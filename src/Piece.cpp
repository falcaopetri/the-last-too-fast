/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#include "Piece.h"

tltf::Piece::Piece()
    : Piece(-1)
{
}

tltf::Piece::Piece(int id)
	: _id(id)
{
}

int tltf::Piece::getId() const {
	return _id;
}

bool tltf::Piece::isEqual (const tltf::Piece &other) const {
    return (getId() == other.getId());
}
