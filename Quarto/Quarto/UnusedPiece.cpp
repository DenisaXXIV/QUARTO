#include "UnusedPiece.h"

#include <sstream>

UnusedPiece::UnusedPiece()
{
	GeneratePieces();
}

Piece UnusedPiece::PickPiece(const std::string& name)
{
	auto mapIt = m_pieces.find(name);
	if (mapIt != m_pieces.end())
	{
		auto piece = std::move(mapIt->second);
		m_pieces.erase(mapIt);

		return piece;
	}
	else
	{
		// Aruncam o exceptie:
		throw "Piece not found!";


		// try --> incearca sa faca o anumita bucata de cod
		// catch --> ce se intampla daca am intalnit o eroare
		// throw --> creem o noua eroare

		//Mai modern:

		//auto node = m_pieces.extract(name);

		//if (node)
		//{
		//	return std::move(node.mapped());
		//}
		//else
		//{
		//	throw "Piece not found!";
		//}
	}
}

void UnusedPiece::GeneratePieces()
{
	//Piece p1(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eHollow, Piece::Height::eTall);
	//Piece p2(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eHollow, Piece::Height::eShort);
	//Piece p3(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eFull, Piece::Height::eTall);
	//Piece p4(Piece::Color::eDark, Piece::Shape::eSquare, Piece::Body::eFull, Piece::Height::eShort);
	//Piece p5(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eTall);
	//Piece p6(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eHollow, Piece::Height::eShort);
	//Piece p7(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p8(Piece::Color::eDark, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eShort);
	//Piece p9(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p10(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p11(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p12(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p13(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p14(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p15(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//Piece p16(Piece::Color::eWhite, Piece::Shape::eRound, Piece::Body::eFull , Piece::Height::eTall);
	//
	//InsertPiece(p1);
	//InsertPiece(p2);
	//InsertPiece(p3);

	const uint8_t kPermutationPoolSize = 8;
	std::array<uint8_t, kPermutationPoolSize> permutationPool = { 1, 1, 1, 1, 2, 2, 2, 2 };
	const uint8_t kMaxPermutations = 5;
	const uint8_t kPermutationSize = 4;

	for (uint8_t currentPermutation = 0; currentPermutation < kMaxPermutations; ++currentPermutation)
	{
		auto itPoolBegin = permutationPool.begin() + currentPermutation;
		auto itPoolEnd = permutationPool.begin() + currentPermutation + kPermutationSize;

		do
		{
			EmplacePiece(Piece(
				static_cast<Piece::Body>(*itPoolBegin),
				static_cast<Piece::Color>(*(itPoolBegin + 1)),
				static_cast<Piece::Height>(*(itPoolBegin + 2)),
				static_cast<Piece::Shape>(*(itPoolBegin + 3))
			));
		} while (std::next_permutation(itPoolBegin, itPoolEnd));
	}

}

void UnusedPiece::InsertPiece(const Piece& newPiece)
{
	/*std::stringstream pieceString;
	pieceString << newPiece;

	m_pieces.insert(std::make_pair(pieceString.str(), newPiece));*/

	std::stringstream stringStream;
	stringStream << newPiece;
	m_pool.insert(std::make_pair(stringStream.str(), std::forward<Piece&&>(newPiece)));
}

std::ostream& operator<<(std::ostream& out, const UnusedPiece& unusedPieces)
{
	// in mod normal: 
	// for(cont auto& it : unusedPieces.m_pieces)
	// {
	//		out<<it.pieceName<<" ";
	// }

	// pentru pair:
	for (const auto&[pieceName,piece] : unusedPieces.m_pieces)
	{
		out << pieceName << " ";
	}

	//Obs! referinta ( & ) pentru a nu copia pair-ul
	//Obs! const pentru ca pair-ul nu se modifica

	return out;
}
