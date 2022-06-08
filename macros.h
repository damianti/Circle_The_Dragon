#pragma once

#include <exception>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <sstream>
#include <optional>
#include <unordered_map>
#include <unordered_set>




//using section
using namespace sf;
using namespace std;

//window data
const unsigned int WindowHeight = 1100;
const unsigned int WindowWidth = 1550;
const auto centerWindow = Vector2f(WindowWidth/2, WindowHeight /2);
const auto BackgroundColor = Color (166,166,166);

//Board data
using LocIndx = pair<int, int>;
const size_t BS = 11;// board Size
const auto startPos = Vector2f(420, 200);
const auto BoardSpace = Vector2f(60, 60);
const auto maxNumOfNeighbours = 6;
const auto firstRow = 0;
const auto firstCol = 0;
const auto lastRow = 10;
const auto lastCol = 10;



//Circle data
const int CircleRadius = 31;
const Color BussyColor = Color (55, 120, 55, 255);
const Color FreeColor = Color (238, 188, 53);
const pair<int, int> dragonStart = { 5, 5 };
const auto defaultHexagon = CircleShape(CircleRadius, 6);


/* textures */
enum class Type_t
{
	dragons, gameWin, gameOver, LevelUp,
};



/* Fonts */
enum class Type_f
{
	algertxt,
};
enum class Type_s
{
	mainTrack,
};


/* Info data*/
enum class Type_B { Undo, Reset, };
const auto infoSteps = sf::Vector2f(800.f, 880);
const auto infoUndo = sf::Vector2f(625.f, 880);
const auto infoReset = sf::Vector2f(450.f, 880);
const auto infoLevel = sf::Vector2f(680, 150);
const auto noSteps = 0;
const auto firstLevel = 1;
const auto maxLevelNum = 3;
const auto characterSize = 40;

/* Animation data*/
const auto maxNumImages = 2;
const auto firstImage = 0;
const auto startTime = 0.0f;


