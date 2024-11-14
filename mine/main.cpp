#include <iostream>
#include <Windows.h>
#include "MineSweeper.h"
using namespace std;

int Map::count = 0;

namespace ksb {
	void printName() {
		cout << "학번:201714159 이름:권솔비" << endl;
	}
}

int main() {
	ksb::printName();

	MineSweeper mine;
	Map map;
	Map1 map1;
	Control ct;
	ct.setColor(10, 0);
	ct.gotoxy(0, 10);
	ct.setCursorView(0);

	mine.play();
	system("pause");
	system("cls");

	ct.setColor(9, 15);
	ct.setRow();
	ct.setCol();
	ct.setLevel();
	map.createMap(ct.getRow(), ct.getCol());
	map1.createMap1(ct.getRow(), ct.getCol());
	map.setMap(ct.getRow(), ct.getCol());
	map1.setMap1(ct.getRow(), ct.getCol());
	map.setMine(ct.getRow(), ct.getCol(), ct.getLevel());
	map.MapCount(ct.getRow(), ct.getCol());
	ct.showMap(map, map1);
	system("pause");

	while (1) {
		system("cls");
		ct.showMap(map, map1);
		ct.showMenu();
		ct.setx();
		ct.sety();
		ct.setMenu(map1);
		system("pause");
		//Sleep(500);
		if (ct.result(map, map1) == true) {
			system("cls");
			ct.showWin();
			break;
		}
		else if (ct.result(map, map1) == false) {
			system("cls");
			ct.showLose(map, map1);
			break;
		}
		//ct.showMap(map, map1);
	}

	map.deleteMap(ct.getRow());
	map1.deleteMap1(ct.getRow());

}