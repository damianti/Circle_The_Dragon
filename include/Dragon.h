#pragma once

#include "macros.h"
#include "Utilities.h"
#include "Animation.h"
#include "ResourceManager.h"
#include <cmath>

class Dragon
{
public:
    /* Constructor / Distructor */
    Dragon(const LocIndx& loc);
    ~Dragon() = default;

    /* draw */
    void draw(RenderWindow* window);

    /* Accesors */
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    float getFactor() const;
    sf::FloatRect getGlobalBounds() const;


    LocIndx getLoc() const;
    bool isMoving() const;
    bool isFree() const ;

    /* Mutator */
    void setPosition(const sf::Vector2f & pos);
    void setScale(const float scale);
    void setOrigin(const float x, const float y);
    void setSize(const sf::Vector2u size);
    void setLoc(const LocIndx);
    void update(float deltaTime);
    void undo();
    void reset();

private:
    /* Private Members */
    stack<LocIndx> m_posStack;
    bool m_isMoving;;
    Vector2f m_nextPosition;
    Vector2f m_lastPosition;
    RectangleShape m_dragonBody;
    Animation m_animation;
    bool m_faceRight;
    float m_speed;
    LocIndx m_loc;
};