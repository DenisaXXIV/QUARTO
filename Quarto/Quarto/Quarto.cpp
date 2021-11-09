#include <iostream>
#include "Piece.h"
#include "Board.h"
#include "UnusedPiece.h"
int main()
{
	Piece piece1(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull, Piece::Height::eTall);
	Piece piece2(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eTall);
	Board board;
	board[std::make_pair(1, 3)] = piece2;
	std::cout << board << std::endl;
	std::cout << piece1 << " " << piece2;

	UnusedPiece unusedPieces;

	std::cout << '\n';
	std::cout << unusedPieces;
}