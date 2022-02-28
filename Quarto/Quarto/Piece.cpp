#include "Piece.h"

Piece::Piece() :
	m_shape(Piece::Shape::eNone),
	m_body(Piece::Body::eNone),
	m_height(Piece::Height::eNone),
	m_color(Piece::Color::eNone)
{
}

Piece::Piece(Color color, Shape shape, Body body, Height height) :
	m_shape(shape),
	m_body(body),
	m_height(height),
	m_color(color)

{
}

Piece::Piece(const Piece& ourPiece)
{
	*this = ourPiece;
}

Piece::Piece(Piece&& piece)
{
	*this = std::move(piece);
}

Piece::~Piece()
{
	m_body = Body::eNone;
	m_color = Color::eNone;
	m_height = Height::eNone;
	m_shape = Shape::eNone;
}

Piece::Color Piece::GetColor() const
{
	return m_color;
}

Piece::Body Piece::GetBody() const
{
	return m_body;
}

Piece::Shape Piece::GetShape() const
{
	return m_shape;
}

Piece::Height Piece::GetHeight() const
{
	return m_height;
}

Piece& Piece::operator=(const Piece& other)
{
	this->m_body = other.m_body;
	this->m_color = other.m_color;
	this->m_height = other.m_height;
	this->m_shape = other.m_shape;

	return *this;
}

Piece& Piece::operator=(Piece&& other)
{
	this->m_body = other.m_body;
	this->m_color = other.m_color;
	this->m_height = other.m_height;
	this->m_shape = other.m_shape;

	new(&other) Piece;

	return *this;
}

Piece Piece::Intersection(const Piece& other) const
{
	Piece piece = *this;

	if (piece.m_body != other.m_body)
		piece.m_body = Body::eNone;

	if (piece.m_color != other.m_color)
		piece.m_color = Color::eNone;

	if (piece.m_height != other.m_height)
		piece.m_height = Height::eNone;

	if (piece.m_shape != other.m_shape)
		piece.m_shape = Shape::eNone;

	return piece;
}

bool Piece::HasAnyFeatureSet() const
{
	return
		GetBody() != Piece::Body::eNone ||
		GetColor() != Piece::Color::eNone ||
		GetHeight() != Piece::Height::eNone ||
		GetShape() != Piece::Shape::eNone;
}

std::ostream& operator<<(std::ostream& out, const Piece& outputPiece)
{
	return out <<
		static_cast<int>(outputPiece.m_body) - 1 <<
		static_cast<int>(outputPiece.m_color) - 1 <<
		static_cast<int>(outputPiece.m_height) - 1 <<
		static_cast<int>(outputPiece.m_shape) - 1;
}
