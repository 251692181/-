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


	cout << "输入文件名：";
	cin >> filename;

	file.open(filename.c_str());//打开文件
	if (file.fail()) //如果打开失败
	{
		cout << "文件打开出错" << endl;
		exit(1);
	}

	file >> x >> y;

	if (x > N || y > N) {   
		cerr << "网格太大，调整程序.\n";
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
				cout << "峰值出现在 行:" << i << " 列:" << j << endl;
				cout << "海拔高度：" << map[i][j];
				time++;
			}
			else if ( isValley (map, i, j)) {
				cout << "低峰值出现在行: " << i << " 列:" << j << endl;

			}
		}
		}
	cout << "峰值出现了：" << time << "次" << endl;
	file.close();


	








	/*
	char name;
	int pwd;
	
	cout << "请输入账号:";
	cin >> name;

	cout << "请输入密码:";
	cin >> pwd;


	system("pause");

	initgraph(800, 600);
	loadimage(0,_T("668.jpg"));       //加载图片
	settextstyle(15, 0, _T("黑体"));  //设置文本字体
	settextcolor(RGB(255, 0, 0));     //设置文本颜色
	setlinecolor(RGB(255, 0, 0));     //设置线条颜色
	setlinestyle(PS_SOLID, 1);        //设置线条大小

	//菜单栏
	rectangle(0,20,200,50);
    outtextxy(10, 30, _T("开   始   游   戏"));
	rectangle(0, 90, 200, 120);
	outtextxy(10, 100, _T("结   束   游   戏"));

	mciSendString(_T("open 11.wav alias 1 "), 0, 0, 0);
	outtextxy(0, 0, _T("按任意键开始播放"));
	_getch();

	// 播放音乐
	mciSendString(_T("play 1 "), 0, 0, 0);
	outtextxy(0, 0, _T("按任意键停止播放"));
	_getch();

	// 停止播放并关闭音乐
	mciSendString(_T("stop 1"), 0, 0, 0);
	mciSendString(_T("close 1"), 0, 0, 0);

	outtextxy(0, 0, _T("按任意键退出程序"));
	_getch();

	system("pause");
	closegraph();
	*/

	system("pause");
	return 0;
}