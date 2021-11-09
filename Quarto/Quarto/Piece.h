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
	// constructor de copiere:
	Piece(const Piece&);
	// constructor de mutare:
	Piece(Piece&&);

	// Obs! && pentru un rvalue( temporara, poate sta doar in dreapta egalului)

	Color GetColor() const;
	Body GetBody() const;
	Shape GetShape() const;
	Height GetHeight() const;

	friend std::ostream& operator<<(std::ostream& out, const Piece& outputPiece);
	Piece& operator=(const Piece&);
	Piece& operator=(Piece&&);

private:
	Color m_color;
	Shape m_shape;
	Body m_body;
	Height m_height;
};

