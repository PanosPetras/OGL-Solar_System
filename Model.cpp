#include "Model.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

using namespace OGL;

void Model::loadModel(
	const std::string& path
) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	size_t lastBackslash = path.find_last_of("\\");
	directory = path.substr(0, lastBackslash + 1);
	processNode(scene->mRootNode, scene);
}

void Model::processNode(
	aiNode* node, 
	const aiScene* scene
) {
	for (unsigned int i = 0; i < node->mNumMeshes; i++) {
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		processNode(node->mChildren[i], scene);
	}
}

Mesh_3D Model::processMesh(
	aiMesh* mesh, 
	const aiScene* scene
) {
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture_2D> textures;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
		Vertex vertex;

		vertex = { 
			.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z),
			.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z),
			.texUV = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y)
		};

		vertices.push_back(vertex);
	}

	for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];

		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	if (mesh->mMaterialIndex >= 0) {
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		std::vector<Texture_2D> diffuseMaps = loadMaterialTextures(
			material,
			aiTextureType_DIFFUSE, "diffuse"
		);
		textures.insert(
			textures.end(), 
			diffuseMaps.begin(), 
			diffuseMaps.end()
		);

		std::vector<Texture_2D> specularMaps = loadMaterialTextures(
			material,
			aiTextureType_SPECULAR, 
			"specular"
		);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	return Mesh_3D(vertices, indices, textures);
}

std::vector<Texture_2D> Model::loadMaterialTextures(
	aiMaterial* mat, 
	aiTextureType type, 
	std::string typeName
) {
	std::vector<Texture_2D> textures;

	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
		aiString str;
		mat->GetTexture(type, i, &str);

		int colorChannels = GL_RGBA;
		if (std::string(str.C_Str()).find("sun") != std::string::npos) colorChannels = GL_RGB;

		Texture_2D texture(directory + str.C_Str(), typeName, i, colorChannels, GL_UNSIGNED_BYTE);
		textures.push_back(texture);
	}
	return textures;
}

Model::Model(
	const std::string& path
) {
	loadModel(path);
}

void Model::Draw(
	Shader& shader,
	Camera& camera,
	glm::mat4& transform
) {
	for(Mesh_3D& mesh : meshes) {
		mesh.Draw(shader, camera, transform);
	}
}

void Model::Delete() {
	for (Mesh_3D& mesh : meshes) {
		mesh.Delete();
	}
}
