#pragma once
class Tile
{
private:
	int minesNearby;
	int tileType;
	int status; //zakryta, odkryta, flaga
public:
	int getMinesNearby();
	void setMinesNearby(int amount);
	int getTileType();
	void setTileType(int isBomb);
	int getStatus();
	void setStatus(int choosenStatus);// 0 - zakryta, 1 - odkryta, 9 - flaga
	Tile();
};
