#include "stdafx.h"

int main()
{
	system("title Snake v1.0.190125z");//设置窗口标题
	system("mode con cols=120 lines=60");//设置窗口大小
	/*获取并隐藏控制台光标*/
	HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(p, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(p, &CursorInfo);
	srand((unsigned)time(NULL));//随机数初始化
	getch();//////
	start();
	while (1)
	{
		Snake_zd();
		//Snake_cz();
	}
	//win();
	return 0;
}

void start()
{
	int i, j;
	for (i = 0; i < GAO; i++)
	{
		for (j = 0; j < KUANG; j++)
		{
			if (i != 0 && i != (GAO - 1) && j != 0 && j != (KUANG - 1))
				ij[i][j] = 0;
			else
				ij[i][j] = -1;
		}
	}
	Snake_dyjm();
	Snake_sjqd();
	Snake_sjzd();
}

void lost()
{
	xy t = Snake.back();
	if (ij[t.y][t.x] == -1)
	{
		gotoxy(KUANG - 6, 1);//////
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
		printf("  You die  ");
		getch();
		exit(0);
	}
}

int eat(int czms)
{
	xy t;
	if (czms == 1)
	{
		t = Snake.back();
		if (ij[t.y][t.x] == 1) return 1;
		else return 0;
	}
	else
	{
		t = Snake_mn.back();
		if (t_ij[t.y][t.x] == 1) return 1;
		else return 0;
	}
}

void Snake_sjqd()
{
	fx = 77;
	while (!Snake.empty()) Snake.pop();
	xy t;
	t.x = rand() % (KUANG / 3) + 2;
	t.y = rand() % (GAO / 3) + (GAO / 2);
	int i;
	for (i = 1; i <= 5; i++)
	{
		if (i < 5) Snake_dy(t.x, t.y, fx, fx);
		else Snake_dy(t.x, t.y, fx, 0);
		ij[t.y][t.x] = -1;
		Snake.push(t);
		t.x++;
	}
}

void Snake_sjzd()
{
	do
	{
		Snake_zdxy.x = rand() % (KUANG - 2) + 1;
		Snake_zdxy.y = rand() % (GAO - 2) + 1;
	} while (ij[Snake_zdxy.y][Snake_zdxy.x] != 0);
	ij[Snake_zdxy.y][Snake_zdxy.x] = 1;
	gotoxy(Snake_zdxy.x * 6 + 3, Snake_zdxy.y * 3 + 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("●");
}

void Snake_dyjm()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	system("cls");
	int i, j;
	for (i = 0; i < GAO; i++)
	{
		for (j = 0; j < KUANG; j++)
		{
			if (ij[i][j] == 0)
			{
				Snake_dy0(j, i);
			}
		}
		Sleep(SD);
	}
}

void Snake_dy0(int x, int y)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		gotoxy(x * 6 + 1, y * 3 + 1 + i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("      ");
	}
}

