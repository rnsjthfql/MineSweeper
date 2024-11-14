#pragma once
#include <Windows.h>
#include "Map.h"
#include "Map1.h"
class Control
{
private:
	int m_row;
	int m_col;
	int level;
	int count;  //���ڰ���
	int mn; //�޴�
	int x;
	int y;
	int mc = 0; //���� ���ڰ���
public:
	Control();
	~Control();
	void setRow();
	void setCol();
	void setLevel();
	int getRow();
	int getCol();
	int getLevel();
	int getCount();
	void showMenu();
	void setMenu(Map1& map1);
	int getMenu();
	void setx();
	void sety();
	int getx();
	int gety();
	void showMap(Map& map, Map1& map1);
	void showWin();
	void showLose(Map& map, Map1& map1);
	bool result(Map& map, Map1& map1);
	void setCursorView(bool visible);
	void gotoxy(int x, int y);
	void setColor(int color, int bgcolor);
};
