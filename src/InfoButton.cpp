#include "InfoButton.h"



InfoButton::InfoButton(const string& str, const Vector2f& loc)
{
    sf::Text text;
    sf::Font* font = ResourceManager::instance().getFont(Type_f::algertxt);

	text.setFont(*font);
	text.setString(str);
	text.setPosition(loc);
	text.setFillColor(Color::Black);
	text.setCharacterSize(characterSize);

    m_text = text;
}


void InfoButton::draw(RenderWindow* window) const
{
    window->draw(m_text);
}

Vector2f InfoButton::getPos() const 
{
	return m_text.getPosition();
}

FloatRect InfoButton::getGlobalBounds() const
{
	return m_text.getGlobalBounds();
}