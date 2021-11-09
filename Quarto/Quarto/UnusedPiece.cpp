#include "UnusedPiece.h"

#include <sstream>

UnusedPiece::UnusedPiece()
{
	GeneratePieces();
}

void UnusedPiece::GeneratePieces()
{
	Piece p1(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eHollow, Piece::Height::eTall);
	Piece p2(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eHollow, Piece::Height::eShort);
	Piece p3(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eFull, Piece::Height::eTall);
	Piece p4(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eFull, Piece::Height::eShort);
	Piece p5(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eTall);
	Piece p6(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eShort);
	Piece p7(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	Piece p8(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eShort);
	Piece p9(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	Piece p10(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	
	InsertPiece(p1);
	InsertPiece(p2);
	InsertPiece(p3);

}

void UnusedPiece::InsertPiece(const Piece& newPiece)
{
	std::stringstream pieceString;
	pieceString << newPiece;

	m_pieces.insert(std::make_pair(pieceString.str(), newPiece));
}

std::ostream& operator<<(std::ostream& out, const UnusedPiece& unusedPieces)
{
	for (const auto& [pieceName,piece] : unusedPieces.m_pieces)
	{
		out << pieceName << " ";
	}

	return out;
}
