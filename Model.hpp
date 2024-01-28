#ifndef model_hpp
#define model_hpp

#include <assimp/scene.h>

#include "Mesh_3D.hpp"

namespace OGL {
    class Model {
    private:
        std::vector<Mesh_3D> meshes;
        std::string directory;

        void loadModel(
            const std::string& path
        );
        void processNode(
            aiNode* node,
            const aiScene* scene
        );
        Mesh_3D processMesh(
            aiMesh* mesh,
            const aiScene* scene
        );
        std::vector<Texture_2D> loadMaterialTextures(
            aiMaterial* mat,
            aiTextureType type,
            std::string typeName
        );

    public:
        Model(
            const std::string& path
        );

        void Draw(
            Shader& shader,
            Camera& camera,
            glm::mat4& transform
        );

        void Delete();
    };
}

#endif
