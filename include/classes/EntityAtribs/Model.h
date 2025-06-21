#ifndef _MODEL_H_
#define _MODEL_H_
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <IDrawable.h>
#include <Mesh.h>

class Model : public IDrawable
{
    public:
        Model(char *path, bool _gammaCorr = false) : gammaCorrection(_gammaCorr)
        {
            loadModel(path);
        }
        ~Model();
        void draw(Shader &shader) const override;
        void draw() const override;	

        // model data
        std::vector<Texture> texturesLoaded;
        std::vector<Mesh> meshes;
        std::string directory;
        bool gammaCorrection;
    private:
        void loadModel(const std::string& path);
        void loadBHMModel(const std::string & path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        unsigned int textureFromFile(const char *path, const std::string &directory, bool gamma = false);


        //void loadBHMModel(const std::string & path);
        std::string eliminarComentario(const std::string& linea);
};
/*
enum ModelType
{
    LIGHT_MODEL = 0,
    HEAVY_MODEL = 1
};
class Model : IDrawable
{
public:
    std::vector<Texture> texturesLoaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::vector<Mesh>    meshes;
    std::string directory;
    bool gammaCorrection;
    ModelType type;
    void draw() const override;
    void draw(Shader&) const override;
    void loadModel(const std::string& path);
    Model(const std::string& path, bool _gammaCorrection = false) : gammaCorrection(_gammaCorrection)
    {
        //cambiar esto segun la extension
        type = HEAVY_MODEL;
        loadModel(path);
    }
    ~Model(){};

private:
    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    //void loadModel(const std::string& path);
    // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    unsigned int textureFromFile(const char *path, const std::string &directory, bool gamma = false);

};*/

#endif 