#include <iostream>
#include "Piece.h"

int main()
{
	Piece piece2(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eTall);
	Piece piece1(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull, Piece::Height::eShort);

	std::cout << piece1 << std::endl << piece2;
}