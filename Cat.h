#pragma once

#include "Direction.h"
#include "Animation.h"
#include "ResourceManager.h"

class Cat
{
public:
    /* Constructor / Distructor */
    Cat(const sf::Vector2f& CenterPos);

    /* draw */
    void draw(RenderWindow* window);
    /* Accesors */
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    float getFactor() const;
    sf::FloatRect getGlobalBounds() const;

    /* Mutator */
    void setPosition(const sf::Vector2f & pos);
    void setScale(const float scale);
    void setOrigin(const float x, const float y);
    void setSize(const sf::Vector2u size);


    void update(sf::Time delta);

private:
    sf::Sprite m_sprite;
    Direction m_dir = Direction::DownLeft;
    Animation m_animation;
};