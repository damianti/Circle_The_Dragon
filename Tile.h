#pragma once
#include"macros.h"

class Tile
{
public:
	Tile(const Vector2f& pos, const Color& color);
	Tile(CircleShape& circle) : m_circle(circle) {};
//	virtual ~Tile() = 0;
	Vector2f getPos() const { return m_circle.getPosition(); }
    void draw(RenderWindow* window);
	void setBussy();
	bool isBussy() const { return m_isBussy; }
	FloatRect getGlobalBounds() { return m_circle.getGlobalBounds(); }
	void addNeighbour(shared_ptr<Tile>& newNeighbour);
	shared_ptr<Tile>& getRandomFreeNeighbour ();
protected:
	CircleShape m_circle;
	bool m_isBussy = false;
	vector<shared_ptr<Tile>> m_neighbours;
};