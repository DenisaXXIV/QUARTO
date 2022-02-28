#pragma once

#include "Board.h"

class StateChecker
{
public:
    enum class State
    {
        None,
        Win,
        Draw
    };

public:
    static State Check(const Board& board, const Board::Position& position);
};

