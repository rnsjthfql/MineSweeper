#pragma once
class Map1
{
private:
	int** map1 = nullptr;
public:
	Map1();
	~Map1();
	void createMap1(const int& row, const int& col);
	void deleteMap1(const int& row);
	void setMap1(const int& row, const int& col);
	int*& operator[](const int& idx);
};

