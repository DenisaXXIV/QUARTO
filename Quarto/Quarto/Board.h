#pragma once
#include <array>
#include "Piece.h"
#include <optional>

class Board
{
public:
	using Position = std::pair<uint8_t, uint8_t>;
public:
	Board() = default;
	friend std::ostream& operator<<(std::ostream& out, const Board& b);
	std::optional<Piece>& operator [](const Position& pos); // getter and/or setter
	const std::optional<Piece>& operator [](const Position& pos)const; // only getter

private:
	static const std::size_t kWidth = 4;
	static const std::size_t kHeight = 4;
	static const std::size_t kSize = kWidth * kHeight;
	std::array<std::optional<Piece>, kSize> m_board;


};

