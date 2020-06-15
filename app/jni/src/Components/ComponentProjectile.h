#ifndef COMPONENT_PROJECTILE_H
#define COMPONENT_PROJECTILE_H

#include "../HeaderFiles/Game.h"
#include"../../UtilLib/glm/glm.hpp"



class ComponentProjectile:public Component{
private:

    SDL_Texture* projectileTexture;// 弹丸使用的贴图
    SDL_Rect sourceRect;
    SDL_Rect destRect;

    glm::vec2 emissionOrigin;
    glm::vec2 emissionDir;


public:

    int lifeTime = 0;

    ComponentProjectile(SDL_Texture* texture,glm::vec2 emissionOrigin, glm::vec2 emissionDir,int width,int height) {
        this->emissionOrigin = emissionOrigin;
        this->emissionDir = emissionDir;

        projectileTexture = texture;

        sourceRect.x = 0;
        sourceRect.y = 0;
        sourceRect.w = 4;
        sourceRect.h = 4;

        destRect.x = emissionOrigin.x;
        destRect.y = emissionOrigin.y;
        destRect.w = width;
        destRect.h = height;

    }

    void Initialize()override{



    }

    void Update(float deltaTime) override {
        lifeTime += 1;
        destRect.x += static_cast<int>(emissionDir.x * deltaTime*1000);
        destRect.y += static_cast<int>(emissionDir.y * deltaTime*1000);


    }

    void Render() override{
        TextureManager::DrawTexture(projectileTexture, sourceRect, destRect, SDL_FLIP_NONE);
    }



};



#endif //COMPONENT_PROJECTILE_H
