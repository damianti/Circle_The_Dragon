#pragma once

#include "macros.h"
#include "Utilities.h"
#include "Dragon.h"
#include "Board.h"
#include "InfoButton.h"
#include "TempState.h"
#include "Info.h"


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
	Board m_board;
	vector<unique_ptr<InfoButton>> m_infoButtons;
	Dragon m_dragon;
	Info m_gameSteps;	
	Info m_level;
	Clock m_clock;

	/* Private Functions */
	void handleClick(const Vector2f location);
	void initWindow();
	void initInfo();
	void dragonNextStep();
	void undo();
	void gameOver();
	void endLevel();
	void reset();
};
