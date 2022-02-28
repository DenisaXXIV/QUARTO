#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include "Piece.h"

class UnusedPiece
{
public:
	UnusedPiece();

	friend std::ostream& operator<<(std::ostream& out,const UnusedPiece& unusedPieces);
	Piece PickPiece(const std::string& name);

	// Obs!const-ul la final nu permite modificarea obiectului nostru.
	// Obs! const string& name nu permite modificarea name-ului.

	friend std::ostream& operator << (std::ostream& os, const UnusedPiece& unusedPieces);

private:
	void GeneratePieces();
	void InsertPiece(const Piece& newPiece);

private:
	// vector<pair<key,value>> == map<key,value>
	std::unordered_map<std::string, Piece> m_pieces;

	// Obs! Nu folosim unordered_set<value> deoarece vom face cautare:
	//			unordered_set<value>	 ---> Cautare Secventiala
	//			unordered_map<key,value> ---> Cautare Binara
};

