#include <iostream>

#include "Player.h"
#include "Game.h"

int tests()
{
	Piece piece(Piece::Body::eFull, Piece::Color::eDark, Piece::Height::eShort, Piece::Shape::eSquare);
	std::cout << "Full, Dark, Short, Square piece: " << piece << std::endl;

	Board board;
	std::cout << "Empty board:\n" << board << std::endl;

	board[{0, 0}] = std::move(piece);
	std::cout << "Moved piece to board:\n" << board << std::endl;

	UnusedPiece unusedPieces;
	std::cout << "All available pieces:\n" << unusedPieces << std::endl;
	unusedPieces.PickPiece("0001");
	std::cout << "Extracted \"0001\" remaining pieces after extracted:\n" << unusedPieces << std::endl;

	Player player("Player_1");
	Piece pickedPiece = player.PickPiece(std::cin, unusedPieces);
	std::cout << "Picked piece: " << pickedPiece << std::endl;
	std::cout << "Remaining pieces:\n" << unusedPieces << std::endl;
	const auto& [line, column] = player.PlacePiece(std::cin, std::move(pickedPiece), board);
	std::cout << "Board after placing piece on position ("
		<< static_cast<uint16_t>(line) << "," << static_cast<uint16_t>(column) << "):\n" << board;

	return 0;
}

int main()
{
	Game quartoGame;
	quartoGame.Run();

	return 0;
}