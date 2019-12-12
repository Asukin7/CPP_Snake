#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <queue>
#include <stack>

using namespace std;

#define KUANG 20//游戏窗口宽度
#define GAO 20//游戏窗口高度

struct xy
{
	int x;
	int y;
};
struct xys
{
	int x;
	int y;
	int s;
};
int ij[GAO][KUANG];
int t_ij[GAO][KUANG];
char fx;
xy Snake_zdxy;
queue<xy> Snake;
queue<xy> Snake_mn;
queue<xy> Snake_t;
queue<xys> dl;
queue<xys> dl_t;
stack<xys> dz;
stack<xys> cz;
stack<xys> cz_mn;
stack<xys> cz_t;
int BFSorDFS;//0BFS 1DFS
int SD = 1;//速度

void start();//开始游戏
void lost();
int eat(int czms);
void Snake_sjqd();//随机生成起点
void Snake_sjzd();//随机终点起点
void Snake_dyjm();//打印界面
void Snake_dy0(int x, int y);
void Snake_dy(int x, int y, char A, char B);
void Snake_dys(int czms, int eat);
void Snake_cz();
void Snake_fx(int czms, char UserHit);

void gotoxy(int x, int y);//移动光标

void Snake_zd();
int Snake_zd_zczw(int zczw);
void Snake_zd_zczw_cz(int zczw);
void Snake_zd_mn();
void Snake_zd_fx();
void Snake_zd_cz(int czms, int zczw);
void Snake_zd_fz();
void Snake_zd_zy();
/*
开始
如果 （能找到吃的）
{
	如果 （吃了之后能找到尾巴）
	{
		去吃
		回到开始
	}
	否则
	{
		如果 （能找到尾巴）
		{
			去追尾巴一步
			回到开始
		}
	}
}
否则
{
	如果 （能找到尾巴）
	{
		去追尾巴一步
		回到开始
	}
	否则
	{
		随机走一步
		回到开始
	}
}
*/