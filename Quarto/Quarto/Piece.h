#pragma once
#include <iostream>

class Piece
{
public:
	enum class Color: uint8_t
	{
		eNone,
		eDark,
		eWhite
	};

	enum class Shape : uint8_t
	{
		eNone,
		eRound,
		eSquare
	};

	enum class Body : uint8_t
	{
		eNone,
		eFull,
		eHollow
	};

	enum class Height : uint8_t
	{
		eNone,
		eShort,
		eTall
	};

public:
	Piece();
	Piece(Color, Shape, Body, Height);

	Color GetColor() const;
	Body GetBody() const;
	Shape GetShape() const;
	Height GetHeight() const;

	friend std::ostream& operator<<(std::ostream& out, const Piece& outputPiece);

private:
	Color m_color;
	Shape m_shape;
	Body m_body;
	Height m_height;
};

