#pragma once

#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <stdexcept>



//using section
using namespace sf;
using namespace std;

//window data
const unsigned int WindowHeight = 1100;
const unsigned int WindowWidth = 1550;

//Board data
const size_t boardSize = 11;
const auto startPos = Vector2f(200, 200);
const auto BoardSpace = Vector2f(60, 60);
const auto maxNumOfNeighbours = 6;


//Circle data
const int CircleRadius = 25;
const Color BussyColor = Color::Magenta;
const Color FreeColor = Color::Green;


enum class Type_t
{
	cat,
};
const int numOfTextures = 1;
const std::string TextureFiles[numOfTextures] = { "cat.png" };


/* Fonts */
enum class Type_f
{
	algertxt,
};
const int numOfFonts = 1;
const std::string FontFiles[numOfFonts] = { "ALGER.TTF" };


const auto infoSteps = sf::Vector2f(580.f, 900.f);