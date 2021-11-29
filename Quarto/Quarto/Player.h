#pragma once

#include<string>

#include "UnusedPiece.h"
#include "Piece.h"
#include "Board.h"

class Player
{
public:
	Player(std::string name);

	friend std::ostream& operator<<(std::ostream& out, const Player&);

	Piece PickPiece(UnusedPiece&, std::istream&);
	Board::Position PlacePiece(const Piece&& piece, Board& board, std::istream& in);//dublu referinta pentru ca mutam
	//obiectul - la piece 

private:
	std::string m_name;

};

