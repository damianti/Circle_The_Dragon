#pragma once
#include "macros.h"

class Button
{
public:
    /* Constructor / Distructor */
    Button();

    /* Accesors */
    virtual Vector2f getPos() const = 0;
    virtual FloatRect getGlobalBounds() const = 0;

    /* Draw*/
    virtual void draw(RenderWindow* window) const = 0;
};