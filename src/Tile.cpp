#include "Tile.h"

Tile::Tile(const Vector2f& pos, const Color& color)
	: m_isBussy(false)
{
	m_circle = defaultHexagon;
	m_circle.setOrigin(float(m_circle.getTextureRect().height/2), float(m_circle.getTextureRect().width / 2));
	m_circle.setPosition(pos);
	m_circle.setFillColor(color);
}

void Tile::draw(RenderWindow* window) const
{
	window->draw(m_circle);
}

void Tile::setBussy()
{
	m_isBussy = true;
	m_circle.setFillColor(BussyColor);
}

void Tile::setFree()
{
	m_isBussy = false;
	m_circle.setFillColor(FreeColor);
}

bool Tile::isBussy() const 
{ 
	return m_isBussy; 
}

Vector2f Tile::getPos() const 
{
	return m_circle.getPosition();
}

FloatRect Tile::getGlobalBounds() const
{
	return m_circle.getGlobalBounds();
}