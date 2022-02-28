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
	Piece(const Piece&);
	Piece(Piece&&);
	~Piece();

	// Obs! && pentru un rvalue( temporara, poate sta doar in dreapta egalului)

	Color GetColor() const;
	Body GetBody() const;
	Shape GetShape() const;
	Height GetHeight() const;

	friend std::ostream& operator<<(std::ostream& out, const Piece& outputPiece);
	Piece& operator=(const Piece&);
	Piece& operator=(Piece&&);
	Piece& operator &= (const Piece& other);

	Piece Intersection(const Piece&) const;
	bool HasAnyFeatureSet() const;

private:
	Body m_body : 2;
	Color m_color : 2;
	Height m_height : 2;
	Shape m_shape : 2;
};

