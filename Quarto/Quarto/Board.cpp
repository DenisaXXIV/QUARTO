#include "Board.h"

std::ostream& operator<<(std::ostream& out, const Board& b)
{
    Board::Position position;
    auto& [line, column] = position;
    for (line = 0; line < Board::kWidth; line++)
    {
        for (column = 0; column < Board::kHeight; column++)
        {
            //Board::Position position = std::make_pair(line, column);
            if (b[position])
            {
                out << *b[position];
            }
            else
            {
                out << "____"<<" ";
            }
        }
        out << std::endl;
    }
    return out;
}

std::optional<Piece>& Board::operator[](const Position& pos)
{
    const auto& [line, column] = pos;
    return m_board[line * kWidth + column];
}

const std::optional<Piece>& Board::operator[](const Position& pos) const
{
    const auto& [line, column] = pos;
    return m_board[line * kWidth + column];
}
