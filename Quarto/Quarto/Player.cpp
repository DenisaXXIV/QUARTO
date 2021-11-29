#include "Player.h"

Player::Player(std::string name) : m_name(name)
{
}

Piece Player::PickPiece(UnusedPiece& unusedPieces, std::istream& in)
{
	std::string pieceName;

	in >> pieceName;

	Piece piece = unusedPieces.PickPiece(pieceName);

	return piece;
}

Board::Position Player::PlacePiece(const Piece&& piece, Board& board, std::istream& in)
{
	uint16_t line, column;
	line = UINT16_MAX;
	column = UINT16_MAX;

	if (in >> line && in >> column) {

		Board::Position position = { static_cast<uint8_t>(line),static_cast<uint8_t>(column) };

		auto& optionalPiece = board[position];

		if (optionalPiece) {
			throw "This position is not empty";

		}

		optionalPiece = std::move(piece);

		return position;


	}

	throw "Please enter only 2 number from 0 to 3";
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name;
	return out;
}

