#pragma once

#include "Tile.h"
#include "Cat.h"

class Controller
{
public:
	/*constructor Distructor */
	Controller();
	~Controller();


	/* Window Functions */
	void update();
	void render();
	void pollEvents();
	void run();

private:
	/* Window members */
	RenderWindow* m_window = nullptr;
	VideoMode m_videoMode;
	Event m_event;
	Music m_music;

	/* Game members */
	using Board = vector<vector<shared_ptr<Tile>>>;
	Board m_board;
	Cat m_cat;
	sf::Clock m_clock;
	int m_gameSteps = 0;	
	


	void handleClick(const Vector2f location);
	/* Private Functions */
	void updateStates();

	void initWindow();
	void initBoard();
	void connectTiles();
	void catNextStep();
	void connectOneTile(const int row, const int col, const int OddOrEven);
	bool isInsideBoard(const int row, const int col);
	Vector2f setTilePosition(const size_t row, const size_t col);
	sf::Text getStepsText();
};