void Snake_dy(int x, int y, char A, char B)
{
	int i, j;
	Snake_dy0(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	gotoxy(x * 6 + 3, y * 3 + 2);
	printf("  ");
	switch (A)
	{
	case 72:i = 2; j = 1; break;
	case 80:i = 0; j = 1; break;
	case 75:i = 1; j = 2; break;
	case 77:i = 1; j = 0; break;
	default:break;
	}
	gotoxy(x * 6 + 1 + j * 2, y * 3 + 1 + i);
	printf("  ");
	switch (B)
	{
	case 72:i = 0; j = 1; break;
	case 80:i = 2; j = 1; break;
	case 75:i = 1; j = 0; break;
	case 77:i = 1; j = 2; break;
	default:break;
	}
	gotoxy(x * 6 + 1 + j * 2, y * 3 + 1 + i);
	printf("  ");
}

void Snake_dys(int czms, int eat)
{
	xy t, w;
	if (czms == 1)
	{
		t = Snake.back();
		w = Snake.front();
		if (eat == 1)
		{
			Snake_sjzd();
		}
		else
		{
			ij[w.y][w.x] = 0;
			Snake_dy0(w.x, w.y);
			Snake.pop();
		}
		ij[t.y][t.x] = -1;
		Snake_dy(t.x, t.y, fx, 0);
	}
	else
	{
		t = Snake_mn.back();
		w = Snake_mn.front();
		if (eat != 1)
		{
			t_ij[w.y][w.x] = 0;
			Snake_mn.pop();
		}
		t_ij[t.y][t.x] = -1;
	}
}

void Snake_cz()
{
	int i;
	char UserHit;
	for (i = 0; i <= 260; i += 10)
	{
		Sleep(10);
		if (kbhit())
		{
			UserHit = getch();
			switch (UserHit)
			{
			case 72:case 80:case 75:case 77:Snake_fx(1, UserHit); break;
			//case 32:Snake_zd(); break;
			}
			break;
		}
	}
	if (i >= 260) Snake_fx(1, fx);
}

void Snake_fx(int czms, char UserHit)
{
	xy t, w;
	if (czms == 1)
	{
		t = Snake.back();
		w = Snake.front();
		Snake_dy(t.x, t.y, fx, UserHit);
	}
	else
	{
		t = Snake_mn.back();
		w = Snake_mn.front();
	}
	switch (UserHit)
	{
	case 72:
	{
		if (fx == 80) return;
		t.y--;
		break;
	}
	case 80:
	{
		if (fx == 72) return;
		t.y++;
		break;
	}
	case 75:
	{
		if (fx == 77) return;
		t.x--;
		break;
	}
	case 77:
	{
		if (fx == 75) return;
		t.x++;
		break;
	}
	default:return;
	}
	fx = UserHit;
	if (czms == 1) Snake.push(t);
	else Snake_mn.push(t);
	//lost();
	Snake_dys(czms, eat(czms));
}

void gotoxy(int x, int y)//移动光标
{
	COORD p;
	p.X = x - 1;
	p.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Snake_zd()
{
	Snake_zd_fz();
	while (!dl.empty()) dl.pop();
	while (!dl_t.empty()) dl_t.pop();
	while (!dz.empty()) dz.pop();
	while (!cz.empty()) cz.pop();
	while (!cz_mn.empty()) cz_mn.pop();
	while (!cz_t.empty()) cz_t.pop();
	BFSorDFS = 0;
	if (Snake_zd_zczw(0) == 1)
	{
		Snake_zd_zczw_cz(0);
		Snake_zd_mn();
		if (Snake_zd_zczw(1) == 1)
		{
			Snake_zd_cz(1, 0);
			return;
		}
		else
		{
			int BDZY = rand() % 2;
			if (BDZY == 0) BFSorDFS = 1;
			Snake_zd_zczw_cz(1);
			if (BDZY == 1) Snake_zd_zy();
			Snake_zd_cz(1, 1);
			return;
		}
	}
	else
	{
		Snake_zd_fz();
		if (Snake_zd_zczw(1) == 1)
		{
			int BDZY = rand() % 2;
			if (BDZY == 0) BFSorDFS = 1;
			Snake_zd_zczw_cz(1);
			if (BDZY == 1) Snake_zd_zy();
			Snake_zd_cz(1, 1);
			return;
		}
	}
}

int Snake_zd_zczw(int zczw)
{
	xys zd_xys;
	if (zczw == 0)
	{
		zd_xys.x = Snake.back().x;
		zd_xys.y = Snake.back().y;
	}
	else
	{
		while (!dl.empty()) dl.pop();
		while (!dl_t.empty()) dl_t.pop();
		while (!dz.empty()) dz.pop();
		t_ij[Snake_mn.front().y][Snake_mn.front().x] = 0;
		zd_xys.x = Snake_mn.back().x;
		zd_xys.y = Snake_mn.back().y;
	}
	zd_xys.s = 0;
	dl.push(zd_xys);
	while (1)
	{
		if (dl.empty())
		{
			if (BFSorDFS == 0) return 0;
			while (!dl_t.empty())
			{
				dl.push(dl_t.front());
				dl_t.pop();
			}
		}
		Snake_zd_fx();
		dz.push(dl.front());
		dl_t.push(dl.front());
		zd_xys = dl.front();
		if (zczw == 0)
		{
			if (zd_xys.x == Snake_zdxy.x && zd_xys.y == Snake_zdxy.y) return 1;
		}
		else
		{
			if (zd_xys.x == Snake_mn.front().x && zd_xys.y == Snake_mn.front().y) return 1;
		}
		dl.pop();
	}
}

void Snake_zd_zczw_cz(int zczw)
{
	if (zczw == 0)
	{
		if (Snake_zd_zczw(0) == 0) return;
	}
	else
	{
		Snake_zd_fz();
		while (!dz.empty()) dz.pop();
		while (!cz.empty()) cz.pop();
		if (Snake_zd_zczw(1) == 0) return;
	}
	xys zd_xys;
	xys t_xys;
	zd_xys = dz.top();
	dz.pop();
	cz.push(zd_xys);
	if (zczw == 0) cz_mn.push(zd_xys);
	while (!dz.empty())
	{
		t_xys = dz.top();
		if (zd_xys.s == t_xys.s + 1)
		{
			if ((zd_xys.x == t_xys.x - 1 && zd_xys.y == t_xys.y)
				|| (zd_xys.x == t_xys.x + 1 && zd_xys.y == t_xys.y)
				|| (zd_xys.x == t_xys.x && zd_xys.y == t_xys.y - 1)
				|| (zd_xys.x == t_xys.x && zd_xys.y == t_xys.y + 1))
			{
				zd_xys = t_xys;
				cz.push(zd_xys);
				if (zczw == 0) cz_mn.push(zd_xys);
			}
		}
		dz.pop();
	}
}

void Snake_zd_mn()
{
	int t_fx = fx;
	Snake_zd_fz();
	Snake_zd_cz(0, 0);
	fx = t_fx;
}

void Snake_zd_fx()
{
	xys zd_xys;
	xys t_xys;
	t_xys = dl.front();
	zd_xys = t_xys;
	if (t_ij[zd_xys.y - 1][zd_xys.x] != -1)
	{
		zd_xys.y--;
		zd_xys.s++;
		t_ij[zd_xys.y][zd_xys.x] = -1;
		dl.push(zd_xys);
		if (BFSorDFS == 1) return;
	}
	zd_xys = t_xys;
	if (t_ij[zd_xys.y + 1][zd_xys.x] != -1)
	{
		zd_xys.y++;
		zd_xys.s++;
		t_ij[zd_xys.y][zd_xys.x] = -1;
		dl.push(zd_xys);
		if (BFSorDFS == 1) return;
	}
	zd_xys = t_xys;
	if (t_ij[zd_xys.y][zd_xys.x - 1] != -1)
	{
		zd_xys.x--;
		zd_xys.s++;
		t_ij[zd_xys.y][zd_xys.x] = -1;
		dl.push(zd_xys);
		if (BFSorDFS == 1) return;
	}
	zd_xys = t_xys;
	if (t_ij[zd_xys.y][zd_xys.x + 1] != -1)
	{
		zd_xys.x++;
		zd_xys.s++;
		t_ij[zd_xys.y][zd_xys.x] = -1;
		dl.push(zd_xys);
		if (BFSorDFS == 1) return;
	}
}

void Snake_zd_cz(int czms, int zczw)
{
	xys t, xy;
	bool loop;
	if (czms == 1)
	{
		loop = !cz.empty();
		t = cz.top();
		cz.pop();
	}
	else
	{
		loop = !cz_mn.empty();
		t = cz_mn.top();
		cz_mn.pop();
	}
	while (loop)
	{
		if (czms == 1)
		{
			xy.y = cz.top().y - t.y;
			xy.x = cz.top().x - t.x;
		}
		else
		{
			xy.y = cz_mn.top().y - t.y;
			xy.x = cz_mn.top().x - t.x;
		}
		switch (xy.y)
		{
		case -1:Snake_fx(czms, 72); break;
		case 1:Snake_fx(czms, 80); break;
		default:break;
		}
		switch (xy.x)
		{
		case -1:Snake_fx(czms, 75); break;
		case 1:Snake_fx(czms, 77); break;
		default:break;
		}
		if (czms == 1)
		{
			Sleep(SD);
			t = cz.top();
			cz.pop();
			loop = !cz.empty();
			if (zczw == 1) return;
		}
		else
		{
			t = cz_mn.top();
			cz_mn.pop();
			loop = !cz_mn.empty();
		}
	}
}

void Snake_zd_fz()
{
	memcpy(t_ij, ij, sizeof(ij));
	while (!Snake_mn.empty()) Snake_mn.pop();
	while (!Snake_t.empty()) Snake_t.pop();
	while (!Snake.empty())
	{
		Snake_mn.push(Snake.front());
		Snake_t.push(Snake.front());
		Snake.pop();
	}
	while (!Snake_t.empty())
	{
		Snake.push(Snake_t.front());
		Snake_t.pop();
	}
}

void Snake_zd_zy()
{
	xys t1_xys;
	xys t2_xys;
	memcpy(t_ij, ij, sizeof(ij));
	while (!cz.empty())
	{
		t_ij[cz.top().y][cz.top().x] = -1;
		cz_t.push(cz.top());
		cz.pop();
	}
	while (!cz_t.empty())
	{
		cz.push(cz_t.top());
		cz_t.pop();
	}
	while (cz.size() >= 2)
	{
		cz_t.push(cz.top());
		t2_xys = cz_t.top();
		cz.pop();
		t1_xys = cz.top();
		if (t_ij[t1_xys.y - 1][t1_xys.x] == 0 && t_ij[t2_xys.y - 1][t2_xys.x] == 0)
		{
			t1_xys.y--;
			t2_xys.y--;
			t_ij[t1_xys.y][t1_xys.x] = -1;
			t_ij[t2_xys.y][t2_xys.x] = -1;
			cz.push(t1_xys);
			cz.push(t2_xys);
			cz.push(cz_t.top());
			cz_t.pop();
			continue;
		}
		if (t_ij[t1_xys.y + 1][t1_xys.x] == 0 && t_ij[t2_xys.y + 1][t2_xys.x] == 0)
		{
			t1_xys.y++;
			t2_xys.y++;
			t_ij[t1_xys.y][t1_xys.x] = -1;
			t_ij[t2_xys.y][t2_xys.x] = -1;
			cz.push(t1_xys);
			cz.push(t2_xys);
			cz.push(cz_t.top());
			cz_t.pop();
			continue;
		}
		if (t_ij[t1_xys.y][t1_xys.x - 1] == 0 && t_ij[t2_xys.y][t2_xys.x - 1] == 0)
		{
			t1_xys.x--;
			t2_xys.x--;
			t_ij[t1_xys.y][t1_xys.x] = -1;
			t_ij[t2_xys.y][t2_xys.x] = -1;
			cz.push(t1_xys);
			cz.push(t2_xys);
			cz.push(cz_t.top());
			cz_t.pop();
			continue;
		}
		if (t_ij[t1_xys.y][t1_xys.x + 1] == 0 && t_ij[t2_xys.y][t2_xys.x + 1] == 0)
		{
			t1_xys.x++;
			t2_xys.x++;
			t_ij[t1_xys.y][t1_xys.x] = -1;
			t_ij[t2_xys.y][t2_xys.x] = -1;
			cz.push(t1_xys);
			cz.push(t2_xys);
			cz.push(cz_t.top());
			cz_t.pop();
			continue;
		}
	}
	while (!cz_t.empty())
	{
		cz.push(cz_t.top());
		cz_t.pop();
	}
}

void Snake_zd_zh()
{
	//WASD虚拟移动一步选择离吃最远并能找到尾巴的一个方向真实移动一步
	//如果找不到吃的就选择离尾巴最远的一个方向真实移动一步
}