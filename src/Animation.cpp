#include "Animation.h"




Animation::Animation(Type_t textureType, Vector2u imageCount, float switchTime)
: m_imageCount(imageCount), m_switchTime (switchTime), m_totalTime(startTime)
{
    sf::Texture* texture = ResourceManager::instance().getTexture(textureType);
    m_uvRect.width = texture->getSize().x / int (imageCount.x);
    m_uvRect.height = texture->getSize().y / int (imageCount.y);

}


void Animation::update (bool faceRight, float deltaTime,bool isMooving)
{
    m_totalTime += deltaTime;

    //switch image of animation when the dragon moves
    if (m_totalTime >= m_switchTime)
    {
        m_totalTime -= m_switchTime;
        m_currentImage.x++;
        if (m_currentImage.x > maxNumImages || !isMooving) m_currentImage.x = firstImage;
    }

    m_uvRect.left = m_currentImage.x * m_uvRect.width;
    
    if (faceRight)
    {
        m_uvRect.left = (m_currentImage.x + 1) * abs(m_uvRect.width);
        m_uvRect.width = -abs(m_uvRect.width);
    }
    else
    {
        m_uvRect.left = m_currentImage.x * m_uvRect.width;
        m_uvRect.width = abs(m_uvRect.width);
    }
    
}

IntRect Animation::getUvRect() const
{
    return m_uvRect;
}
