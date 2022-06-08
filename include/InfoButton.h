#pragma once

#include "Button.h"
#include "ResourceManager.h"


class InfoButton: public Button
{
public:
    /* Constructor / Distructors*/

    InfoButton(const string& str, const Vector2f& loc);
    /* Draw */
    void draw(RenderWindow* window) const override;

    /* Accesors */
    Vector2f getPos() const override;
	FloatRect getGlobalBounds() const override;

private:
    /* Private Members*/
    sf::Text m_text;
};