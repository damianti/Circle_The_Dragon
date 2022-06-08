#include "Info.h"

Info::Info(const string& str, const Vector2f& loc, const unsigned int data)
	:m_str(str), m_data(data)
{
	sf::Text text;
	sf::Font* font = ResourceManager::instance().getFont(Type_f::algertxt);
	text.setFont(*font);
	text.setPosition(loc);
	text.setFillColor(Color::Black);
	text.setCharacterSize(characterSize);
	m_text = text;
	setSentence();
}

void Info::setSentence()
{
	std::string sentence;
	std::stringstream sstm;
	sstm << m_str << m_data;
	sentence = sstm.str();
	m_text.setString(sentence);
}

void Info::setData(const int data)
{
	m_data = data;
	setSentence();
}

void Info::draw(RenderWindow* window) const
{
	window->draw(m_text);
}

int Info::getData() const
{
	return m_data;
}

Vector2f Info::getPos() const
{
	return m_text.getPosition();
}

void Info::operator++()
{
	m_data++;
	setSentence();
}

void Info::operator--()
{
	if(m_data > 0)
		m_data--;
	setSentence();
}