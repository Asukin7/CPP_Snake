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

#define KUANG 20//��Ϸ���ڿ��
#define GAO 20//��Ϸ���ڸ߶�

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
int SD = 1;//�ٶ�

void start();//��ʼ��Ϸ
void lost();
int eat(int czms);
void Snake_sjqd();//����������
void Snake_sjzd();//����յ����
void Snake_dyjm();//��ӡ����
void Snake_dy0(int x, int y);
void Snake_dy(int x, int y, char A, char B);
void Snake_dys(int czms, int eat);
void Snake_cz();
void Snake_fx(int czms, char UserHit);

void gotoxy(int x, int y);//�ƶ����

void Snake_zd();
int Snake_zd_zczw(int zczw);
void Snake_zd_zczw_cz(int zczw);
void Snake_zd_mn();
void Snake_zd_fx();
void Snake_zd_cz(int czms, int zczw);
void Snake_zd_fz();
void Snake_zd_zy();
/*
��ʼ
��� �����ҵ��Եģ�
{
	��� ������֮�����ҵ�β�ͣ�
	{
		ȥ��
		�ص���ʼ
	}
	����
	{
		��� �����ҵ�β�ͣ�
		{
			ȥ׷β��һ��
			�ص���ʼ
		}
	}
}
����
{
	��� �����ҵ�β�ͣ�
	{
		ȥ׷β��һ��
		�ص���ʼ
	}
	����
	{
		�����һ��
		�ص���ʼ
	}
}
*/