#ifndef gl_model_hpp
#define gl_model_hpp

#include <assimp/scene.h>

#include "GL_Mesh.hpp"

class GL_Model {
private:
    std::vector<GL_Mesh> meshes;
    std::string directory;

    void loadModel(
        const std::string& path
    );
    void processNode(
        aiNode* node, 
        const aiScene* scene
    );
    GL_Mesh processMesh(
        aiMesh* mesh, 
        const aiScene* scene
    );
    std::vector<GL_Texture_2Ds> loadMaterialTextures(
        aiMaterial* mat, 
        aiTextureType type,
        std::string typeName
    );

public:
    GL_Model(
        const std::string& path
    );

    void Draw(
        GL_Shader& shader,
        GL_Camera& camera,
        glm::mat4& transform
    );

    void Delete();
};
#endif
