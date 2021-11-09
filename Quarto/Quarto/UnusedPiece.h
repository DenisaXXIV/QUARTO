#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include "Piece.h"

class UnusedPiece
{
public:
	UnusedPiece();
	friend std::ostream& operator<<(std::ostream& out,const UnusedPiece& unusedPieces);

private:
	void GeneratePieces();
	void InsertPiece(const Piece& newPiece);

private:
	std::unordered_map<std::string, Piece> m_pieces;
};

