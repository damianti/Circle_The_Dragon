#pragma once 
#include"macros.h"
#include"ResourceManager.h"

class Info
{
public:
	/* Constructor */
	Info(const string& str, const Vector2f& loc, const unsigned int data);

	/* Draw */
	void draw(RenderWindow* window) const;

	/* Accesors */
	Vector2f getPos() const;
	int getData() const;

	/* Operators */
	void operator++();
	void operator--();

	/* Mutators */
	void setData(const int data);
private:
	/* Private Members */
	sf::Text m_text;
	unsigned int m_data;
	string m_str;

	/* Private Functions */
	void setSentence();
};