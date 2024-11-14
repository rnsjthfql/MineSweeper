#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

int Map::mineCount()
{
	return count;
}

void Map::createMap(const int& row, const int& col)
{
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
	}
}

void Map::deleteMap(const int& row)
{
	if (map != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] map[i];
		}
		delete[] map;
	}
	map = nullptr;
}


void Map::setMap(const int& row, const int& col)
{
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			map[i][j] = 0;
		}
	}
}

void Map::setMine(const int& row, const int& col, const int& level)
{
	int x, y;
	srand((unsigned)time(NULL));
	if (level == 1) {
		count = (int)row * col * 0.1;
		for (int i = 0; i < count; i++) {
			x = rand() % row;
			y = rand() % col;
			map[x][y] = 9;
		}
	}
	else if (level == 2) {
		count = (int)row * col * 0.2;
		for (int i = 0; i < count; i++) {
			x = rand() % row;
			y = rand() % col;
			map[x][y] = 9;
		}
	}
	else if (level == 3) {
		count = (int)row * col * 0.3;
		for (int i = 0; i < count; i++) {
			x = rand() % row;
			y = rand() % col;
			map[x][y] = 9;
		}
	}
}

void Map::MapCount(const int& row, const int& col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != 9) {
				int mc = 0; //ÇØ´çÄ­ÁÖº¯ Áö·Ú°³¼ö
				if (i - 1 != -1 && map[i - 1][j] == 9)	mc++;
				if (i + 1 != row && map[i + 1][j] == 9)	mc++;
				if (j - 1 != -1 && map[i][j - 1] == 9)	mc++;
				if (j + 1 != col && map[i][j + 1] == 9)	mc++;
				map[i][j] = mc;
			}
		}
	}
}


int*& Map::operator[](const int& idx)
{
	return map[idx];
}





