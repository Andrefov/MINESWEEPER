#include "tile.h"

int tile::getMinesNearby()
{
	return minesNearby;
}

int tile::setMinesNearby(int amount)
{
	minesNearby = amount;
	return minesNearby;
}

int tile::getTileType()
{
	return tileType;
}

int tile::setTileType(int isBomb)
{
	tileType = isBomb;
	return tileType;
}

int tile::getStatus()
{
	return status;
}

int tile::setStatus(int choosenStatus)
{
	status = choosenStatus;
	return status;
}

