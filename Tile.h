#pragma once
#include"macros.h"
#include "Button.h"

class Tile: public Button
{ 
public:
	/* Constructor / Distructor */
	Tile(const Vector2f& pos, const Color& color);
	Tile(CircleShape& circle) : m_circle(circle), m_isBussy(false) {};

	/* Accesors*/
	Vector2f getPos() const override;
	FloatRect getGlobalBounds() const override;
	bool isBussy() const;
	/* Draw */
    void draw(RenderWindow* window) const override;

	/* Mutators */
	void setBussy();
	void setFree();

private:
	/* Private Members*/
	CircleShape m_circle;
	bool m_isBussy;
};