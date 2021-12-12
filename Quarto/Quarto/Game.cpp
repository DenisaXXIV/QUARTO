#include "Game.h"
#include "Board.h"
#include "UnusedPiece.h"
#include "Player.h"

void Game::Run()
{
	Board board;
	UnusedPiece pieces;

	std::string playerName;

	std::cout << "First player name" << std::endl;

	std::cin >> playerName;
	Player player1(playerName);

	std::cout << "Second player name" << std::endl;

	std::cin >> playerName;
	Player player2(playerName);
	//aceste doua variabile retin cate un pointer catre cei doi playeri
	std::reference_wrapper<Player> pickingPlayer = player1;
	std::reference_wrapper<Player> placingPlayer = player2;

	while (true) {

		system("CLS");

		std::cout << "The board look like this" << std::endl;
		std::cout << board << std::endl;

		std::cout << "The unused pieces are the following" << std::endl;
		std::cout << pieces << std::endl;

		std::cout << pickingPlayer << "has to choose a piece" << std::endl;

		Piece pickedPiece;

		//pana cand utilizatorul introduce o valoare buna
		while (true) {

			try
			{
				pickedPiece = pickingPlayer.get().PickPiece(pieces, std::cin);
				break;//playerul a introdus o valoare ok
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}

		}

		std::cout << placingPlayer << "has to place a piece" << std::endl;

		Board::Position position;

		while (true) {
			try {
				position = placingPlayer.get().PlacePiece(std::move(pickedPiece), board, std::cin);
				break;
			}
			catch (const char* errorMessage) {
				std::cout << errorMessage << std::endl;
			}
		}

		std::swap(pickingPlayer, placingPlayer);
	}



}
