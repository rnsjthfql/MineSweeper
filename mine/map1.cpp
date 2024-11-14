#include "Map1.h"
#include <stddef.h>

Map1::Map1()
{
}

Map1::~Map1()
{
}

void Map1::createMap1(const int& row, const int& col)
{
	map1 = new int* [row];
	for (int i = 0; i < row; i++) {
		map1[i] = new int[col];
	}
}

void Map1::deleteMap1(const int& row)
{
	if (map1 != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] map1[i];
		}
		delete[] map1;
	}
	map1 = nullptr;
}

void Map1::setMap1(const int& row, const int& col)
{
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			map1[i][j] = 0;
		}
	}
}

int*& Map1::operator[](const int& idx)
{
	return map1[idx];
}