#include "Control.h"
#include <iomanip>

Control::Control()
{
}

Control::~Control()
{
}

void Control::setRow()
{
	cout << "===========================" << endl;
	cout << "★★★ map 크기설정 ★★★" << endl;
	cout << "---------------------------" << endl;
	int r;
	cout << "map 행크기 입력: ";
	cin >> r;
	this->m_row = r;
}

void Control::setCol()
{
	int c;
	cout << "map 열크기 입력: ";
	cin >> c;
	this->m_col = c;
	cout << "===========================" << endl;
}

void Control::setLevel()
{
	cout << "---------------------------" << endl;
	int l;
	cout << "난이도 선택(1.하 2.중 3.상): ";
	cin >> l;
	this->level = l;
	cout << "---------------------------" << endl;
}

int Control::getRow()
{
	return m_row;
}

int Control::getCol()
{
	return m_col;
}

int Control::getLevel()
{
	return level;
}

int Control::getCount()
{
	if (level == 1) {
		count = (int)m_row * m_col * 0.1;
	}
	else if (level == 2) {
		count = (int)m_row * m_col * 0.2;
	}
	else if (level == 3) {
		count = (int)m_row * m_col * 0.3;
	}
	return count;
}

void Control::showMenu()
{
	int m;
	cout << "====================================" << endl;
	cout << "----------★★★메뉴★★★----------" << endl;
	cout << "1.칸열기 2.지뢰표시 3.지뢰표시취소" << endl;
	cout << "====================================" << endl;
	while (1) {
		cout << "메뉴선택: ";
		cin >> m;
		if (m >= 1 && m <= 3)
			break;
		else
			cout << "메뉴를 다시선택하세요." << endl;
	}
	this->mn = m;
}


void Control::setMenu(Map1& map1)
{
	cout << "------------------------------------" << endl;
	if (mn == 1) {
		if (map1[x][y] == 2) {
			cout << "지뢰표시를 취소하고 칸을 열세요." << endl;
		}
		else if (map1[x][y] == 1)
			cout << "이미 열려있는 칸입니다." << endl;
		else {
			map1[x][y] = 1;  //칸열기
			cout << "칸을 엽니다." << endl;
		}
	}
	else if (mn == 2) {
		if (map1[x][y] == 1) {
			cout << "열려있는 칸으로 지뢰를 표시할 수 없습니다." << endl;
		}
		else if (map1[x][y] == 2)
			cout << "지뢰표시가 돼있는 칸입니다." << endl;
		else {
			if (mc == getCount()) {
				cout << "표시가능한 횟수를 초과했습니다." << endl;
			}
			else {
				map1[x][y] = 2;  //지뢰표시
				cout << "지뢰를 표시합니다." << endl;
				mc++;
			}
		}
	}
	else if (mn == 3) {
		if (map1[x][y] == 1) {
			cout << "열려있는 칸입니다." << endl;
		}
		else if (map1[x][y] == 0)
			cout << "지뢰표시가 안돼있는 칸입니다." << endl;
		else {
			map1[x][y] = 0;  //지뢰표시취소
			cout << "지뢰표시를 취소합니다." << endl;
			mc--;
		}
	}
	cout << "====================================" << endl;
}

int Control::getMenu()
{
	return mn;
}

void Control::setx()
{
	int x1;
	cout << "------------------------------------" << endl;
	cout << "칸을 선택하세요" << endl;
	while (1) {
		cout << "행: ";
		cin >> x1;
		if (x1 > m_row || x1 <= 0) {
			cout << "행을 다시 입력하세요." << endl;
		}
		else
			break;
	}
	this->x = x1 - 1;
}

void Control::sety()
{
	int y1;
	while (1) {
		cout << "열: ";
		cin >> y1;
		if (y1 > m_col || y1 <= 0) {
			cout << "열을 다시 입력하세요." << endl;
		}
		else
			break;
	}
	this->y = y1 - 1;
}

int Control::getx()
{
	return x;
}

int Control::gety()
{
	return y;
}

void Control::setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1,visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void Control::gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Control::setColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}

void Control::showMap(Map& map, Map1& map1)
{
	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			if (map1[i][j] == 0)
				cout << right << setw(5) << "●";
			else if (map1[i][j] == 1 && map[i][j] != 9)
				cout << right << setw(4) << map[i][j];
			else if (map1[i][j] == 2)
				cout << right << setw(5) << "◈";
		}
		cout << endl;
	}
	cout << "지뢰개수: " << getCount() << endl;
	cout << "표시가능한 지뢰개수: " << getCount() - mc << endl;
}

void Control::showWin()
{
	cout << "================================" << endl;
	cout << "★    ★★    ★  ★  ★★   ★" << endl;
	cout << " ★  ★  ★  ★   ★  ★ ★  ★" << endl;
	cout << "  ★★    ★★    ★  ★  ★ ★" << endl;
	cout << "   ★      ★     ★  ★   ★★" << endl;
	cout << "================================" << endl;
}

void Control::showLose(Map& map, Map1& map1)
{
	cout << "====================================" << endl;
	cout << "지뢰를 밟았습니다!!!" << endl;
	cout << "------------------------------------" << endl;
	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			if (map[i][j] == 9 && map1[i][j] == 1)  //지뢰밟은칸
				cout << right << setw(5) << "★";
			else if (map[i][j] == 9)
				cout << right << setw(5) << "☆";
			else
				cout << right << setw(4) << map[i][j];
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "이전 입력 칸: " << getx() + 1 << "행," << gety() + 1 << "열" << endl;
	cout << "====================================" << endl;
}

bool Control::result(Map& map, Map1& map1)
{
	int a = 0;
	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			if (map1[i][j] == 1 && map[i][j] != 9)
				a++;
			if (map1[i][j] == 1 && map[i][j] == 9)
				return false;
		}
	}
	if (a == getRow() * getCol() - getCount())
		return true;
}




