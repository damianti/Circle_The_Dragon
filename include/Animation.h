#pragma once

#include "macros.h"
#include "ResourceManager.h"


class Animation
{
public:
    /* Constructor / Distructor*/
    Animation(Type_t texture, Vector2u imageCount, float switchTime);
    ~Animation() = default;

    /* Mutator */
    void update(bool faceRight, float deltaTime, bool isMooving);

    /* Accesors */
    IntRect getUvRect() const;
private:
    /* Private Members*/
    IntRect m_uvRect;
    Vector2u m_imageCount;
    Vector2u m_currentImage;
    float m_totalTime;
    float m_switchTime;
};