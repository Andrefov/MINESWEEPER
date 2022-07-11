#include "tile.h"

int tile::getMinesNearby()
{
	return minesNearby;
}

void tile::setMinesNearby(int amount)
{
	minesNearby = amount;
}

int tile::getTileType()
{
	return tileType;
}

void tile::setTileType(int isBomb)
{
	tileType = isBomb;

}

int tile::getStatus()
{
	return status;
}

void tile::setStatus(int choosenStatus)
{
	status = choosenStatus;
}

