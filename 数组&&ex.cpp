#include <graphics.h>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include <string>
#pragma comment (lib,"winmm.lib")


using namespace std;

const int N = 64;
bool isPeak(const int map[][N], int i, int j) {
	if (map[i][j]>map[i-1][j]&&
		map[i][j]>map[i + 1][j]&&
		map[i][j]>map[i][j-1]&&
		map[i][j]>map[i][j+1]&&
		map[i][j]>map[i - 1][j-1] &&
		map[i][j]>map[i - 1][j+1] &&
		map[i][j]>map[i+1][j - 1] &&
		map[i][j]>map[i+1][j + 1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isValley(const int map[][N], int i, int j) {
	 if (map[i][j]<map[i - 1][j] &&
	map[i][j]<map[i + 1][j] &&
	map[i][j]<map[i][j - 1] &&
	map[i][j]<map[i][j + 1] &&
	map[i][j]<map[i - 1][j - 1] &&
	map[i][j]<map[i - 1][j + 1] &&
	map[i][j]<map[i + 1][j - 1] &&
	map[i][j]<map[i + 1][j + 1])
	{
	return true;
	 }
	 else
	 {
		 return false;
	 }
	
}








int main(void) {	
	int x, y;
	int map[N][N];
	int time = 0;
	string filename;
	ifstream file;


	cout << "�����ļ�����";
	cin >> filename;

	file.open(filename.c_str());//���ļ�
	if (file.fail()) //�����ʧ��
	{
		cout << "�ļ��򿪳���" << endl;
		exit(1);
	}

	file >> x >> y;

	if (x > N || y > N) {   
		cerr << "����̫�󣬵�������.\n";
		exit(1);
	}

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++)
		{
			file >> map[i][j];  
		}
	}


	for (int i = 1; i < x-1; i++){
		for (int j = 1; j < y - 1; j++) {
			if (isPeak(map, i, j)) {
				cout << "��ֵ������ ��:" << i << " ��:" << j << endl;
				cout << "���θ߶ȣ�" << map[i][j];
				time++;
			}
			else if ( isValley (map, i, j)) {
				cout << "�ͷ�ֵ��������: " << i << " ��:" << j << endl;

			}
		}
		}
	cout << "��ֵ�����ˣ�" << time << "��" << endl;
	file.close();


	








	/*
	char name;
	int pwd;
	
	cout << "�������˺�:";
	cin >> name;

	cout << "����������:";
	cin >> pwd;


	system("pause");

	initgraph(800, 600);
	loadimage(0,_T("668.jpg"));       //����ͼƬ
	settextstyle(15, 0, _T("����"));  //�����ı�����
	settextcolor(RGB(255, 0, 0));     //�����ı���ɫ
	setlinecolor(RGB(255, 0, 0));     //����������ɫ
	setlinestyle(PS_SOLID, 1);        //����������С

	//�˵���
	rectangle(0,20,200,50);
    outtextxy(10, 30, _T("��   ʼ   ��   Ϸ"));
	rectangle(0, 90, 200, 120);
	outtextxy(10, 100, _T("��   ��   ��   Ϸ"));

	mciSendString(_T("open 11.wav alias 1 "), 0, 0, 0);
	outtextxy(0, 0, _T("���������ʼ����"));
	_getch();

	// ��������
	mciSendString(_T("play 1 "), 0, 0, 0);
	outtextxy(0, 0, _T("�������ֹͣ����"));
	_getch();

	// ֹͣ���Ų��ر�����
	mciSendString(_T("stop 1"), 0, 0, 0);
	mciSendString(_T("close 1"), 0, 0, 0);

	outtextxy(0, 0, _T("��������˳�����"));
	_getch();

	system("pause");
	closegraph();
	*/

	system("pause");
	return 0;
}