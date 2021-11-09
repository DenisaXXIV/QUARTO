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

Piece& Piece::operator=(const Piece& piece)
{
	this->m_body = piece.m_body;
	this->m_color = piece.m_color;
	this->m_height = piece.m_height;
	this->m_shape = piece.m_shape;

	return *this;
}

Piece& Piece::operator=(Piece&& piece)
{
	this->m_body = piece.m_body;
	this->m_color = piece.m_color;
	this->m_height = piece.m_height;
	this->m_shape = piece.m_shape;

	new(&piece) Piece;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Piece& outputPiece)
{
	return out << static_cast<int>(outputPiece.m_color)<< static_cast<int>(outputPiece.m_body)
		<< static_cast<int>(outputPiece.m_shape)<< static_cast<int>(outputPiece.m_height);
}
