#include "Dragon.h"

Dragon::Dragon(const LocIndx& loc)
	:m_loc(loc), m_animation(Type_t::dragons, Vector2u(3, 1), 0.06f), m_speed(150.f), m_isMoving(false), m_faceRight(true)
{
	m_dragonBody.setSize(Vector2f(50.f, 50.f));
	m_dragonBody.setOrigin(float(m_dragonBody.getTextureRect().height) / 2, float(m_dragonBody.getTextureRect().width) / 2);
	m_dragonBody.setPosition(setTilePosition(loc));
	m_dragonBody.setTexture(ResourceManager::instance().getTexture(Type_t::dragons));
}


/* Accesors */
sf::FloatRect Dragon::getGlobalBounds() const
{
	return m_dragonBody.getGlobalBounds();
}

sf::Vector2f Dragon::getPosition() const
{
	return m_dragonBody.getPosition();
}

sf::Vector2f Dragon::getSize() const
{
	return sf::Vector2f(float(m_dragonBody.getTextureRect().width), float(m_dragonBody.getTextureRect().height));
}

float Dragon::getFactor() const
{
	return m_dragonBody.getScale().x;
}

/* Mutator */
void Dragon::setPosition(const sf::Vector2f& pos)
{
	m_nextPosition = pos;
	m_isMoving = true;
}

void Dragon::setSize(const sf::Vector2u size)
{
	m_dragonBody.scale((size.x / m_dragonBody.getGlobalBounds().width), (size.y / m_dragonBody.getGlobalBounds().height));
}

void Dragon::setLoc(const LocIndx loc)
{
	m_lastPosition = setTilePosition(m_loc);
	m_posStack.push(m_loc);
	m_loc = loc;
	setPosition(setTilePosition(m_loc));
}


void Dragon::undo()
{
	if (!m_posStack.empty())
	{
		m_lastPosition = setTilePosition(m_loc);
		auto& lastPos = m_posStack.top();
		m_posStack.pop();
		m_loc = lastPos;

		setPosition(setTilePosition(m_loc));
	}
}

void Dragon::reset()
{
	m_posStack = stack<LocIndx>();
	setLoc(dragonStart);
}

void Dragon::update(float deltaTime)
{
	auto movement =  Vector2f(0.0f, 0.0f);

	if (isMoving())
	{
		movement.x += ((m_nextPosition.x - m_lastPosition.x) * deltaTime * m_speed )/ BoardSpace.x;
		movement.y += ((m_nextPosition.y - m_lastPosition.y) * deltaTime * m_speed) / BoardSpace.y;
	}
	
	if (distance(m_nextPosition, m_dragonBody.getPosition())< 1.f)
		m_isMoving = false;
	else if (movement.x > 0.0f)
		m_faceRight = false;
	else 
		m_faceRight = true;


	m_animation.update(m_faceRight, deltaTime, m_isMoving);
	m_dragonBody.setTextureRect(m_animation.getUvRect());
	m_dragonBody.move(movement);

}


bool Dragon::isMoving() const
{
	return m_isMoving;
}

bool Dragon::isFree() const 
{
	return (getLoc().first == firstCol
		|| getLoc().second == firstRow
		|| getLoc().first == lastCol
		|| getLoc().second == lastRow);
}

void Dragon::setOrigin(const float x, const float y)
{
	m_dragonBody.setOrigin(x, y);
}

void Dragon::setScale(const float scale)
{
	m_dragonBody.setScale(sf::Vector2f(scale, scale));
}

/* Draw */
void Dragon::draw(RenderWindow* window)
{
	window->draw(m_dragonBody);
}


LocIndx Dragon::getLoc() const
{
	 return m_loc; 
}

