#pragma once
class tile
{
private:
	int minesNearby;
	int tileType;
	int status; //zakryta, odkryta, flaga
public:
	int getMinesNearby();
	int setMinesNearby(int amount);
	int getTileType();
	int setTileType(int isBomb);
	int getStatus();
	int setStatus(int s);// 0 - zakryta, 1 - odkryta, 9 - flaga
};
