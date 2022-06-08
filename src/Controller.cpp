#include "Controller.h"

/* Constructors / Distructors */
Controller::Controller()
	:m_dragon(Dragon(dragonStart)), m_gameSteps("Steps done: ", infoSteps, noSteps), m_level("Level: ", infoLevel, firstLevel)
{
	
	initInfo();
	initWindow();
	ResourceManager::instance().playSong();
}

Controller::~Controller()
{	
	if (m_window)
		delete m_window;
}

/* Private Functions */
void Controller::initInfo()
{
	m_infoButtons.push_back(make_unique <InfoButton>("Undo", infoUndo));
	m_infoButtons.push_back(make_unique <InfoButton>("Reset", infoReset));
}

void Controller::initWindow()
{
	m_videoMode.width = WindowWidth;
	m_videoMode.height = WindowHeight;
	m_window = new sf::RenderWindow(m_videoMode, "Circle The Dragon", sf::Style::Default |sf::Style::Titlebar | sf::Style::Close);
}

/* Window Functions */
void Controller::run()
{
	while (m_window->isOpen())
	{
		// Update
		update();

		// Render
		render();
	}
}

void Controller::update()
{	
	m_dragon.update(m_clock.getElapsedTime().asSeconds());
	pollEvents();
	m_clock.restart();
}

void Controller::pollEvents()
{
	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed: m_window->close(); break;
		case sf::Event::MouseButtonReleased:
		{
			auto location = m_window->mapPixelToCoords({ m_event.mouseButton.x, m_event.mouseButton.y });
			if(!m_dragon.isMoving())
				handleClick(location);
			break;
		}
		default: break;
		}
	}
}

void Controller::handleClick(const Vector2f location)
{
	if (m_infoButtons[(int)Type_B::Reset]->getGlobalBounds().contains(location))
		reset();
	else if (m_infoButtons[(int)Type_B::Undo]->getGlobalBounds().contains(location))
		undo();
	else if (!m_dragon.getGlobalBounds().contains(location) && m_board.isTileClicked(location))
		dragonNextStep();
}

void Controller::render()
{
	m_window->clear(BackgroundColor);

	/* Draw State */
	m_board.draw(m_window);
	m_dragon.draw(m_window);
	m_gameSteps.draw(m_window);
	m_level.draw(m_window);
	for (auto& button : m_infoButtons)
		button->draw(m_window);

	m_window->display();
}

void Controller::undo()
{
	m_board.undo();
	m_dragon.undo();
	--m_gameSteps;
}


void Controller::dragonNextStep()
{
	++m_gameSteps;
	if (m_dragon.isFree())
		gameOver();

	else if (auto dest = m_board.BFS(m_dragon.getLoc())) //BFS returns std::optional. If Dragon doesnt have where to move -> returns void
		m_dragon.setLoc(*dest);
	else	//end level player win
		endLevel();
}

void Controller::reset()
{
	m_dragon = Dragon(dragonStart);
	m_gameSteps.setData(noSteps);
	m_board.resetLevel();
}

void Controller::gameOver()
{
	TempState(Type_t::gameOver, m_window);
	reset();
}


void Controller::endLevel()
{
	if (m_level.getData() < maxLevelNum)
	{
		TempState(Type_t::LevelUp, m_window);
		++m_level;
		m_board.initLevel(m_level.getData());
		reset();
	}
	else
	{
		TempState(Type_t::gameWin, m_window);
		m_window->close();
	}
}







