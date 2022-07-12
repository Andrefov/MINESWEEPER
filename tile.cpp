#include "tile.h"

int Tile::getMinesNearby()
{
	return minesNearby;
}

void Tile::setMinesNearby(int amount)
{
	minesNearby = amount;
}

int Tile::getTileType()
{
	return tileType;
}

void Tile::setTileType(int isBomb)
{
	tileType = isBomb;

}

int Tile::getStatus()
{
	return status;
}

void Tile::setStatus(int choosenStatus)
{
	status = choosenStatus;
}

Tile::Tile() :
	tileType(0),
	minesNearby(0),
	status(0)
{};
