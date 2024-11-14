#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Map
{
private:
	int** map = nullptr;   //Áö·Ú¼ö Ç¥½Ã
	static int count; //Áö·Ú°³¼ö
public:
	Map();
	~Map();
	int mineCount();
	void createMap(const int& row, const int& col);
	void deleteMap(const int& row);
	void setMap(const int& row, const int& col);
	void setMine(const int& row, const int& col, const int& level);
	void MapCount(const int& row, const int& col);
	int*& operator[](const int& idx);
};

