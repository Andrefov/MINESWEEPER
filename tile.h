#pragma once

class Tile
{
private:
	int minesNearby;
	int tileType;// 0 - nie ma bomby, 1 - jest
	int status; //zakryta, odkryta, flaga lub iloœæ min
public:
	int getMinesNearby();
	void setMinesNearby(int amount);
	int getTileType();
	void setTileType(int isBomb);
	int getStatus();
	void setStatus(int choosenStatus);// 0 - zakryta, 1 - odkryta, 9 - flaga
	Tile();
};
