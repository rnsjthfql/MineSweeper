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
	cout << "�ڡڡ� map ũ�⼳�� �ڡڡ�" << endl;
	cout << "---------------------------" << endl;
	int r;
	cout << "map ��ũ�� �Է�: ";
	cin >> r;
	this->m_row = r;
}

void Control::setCol()
{
	int c;
	cout << "map ��ũ�� �Է�: ";
	cin >> c;
	this->m_col = c;
	cout << "===========================" << endl;
}

void Control::setLevel()
{
	cout << "---------------------------" << endl;
	int l;
	cout << "���̵� ����(1.�� 2.�� 3.��): ";
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
	cout << "----------�ڡڡڸ޴��ڡڡ�----------" << endl;
	cout << "1.ĭ���� 2.����ǥ�� 3.����ǥ�����" << endl;
	cout << "====================================" << endl;
	while (1) {
		cout << "�޴�����: ";
		cin >> m;
		if (m >= 1 && m <= 3)
			break;
		else
			cout << "�޴��� �ٽü����ϼ���." << endl;
	}
	this->mn = m;
}


void Control::setMenu(Map1& map1)
{
	cout << "------------------------------------" << endl;
	if (mn == 1) {
		if (map1[x][y] == 2) {
			cout << "����ǥ�ø� ����ϰ� ĭ�� ������." << endl;
		}
		else if (map1[x][y] == 1)
			cout << "�̹� �����ִ� ĭ�Դϴ�." << endl;
		else {
			map1[x][y] = 1;  //ĭ����
			cout << "ĭ�� ���ϴ�." << endl;
		}
	}
	else if (mn == 2) {
		if (map1[x][y] == 1) {
			cout << "�����ִ� ĭ���� ���ڸ� ǥ���� �� �����ϴ�." << endl;
		}
		else if (map1[x][y] == 2)
			cout << "����ǥ�ð� ���ִ� ĭ�Դϴ�." << endl;
		else {
			if (mc == getCount()) {
				cout << "ǥ�ð����� Ƚ���� �ʰ��߽��ϴ�." << endl;
			}
			else {
				map1[x][y] = 2;  //����ǥ��
				cout << "���ڸ� ǥ���մϴ�." << endl;
				mc++;
			}
		}
	}
	else if (mn == 3) {
		if (map1[x][y] == 1) {
			cout << "�����ִ� ĭ�Դϴ�." << endl;
		}
		else if (map1[x][y] == 0)
			cout << "����ǥ�ð� �ȵ��ִ� ĭ�Դϴ�." << endl;
		else {
			map1[x][y] = 0;  //����ǥ�����
			cout << "����ǥ�ø� ����մϴ�." << endl;
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
	cout << "ĭ�� �����ϼ���" << endl;
	while (1) {
		cout << "��: ";
		cin >> x1;
		if (x1 > m_row || x1 <= 0) {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
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
		cout << "��: ";
		cin >> y1;
		if (y1 > m_col || y1 <= 0) {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
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
				cout << right << setw(5) << "��";
			else if (map1[i][j] == 1 && map[i][j] != 9)
				cout << right << setw(4) << map[i][j];
			else if (map1[i][j] == 2)
				cout << right << setw(5) << "��";
		}
		cout << endl;
	}
	cout << "���ڰ���: " << getCount() << endl;
	cout << "ǥ�ð����� ���ڰ���: " << getCount() - mc << endl;
}

void Control::showWin()
{
	cout << "================================" << endl;
	cout << "��    �ڡ�    ��  ��  �ڡ�   ��" << endl;
	cout << " ��  ��  ��  ��   ��  �� ��  ��" << endl;
	cout << "  �ڡ�    �ڡ�    ��  ��  �� ��" << endl;
	cout << "   ��      ��     ��  ��   �ڡ�" << endl;
	cout << "================================" << endl;
}

void Control::showLose(Map& map, Map1& map1)
{
	cout << "====================================" << endl;
	cout << "���ڸ� ��ҽ��ϴ�!!!" << endl;
	cout << "------------------------------------" << endl;
	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			if (map[i][j] == 9 && map1[i][j] == 1)  //���ڹ���ĭ
				cout << right << setw(5) << "��";
			else if (map[i][j] == 9)
				cout << right << setw(5) << "��";
			else
				cout << right << setw(4) << map[i][j];
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "���� �Է� ĭ: " << getx() + 1 << "��," << gety() + 1 << "��" << endl;
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




