#pragma once

#include "macros.h"


enum class Direction
{
    UpRight,
    UpLeft,
    DownRight,
    DownLeft,
    Right,
    Left,
};

sf::Vector2f toVector(Direction dir);