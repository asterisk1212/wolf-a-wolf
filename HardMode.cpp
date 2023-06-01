#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<time.h>
#include<graphics.h>
#include<Windows.h>
#include<mmsystem.h>
#include "rand.h"
#include <windows.h>
//#include <conio.h>
#pragma comment(lib,"winmm.lib")

int const WIDTH = 467;
int const HEIGHT = 735;
int const NUM = 6;
int const INTERVAL = 10;
int const PCTSIZE = 50;
int case1 = 6;
int size1[6][6] = { 0 };
int size2[6][6] = { 0 };
int size3[6][6] = { 0 };
int size4[6][6] = { 0 };

IMAGE imgbk,modepage;
IMAGE img1[16];
IMAGE win[147];//游戏成功gif声明
IMAGE lost[55];//声明
IMAGE lostback, fuhuo;//返回游戏和复活游戏
IMAGE back, again;//返回游戏和复活游戏
IMAGE yichu, shuaxin, chehui;
IMAGE img, img2, img4;
IMAGE imgbolt,playbk, playbk23;
HWND hnd = GetHWnd();
LPCTSTR Easy = "简单模式";
LPCTSTR Norm = "普通模式";
LPCTSTR Diff = "困难模式";

//把声明放到前面

void Loadpicture()
{
	loadimage(&imgbk, _T("./img/bk.jpg"));
	loadimage(&yichu, _T("./img/yichu.jpg"),PCTSIZE,PCTSIZE);
	loadimage(&shuaxin, _T("./img/shuaxin.jpg"), PCTSIZE, PCTSIZE);
	loadimage(&chehui, _T("./img/chehui.jpg"), PCTSIZE, PCTSIZE);
	loadimage(img1 + 10, "./img/jianxin.jpg",PCTSIZE,PCTSIZE );
	loadimage(img1 + 11, "./img/yueshu.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 12, "./img/xiaoyu.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 13, "./img/chuanhao.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 14, "./img/liaozheng.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 15, "./img/weichu.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 6, "./img/yian.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 7, "./img/xiaobai.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 8, "./img/xiuxiu.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 9, "./img/dongdong.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 0, "./img/1.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 1, "./img/2.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 2, "./img/3.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 3, "./img/4.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 4, "./img/5.jpg", PCTSIZE, PCTSIZE);
	loadimage(img1 + 5, "./img/6.jpg", PCTSIZE, PCTSIZE);
	loadimage(&img, "./img/beijing1.png", 467, 735);
	loadimage(&img2, "./img/shezhi.jpg", 467, 735);
	loadimage(&img4, "./shezhitubiao2.png", 50, 50);
	loadimage(&imgbolt, "./img/kuang.jpg", 364, 80);
	loadimage(&playbk,"./img/1game.png",WIDTH,HEIGHT);
	loadimage(&playbk23, "./img/23game.jpg", WIDTH, HEIGHT);
	loadimage(&modepage, "./img/modepage.png", WIDTH, HEIGHT);
}
void Loadwin()
{
	loadimage(&win[0], "./win/0.jpg", 300, 300);
	loadimage(&win[1], "./win/1.jpg", 300, 300);
	loadimage(&win[2], "./win/2.jpg", 300, 300);
	loadimage(&win[3], "./win/3.jpg", 300, 300);
	loadimage(&win[4], "./win/4.jpg", 300, 300);
	loadimage(&win[5], "./win/5.jpg", 300, 300);
	loadimage(&win[6], "./win/6.jpg", 300, 300);
	loadimage(&win[7], "./win/7.jpg", 300, 300);
	loadimage(&win[8], "./win/8.jpg", 300, 300);
	loadimage(&win[9], "./win/9.jpg", 300, 300);
	loadimage(&win[10], "./win/10.jpg", 300, 300);
	loadimage(&win[11], "./win/11.jpg", 300, 300);
	loadimage(&win[12], "./win/12.jpg", 300, 300);
	loadimage(&win[13], "./win/13.jpg", 300, 300);
	loadimage(&win[14], "./win/14.jpg", 300, 300);
	loadimage(&win[15], "./win/15.jpg", 300, 300);
	loadimage(&win[16], "./win/16.jpg", 300, 300);
	loadimage(&win[17], "./win/17.jpg", 300, 300);
	loadimage(&win[18], "./win/18.jpg", 300, 300);
	loadimage(&win[19], "./win/19.jpg", 300, 300);
	loadimage(&win[20], "./win/20.jpg", 300, 300);
	loadimage(&win[21], "./win/21.jpg", 300, 300);
	loadimage(&win[22], "./win/22.jpg", 300, 300);
	loadimage(&win[23], "./win/23.jpg", 300, 300);
	loadimage(&win[24], "./win/24.jpg", 300, 300);
	loadimage(&win[25], "./win/25.jpg", 300, 300);
	loadimage(&win[26], "./win/26.jpg", 300, 300);
	loadimage(&win[27], "./win/27.jpg", 300, 300);
	loadimage(&win[28], "./win/28.jpg", 300, 300);
	loadimage(&win[29], "./win/29.jpg", 300, 300);
	loadimage(&win[30], "./win/30.jpg", 300, 300);
	loadimage(&win[31], "./win/31.jpg", 300, 300);
	loadimage(&win[32], "./win/32.jpg", 300, 300);
	loadimage(&win[33], "./win/33.jpg", 300, 300);
	loadimage(&win[34], "./win/34.jpg", 300, 300);
	loadimage(&win[35], "./win/35.jpg", 300, 300);
	loadimage(&win[36], "./win/36.jpg", 300, 300);
	loadimage(&win[37], "./win/37.jpg", 300, 300);
	loadimage(&win[38], "./win/38.jpg", 300, 300);
	loadimage(&win[39], "./win/39.jpg", 300, 300);
	loadimage(&win[40], "./win/40.jpg", 300, 300);
	loadimage(&win[41], "./win/41.jpg", 300, 300);
	loadimage(&win[42], "./win/42.jpg", 300, 300);
	loadimage(&win[43], "./win/43.jpg", 300, 300);
	loadimage(&win[44], "./win/44.jpg", 300, 300);
	loadimage(&win[45], "./win/45.jpg", 300, 300);
	loadimage(&win[46], "./win/46.jpg", 300, 300);
	loadimage(&win[47], "./win/47.jpg", 300, 300);
	loadimage(&win[48], "./win/48.jpg", 300, 300);
	loadimage(&win[49], "./win/49.jpg", 300, 300);
	loadimage(&win[50], "./win/50.jpg", 300, 300);
	loadimage(&win[51], "./win/51.jpg", 300, 300);
	loadimage(&win[52], "./win/52.jpg", 300, 300);
	loadimage(&win[53], "./win/53.jpg", 300, 300);
	loadimage(&win[54], "./win/54.jpg", 300, 300);
	loadimage(&win[55], "./win/55.jpg", 300, 300);
	loadimage(&win[56], "./win/56.jpg", 300, 300);
	loadimage(&win[57], "./win/57.jpg", 300, 300);
	loadimage(&win[58], "./win/58.jpg", 300, 300);
	loadimage(&win[59], "./win/59.jpg", 300, 300);
	loadimage(&win[60], "./win/60.jpg", 300, 300);
	loadimage(&win[61], "./win/61.jpg", 300, 300);
	loadimage(&win[62], "./win/62.jpg", 300, 300);
	loadimage(&win[63], "./win/63.jpg", 300, 300);
	loadimage(&win[64], "./win/64.jpg", 300, 300);
	loadimage(&win[65], "./win/65.jpg", 300, 300);
	loadimage(&win[66], "./win/66.jpg", 300, 300);
	loadimage(&win[67], "./win/67.jpg", 300, 300);
	loadimage(&win[68], "./win/68.jpg", 300, 300);
	loadimage(&win[69], "./win/69.jpg", 300, 300);
	loadimage(&win[70], "./win/70.jpg", 300, 300);
	loadimage(&win[71], "./win/71.jpg", 300, 300);
	loadimage(&win[72], "./win/72.jpg", 300, 300);
	loadimage(&win[73], "./win/73.jpg", 300, 300);
	loadimage(&win[74], "./win/74.jpg", 300, 300);
	loadimage(&win[75], "./win/75.jpg", 300, 300);
	loadimage(&win[76], "./win/76.jpg", 300, 300);
	loadimage(&win[77], "./win/77.jpg", 300, 300);
	loadimage(&win[78], "./win/78.jpg", 300, 300);
	loadimage(&win[79], "./win/79.jpg", 300, 300);
	loadimage(&win[80], "./win/80.jpg", 300, 300);
	loadimage(&win[81], "./win/81.jpg", 300, 300);
	loadimage(&win[82], "./win/82.jpg", 300, 300);
	loadimage(&win[83], "./win/83.jpg", 300, 300);
	loadimage(&win[84], "./win/84.jpg", 300, 300);
	loadimage(&win[85], "./win/85.jpg", 300, 300);
	loadimage(&win[86], "./win/86.jpg", 300, 300);
	loadimage(&win[87], "./win/87.jpg", 300, 300);
	loadimage(&win[88], "./win/88.jpg", 300, 300);
	loadimage(&win[89], "./win/89.jpg", 300, 300);
	loadimage(&win[90], "./win/90.jpg", 300, 300);
	loadimage(&win[91], "./win/91.jpg", 300, 300);
	loadimage(&win[92], "./win/92.jpg", 300, 300);
	loadimage(&win[93], "./win/93.jpg", 300, 300);
	loadimage(&win[94], "./win/94.jpg", 300, 300);
	loadimage(&win[95], "./win/95.jpg", 300, 300);
	loadimage(&win[96], "./win/96.jpg", 300, 300);
	loadimage(&win[97], "./win/97.jpg", 300, 300);
	loadimage(&win[98], "./win/98.jpg", 300, 300);
	loadimage(&win[99], "./win/99.jpg", 300, 300);
	loadimage(&win[100], "./win/100.jpg", 300, 300);
	loadimage(&win[101], "./win/101.jpg", 300, 300);
	loadimage(&win[102], "./win/102.jpg", 300, 300);
	loadimage(&win[103], "./win/103.jpg", 300, 300);
	loadimage(&win[104], "./win/104.jpg", 300, 300);
	loadimage(&win[105], "./win/105.jpg", 300, 300);
	loadimage(&win[106], "./win/106.jpg", 300, 300);
	loadimage(&win[107], "./win/107.jpg", 300, 300);
	loadimage(&win[108], "./win/108.jpg", 300, 300);
	loadimage(&win[109], "./win/109.jpg", 300, 300);
	loadimage(&win[110], "./win/110.jpg", 300, 300);
	loadimage(&win[111], "./win/111.jpg", 300, 300);
	loadimage(&win[112], "./win/112.jpg", 300, 300);
	loadimage(&win[113], "./win/113.jpg", 300, 300);
	loadimage(&win[114], "./win/114.jpg", 300, 300);
	loadimage(&win[115], "./win/115.jpg", 300, 300);
	loadimage(&win[116], "./win/116.jpg", 300, 300);
	loadimage(&win[117], "./win/117.jpg", 300, 300);
	loadimage(&win[118], "./win/118.jpg", 300, 300);
	loadimage(&win[119], "./win/119.jpg", 300, 300);
	loadimage(&win[120], "./win/120.jpg", 300, 300);
	loadimage(&win[121], "./win/121.jpg", 300, 300);
	loadimage(&win[122], "./win/122.jpg", 300, 300);
	loadimage(&win[123], "./win/123.jpg", 300, 300);
	loadimage(&win[124], "./win/124.jpg", 300, 300);
	loadimage(&win[125], "./win/125.jpg", 300, 300);
	loadimage(&win[126], "./win/126.jpg", 300, 300);
	loadimage(&win[127], "./win/127.jpg", 300, 300);
	loadimage(&win[128], "./win/128.jpg", 300, 300);
	loadimage(&win[129], "./win/129.jpg", 300, 300);
	loadimage(&win[130], "./win/130.jpg", 300, 300);
	loadimage(&win[131], "./win/131.jpg", 300, 300);
	loadimage(&win[132], "./win/132.jpg", 300, 300);
	loadimage(&win[133], "./win/133.jpg", 300, 300);
	loadimage(&win[134], "./win/134.jpg", 300, 300);
	loadimage(&win[135], "./win/135.jpg", 300, 300);
	loadimage(&win[136], "./win/136.jpg", 300, 300);
	loadimage(&win[137], "./win/137.jpg", 300, 300);
	loadimage(&win[138], "./win/138.jpg", 300, 300);
	loadimage(&win[139], "./win/139.jpg", 300, 300);
	loadimage(&win[140], "./win/140.jpg", 300, 300);
	loadimage(&win[141], "./win/141.jpg", 300, 300);
	loadimage(&win[142], "./win/142.jpg", 300, 300);
	loadimage(&win[143], "./win/143.jpg", 300, 300);
	loadimage(&win[144], "./win/144.jpg", 300, 300);
	loadimage(&back, "./win/back.jpg", 300, 50);
	loadimage(&again, "./win/again.jpg", 300, 50);
}//加载游戏成功gif相关图片
void Loadlost()
{
	loadimage(&lost[0], "./lost/1.jpg", 300, 300);
	loadimage(&lost[1], "./lost/2.jpg", 300, 300);
	loadimage(&lost[2], "./lost/3.jpg", 300, 300);
	loadimage(&lost[3], "./lost/4.jpg", 300, 300);
	loadimage(&lost[4], "./lost/5.jpg", 300, 300);
	loadimage(&lost[5], "./lost/6.jpg", 300, 300);
	loadimage(&lost[6], "./lost/7.jpg", 300, 300);
	loadimage(&lost[7], "./lost/8.jpg", 300, 300);
	loadimage(&lost[8], "./lost/9.jpg", 300, 300);
	loadimage(&lost[9], "./lost/10.jpg", 300, 300);
	loadimage(&lost[10], "./lost/11.jpg", 300, 300);
	loadimage(&lost[11], "./lost/12.jpg", 300, 300);
	loadimage(&lost[12], "./lost/13.jpg", 300, 300);
	loadimage(&lost[13], "./lost/14.jpg", 300, 300);
	loadimage(&lost[14], "./lost/15.jpg", 300, 300);
	loadimage(&lost[15], "./lost/16.jpg", 300, 300);
	loadimage(&lost[16], "./lost/17.jpg", 300, 300);
	loadimage(&lost[17], "./lost/18.jpg", 300, 300);
	loadimage(&lost[18], "./lost/19.jpg", 300, 300);
	loadimage(&lost[19], "./lost/20.jpg", 300, 300);
	loadimage(&lost[20], "./lost/21.jpg", 300, 300);
	loadimage(&lost[21], "./lost/22.jpg", 300, 300);
	loadimage(&lost[22], "./lost/23.jpg", 300, 300);
	loadimage(&lost[23], "./lost/24.jpg", 300, 300);
	loadimage(&lost[24], "./lost/25.jpg", 300, 300);
	loadimage(&lost[25], "./lost/26.jpg", 300, 300);
	loadimage(&lost[26], "./lost/27.jpg", 300, 300);
	loadimage(&lost[27], "./lost/28.jpg", 300, 300);
	loadimage(&lost[28], "./lost/29.jpg", 300, 300);
	loadimage(&lost[29], "./lost/30.jpg", 300, 300);
	loadimage(&lost[30], "./lost/31.jpg", 300, 300);
	loadimage(&lost[31], "./lost/32.jpg", 300, 300);
	loadimage(&lost[32], "./lost/33.jpg", 300, 300);
	loadimage(&lost[33], "./lost/34.jpg", 300, 300);
	loadimage(&lost[34], "./lost/35.jpg", 300, 300);
	loadimage(&lost[35], "./lost/36.jpg", 300, 300);
	loadimage(&lost[36], "./lost/37.jpg", 300, 300);
	loadimage(&lost[37], "./lost/38.jpg", 300, 300);
	loadimage(&lost[38], "./lost/39.jpg", 300, 300);
	loadimage(&lost[39], "./lost/40.jpg", 300, 300);
	loadimage(&lost[40], "./lost/41.jpg", 300, 300);
	loadimage(&lost[41], "./lost/42.jpg", 300, 300);
	loadimage(&lost[42], "./lost/43.jpg", 300, 300);
	loadimage(&lost[43], "./lost/44.jpg", 300, 300);
	loadimage(&lost[44], "./lost/45.jpg", 300, 300);
	loadimage(&lost[45], "./lost/46.jpg", 300, 300);
	loadimage(&lost[46], "./lost/47.jpg", 300, 300);
	loadimage(&lost[47], "./lost/48.jpg", 300, 300);
	loadimage(&lost[48], "./lost/49.jpg", 300, 300);
	loadimage(&lost[49], "./lost/50.jpg", 300, 300);
	loadimage(&lost[50], "./lost/51.jpg", 300, 300);
	loadimage(&lost[51], "./lost/52.jpg", 300, 300);
	loadimage(&lost[52], "./lost/53.jpg", 300, 300);
	loadimage(&lost[53], "./lost/54.jpg", 300, 300);
	loadimage(&lost[54], "./lost/55.jpg", 300, 300);
	loadimage(&lostback, "./lost/back.jpg", 300, 50);
	loadimage(&fuhuo, "./lost/fuhuo.jpg", 300, 50);
}//加载
void shuffle(int size[6][6])
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			size[i][j] = (((i + j+116)%16+1)+(i+j+25)%16+1)%16+1;
			printf("%d ", size[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			int i1=random()%123;
			i1 = i1 % 5;
			Sleep(1);
			int j1 = random() % 45;
			j1 = j1 % 5;
			//printf("\t%d %d", i1, j1);
			int temp;
			//printf("%d ", size[i1][j1]);
			temp = size[i][j];
			size[i][j] = size[i1][j1];
			size[i1][j1] = temp;
			//printf("%d ", size[i][j]);
		}
		//printf("\n");
	}
	
}
void shuffle2(int size[6][6])
{
	//int too1[6][6], int* row1, int* col1
	int cnt = 0;
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			int i1 = random() % 123;
			i1 = i1 % 5;
			//Sleep(1);
			int j1 = random() % 45;
			j1 = j1 % 5;
			
			/*if (*row1 == i && *col1 == j&&cnt==0)
			{
				printf("%d %d \n", *row1, *col1);
				printf("%d\n", size[i][j]);
				*row1 = i1; *col1 = j1;
				cnt++;
			}*/
			//printf("\t%d %d", i1, j1);
			int temp;
			//printf("%d ", size[i1][j1]);
			temp = size[i][j];
			size[i][j] = size[i1][j1];
			size[i1][j1] = temp;
			//printf("%d ", size[i][j]);
		}
		//printf("\n");
	}
}
int ArrayAssignment(int x, int y, int* pctcnt)
{
	if (*pctcnt >= 9)
	{
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		//判断左上角
		for (int i = 0; i < NUM/2; i++)
		{
			for (int j = 0; j < NUM / 2; j++) 
			{
				if (size1[i][j] == 0)
					cnt1++;
				//printf("cnt1=%d \n", cnt1);
			}
		}
		if (cnt1 == 9&&size2[0][0]!=0)
		{
			for (int i = 0; i < NUM / 2; i++)
			{
				for (int j = 0; j < NUM / 2; j++)
				{
					size1[i][j] = size2[i][j];
					//printf("\tsize2=%d", size2[i][j]);
					size2[i][j] = 0;	
				}
			}
			cnt1 = 0;
			return *pctcnt -= 9;
		}
		else if(cnt1==9&&size3[0][0]!=0)
		{
			for (int i = 0; i < NUM / 2; i++)
			{
				for (int j = 0; j < NUM / 2; j++)
				{
					size1[i][j] = size3[i][j];
					size3[i][j] = 0;
					
				}
			}
			cnt1 = 0;	return *pctcnt -= 9;
		}
		//判断左下角
		for (int i = 0; i < NUM / 2; i++)
		{
			for (int j = NUM/2; j < NUM; j++)
			{
				if (size1[i][j] == 0)
					cnt2++;
			}
		}
		if (cnt2 == 9 && size2[0][3] != 0)
		{
			for (int i = 0; i < NUM / 2; i++)
			{
				for (int j = NUM/2; j < NUM; j++)
				{
					size1[i][j] = size2[i][j];
					size2[i][j] = 0;
				}
			}cnt2 = 0;	return *pctcnt -= 9;
		}
		else if (cnt2 == 9 && size3[0][3] != 0)
		{
			for (int i = 0; i < NUM / 2; i++)
			{
				for (int j = NUM/2; j < NUM ; j++)
				{
					size1[i][j] = size3[i][j];
					size3[i][j] = 0;
					
				}
			}
			cnt2 = 0;	return *pctcnt -= 9;
		}
		//判断右上角
		for (int i = NUM/2; i < NUM; i++)
		{
			for (int j = 0; j < NUM / 2; j++)
			{
				if (size1[i][j] == 0)
					cnt3++;
			}
		}
		if (cnt3 == 9 && size2[3][0] != 0)
		{
			for (int i = NUM/2; i < NUM; i++)
			{
				for (int j = 0; j < NUM / 2; j++)
				{
					size1[i][j] = size2[i][j];
					size2[i][j] = 0;
					
				}
			}
			cnt3 = 0;	return *pctcnt -= 9;
		}
		else if (cnt3 == 9 && size3[3][0] != 0)
		{
			for (int i = NUM/2; i < NUM; i++)
			{
				for (int j = 0; j < NUM / 2; j++)
				{
					size1[i][j] = size3[i][j];
					size3[i][j] = 0;
					
				}
			}
			cnt3 = 0;	return *pctcnt -= 9;
		}
		//判断右下角
		for (int i =NUM/2; i < NUM; i++)
		{
			for (int j = NUM / 2; j < NUM; j++)
			{
				if (size1[i][j] == 0)
					cnt4++;
			}
		}
		if (cnt4 == 9 && size2[3][3] != 0)
		{
			for (int i = NUM/2; i < NUM; i++)
			{
				for (int j = NUM / 2; j < NUM; j++)
				{
					size1[i][j] = size2[i][j];
					size2[i][j] = 0;
					
				}
			}
			cnt4 = 0;	return *pctcnt -= 9;
		}
		else if (cnt4 == 9 && size3[3][3] != 0)
		{
			for (int i = NUM/2; i < NUM; i++)
			{
				for (int j = NUM / 2; j < NUM; j++)
				{
					size1[i][j] = size3[i][j];
					size3[i][j] = 0;
					
				}
			}
			cnt4 = 0;	return *pctcnt -= 9;
		}
	}

	return *pctcnt;
}
void fuzhi(int size[6][6])
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			size[i][j] = rand() % 16 + 1;
			//printf("%d ", size[i][j]);
		}
		//printf("\n");
	}
}
//数组赋值
void Array(int size[6][6], int size2[6][6], int size3[6][6])
//重排数组
{
		
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < NUM; j++)
			{
				int i1 = random() % 123;
				i1 = i1 % 5;
				Sleep(1);
				int j1 = random() % 45;
				j1 = j1 % 5;
				//printf("\t%d %d", i1, j1);
				int temp;
				//printf("%d ", size[i1][j1]);
				temp = size[i][j];
				size[i][j] = size[i1][j1];
				size[i1][j1] = temp;
				printf("%d ", size[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < NUM; j++)
			{
				int temp;
				temp = size[i][j];
				size2[i][j] = size[i][j];

				printf("%d ", size2[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < NUM; j++)
			{
				int temp;
				temp = size[i][j];
				size3[i][j] = size[i][j];

				printf("%d ", size3[i][j]);
			}
			printf("\n");
		}
		printf("--------------------------\n\n");
}
int WinGame(int size1[6][6], int size2[6][6], int size3[6][6],int store[7])
//重排数组
{
	int cnt = 0;
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			if (size1[i][j] > 0)
			{
				cnt++;
			}

		}
	}
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			if (size2[i][j] > 0)
			{
				cnt++;
			}

		}
	}
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			if (size3[i][j] > 0)
			{
				cnt++;
			}

		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (store[i] > 0) {
			cnt++;
		}
	}
	return cnt;
}
//游戏成功的判断
bool allEmpty(int(*arr)[NUM])
{
	for (int r = 0; r < NUM; r++)
	{
		for (int c = 0; c < NUM; c++)
		{
			if (arr[r][c])
				return false;
		}
	}
	return true;
}
int random(int(*map)[NUM])
{
	//初始化地图
	for (int r = 0; r < NUM; r++)
	{
		for (int c = 0; c < NUM; c++)
		{
			map[r][c] = r + 1;
		}
	}
	//打乱数组
	srand(time(0));
	for (int r = 0; r < NUM; r++)
	{
		for (int c = 0; c < NUM; c++)
		{//数组当中的行和列随机打乱
			int r1 = rand() % NUM;
			Sleep(2);
			int c1 = rand() % NUM;
			int t = map[r1][c1];
			map[r1][c1] = map[r][c];
			map[r][c] = t;
		}
	}
	return 0;
}

//这个函数是判断鼠标的X,Y 坐标是不是在矩形内的在矩形里面就返回一个bool值 不在则假
bool printInRect(int x, int y, RECT& r)
{
	printf("%d %d %d %d\n", r.left, r.top, r.right, r.bottom);
	//printf 这行注释是常用的调试方法 可视化坐标 判断你是不是矩形坐标写的有问题
	return(r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
	//判断给的鼠标的x，y坐标是否在矩形区域内，是的话就返回真，不是则假
}
void PlayMsc()
{
	printf("case1=%d\n", case1);
		mciSendString("open ./music/beijing.mp3", 0, 0, 0);
		mciSendString("play ./music/beijing.mp3", 0, 0, 0);
	//return case1 = 2;
}
//放音乐
void CloseMsc()
{
		printf("case1.=%d\n", case1);
		//mciSendString("open ./music/beijing.mp3 ", 0, 0, 0);
		//mciSendString("play ./music/beijing.mp3 repeat", 0, 0, 0);
		//Sleep(2);
		mciSendString("pause ./music/beijing.mp3", 0, 0, 0);
	//return case1=2;
}
//暂停音乐  听歌肯定是一遍一遍的听嘛
//谁听歌永远只听开头啊  那样子多美乐趣 所以是暂停不是关闭！
int WinGame()
{

	Loadwin();
	int i;
	while (true)
	{
		/*mciSendString("open ./music/beijing.mp3", 0, 0, 0);
		mciSendString("play ./music/beijing.mp3", 0, 0, 0);*/
		BeginBatchDraw();
		putimage(100, 400, &back);
		putimage(100, 450, &again);
		for (i = 0; i < 105; i++)
		{
			putimage(100, 100, &win[i]);
			EndBatchDraw();
			Sleep(10);
			ExMessage msg = { 0 };
			if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x > 100 && msg.x < 400 && msg.y>400 && msg.y < 450)
				{
					//printf("%d , %d\n", msg.x, msg.y);
					return case1 = 4;
					break;
				}
				else if (msg.x > 100 && msg.x < 400 && msg.y>450 && msg.y < 500)
				{
					//printf("%d , %d\n", msg.x, msg.y);
					if (case1 == 5)
					{
						return case1 = 5;
						break;
					}
					else if (case1 == 6)
					{
						return case1 = 6;
						break;
					}
					else if (case1 == 7)
					{
						return case1 = 7;
						break;
					}
				}

			}

			if (i == 100)i = 0;
		}

	}
}
//游戏胜利界面
int LostGame()
{
	Loadlost();
	int i;
	while (true)
	{
		BeginBatchDraw();
		putimage(100, 400, &lostback);
		putimage(100, 450, &fuhuo);
		for (i = 0; i < 55; i++)
		{
			putimage(100, 100, &lost[i]);
			EndBatchDraw();
			Sleep(30);
			ExMessage msg = { 0 };
			if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN)
			{
				if (msg.x > 100 && msg.x < 400 && msg.y>400 && msg.y < 450)
				{
					//printf("%d , %d\n", msg.x, msg.y);
					return case1 = 4;
					break;
				}
				else if (msg.x > 100 && msg.x < 400 && msg.y>450 && msg.y < 500)
				{
					if (case1==5)
					{
						return case1 = 5;
						break;
					}
					else if (case1 == 6)
					{
						return case1 = 6;
						break;
					}
					else if (case1 == 7)
					{
						return case1 = 7;
						break;
					}

				}
			}
			if (i == 54)i = 0;
		}
	}
}
//游戏失败界面
int MainPage()
{
	putimage(0, 0, &img);

	//fillrectangle(0, 60, 60,120);
//left:矩形左部 x 坐标。
//top : 矩形顶部 y 坐标。
//right : 矩形右部 x 坐标。
//bottom : 矩形底部 y 坐标。
	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");//高，宽
	settextcolor(RED);
	outtextxy(400, 179, "设置");//x 字符串输出时头字母的 x 轴的坐标值。
	//y 字符串输出时头字母的 y 轴的坐标值
	//setbkmode(TRANSPARENT);
	//settextstyle(30, 15, "幼圆");
	//settextcolor(WHITE);
	//outtextxy(0, 120, "名片");

	//setbkmode(TRANSPARENT);
	//settextstyle(30, 15, "幼圆");
	//settextcolor(WHITE);
	//outtextxy(380, 30, "排行榜");

	//setbkmode(TRANSPARENT);
	//settextstyle(65, 40, "幼圆");
	//settextcolor(RED);
	//outtextxy(75, 200, "狼了个狼");

	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");
	settextcolor(RED);
	outtextxy(264, 474, "开始游戏");

	//setbkmode(TRANSPARENT);
	//settextstyle(40, 20, "幼圆");
	//settextcolor(WHITE);
	//outtextxy(150, 450, "继续游戏");

	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");
	settextcolor(RED);
	outtextxy(264, 578, "退出游戏");//可以更改字体

	while (1)
	{

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				printf("坐标（%d,%d）\n", msg.x, msg.y);

				if (msg.x >= 0 && msg.x <= 60 && msg.y >= 120 && msg.y <= 150)

				{
					return 0;
					break;
				}
				//开始游戏
				else if (msg.x >= 125 && msg.x <= 435 && msg.y >= 343 && msg.y <= 493)
				{
					return case1=4;
					break;
					//继续游戏
				}
				else if (msg.x >= 122 && msg.x <= 340 && msg.y >= 540 && msg.y <= 595)
				{
					return case1 = 3;
					break;//退出游戏
				}
				else if (msg.x >= 343 && msg.x <= 455 && msg.y >= 66 && msg.y <= 170)
				{
					return case1 = 2;
					break;//设置
				}
			}
		}
	}
}
	//主界面
int SetPage()
{
	putimage(0, 0, &img2);

	//setbkmode(TRANSPARENT);
	//settextstyle(50, 25, "幼圆");
	//settextcolor(RED);
	//outtextxy(60, 230, "音乐");

	//setbkmode(TRANSPARENT);
	//settextstyle(50, 25, "幼圆");
	//settextcolor(RED);
	//outtextxy(60, 400, "音效");

	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");
	settextcolor(RED);
	outtextxy(280, 405, "音乐开");

	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");
	settextcolor(RED);
	outtextxy(281, 575, "音乐关");

	//setbkmode(TRANSPARENT);
	//settextstyle(50, 25, "幼圆");
	//settextcolor(RED);
	//outtextxy(220, 400, "开");

	//setbkmode(TRANSPARENT);
	//settextstyle(50, 25, "幼圆");
	//settextcolor(RED);
	//outtextxy(320, 400, "关");

	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");
	settextcolor(RED);
	outtextxy(380, 220, "退出设置");

	while (1)
	{

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				printf("坐标（%d,%d）\n", msg.x, msg.y);

				if (msg.x >= 124 && msg.x <= 341 && msg.y >= 370 && msg.y <= 419)

				{
					PlayMsc();
					return case1=2;
					break;
				}
				//音乐开
				else if (msg.x >= 123 && msg.x <= 342 && msg.y >= 537 && msg.y <= 589)

				{
					CloseMsc();
					return case1=2;
					break;
				}
				//音乐关
				else if (msg.x >= 331 && msg.x <= 446 && msg.y >= 109 && msg.y <= 213)
				{
					return case1=1;
					break;
					//退出设置
				}
			}
		}
	}
}
	//设置界面
int BreakGame()
{
	int is_ok = MessageBox(hnd, "真的忍心拒绝可爱的小狼灵吗？QMQ", "提示", MB_OKCANCEL);
	if (is_ok == IDOK)
	{
		exit(0);
	}
	else if (is_ok == IDCANCEL)
	{
		return case1 = 1; 
	}
}
	//退出游戏窗口显示
int ModePage()				//打印选择页面
{

	//initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	putimage(0, 0, &modepage);					//背景
	//putimage(20, 40, &img4);				//设置

	//打印字体
	setbkmode(TRANSPARENT);
	settextstyle(18, 10, "楷体");//高，宽
	settextcolor(RED);
	outtextxy(400, 150, "设置");//设置
	settextstyle(23, 12, "楷体");
	outtextxy(355 - textwidth(Easy), 317-textheight(Easy), Easy);
	outtextxy(355 - textwidth(Norm), 444 - textheight(Norm), Norm);
	outtextxy(355 - textwidth(Diff), 579 - textheight(Diff), Diff);

	//打印矩形
	//roundrect(WIDTH / 2 - textwidth(Easy) / 2, HEIGHT / 5, WIDTH / 2 + textwidth(Easy) / 2, HEIGHT / 5 + textheight(Easy), 5, 5);
	//roundrect(WIDTH / 2 - textwidth(Easy) / 2, HEIGHT / 5 * 2, WIDTH / 2 + textwidth(Easy) / 2, HEIGHT / 5 * 2 + textheight(Easy), 5, 5);
	//roundrect(WIDTH / 2 - textwidth(Easy) / 2, HEIGHT / 5 * 3, WIDTH / 2 + textwidth(Easy) / 2, HEIGHT / 5 * 3 + textheight(Easy), 5, 5);

	EndBatchDraw();
	while (1) {
		
		
		//getmessage(&press, EX_MOUSE);
		if (MouseHit()) 
		{
			//接受鼠标信息
			MOUSEMSG press= GetMouseMsg();
			switch (press.uMsg)
			{
			case WM_LBUTTONDOWN:
				printf("坐标（%d,%d）\n", press.x, press.y);
				//easy板块
				//printf("坐标（%d,%d）\n", press.x, press.y);
				if ((press.x > 110) && (press.x < 355) && (press.y > 256) && (press.y < 317))
				{
					return case1 = 5;
					break;
				}
				//norm板块
				else if ((press.x >110 ) && (press.x < 355) && (press.y >385 ) && (press.y <444 ))
				{
					return case1 = 6;
					break;
				}
				//diff板块
				else if ((press.x > 110) && (press.x < 355) && (press.y > 520) && (press.y < 580))
				{
					return case1 = 7;
					break;
				}
				//setting板块
				else if ((press.x > 304) && (press.x < 420) && (press.y > 54) && (press.y < 158))

				{
					return case1 = 2;
					break;
				}

			}
		}
	}
	return 0;
}
	//模式选择界面
int SimpleMode()
{
	//放数字
	srand(time(0));
	int size[NUM][NUM] = { 0 };
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			size[i][j] = i + 1;
		}
	}

	//随机交换数字
	int exch = 0;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0, a, b; j <= 5; j++) {
			exch = size[a = rand() % NUM][b = rand() % NUM];
			size[a][b] = size[i][j];
			size[i][j] = exch;
		}
	}

	int put_X = (WIDTH - (NUM * 56 + (NUM - 1) * INTERVAL)) / 2;
	int put_Y = ((HEIGHT+100 - 200) - (NUM * 56 + (NUM - 1) * INTERVAL)) / 2;
	int store[7] = { 0 }, map[7] = { 0 };

	while (true)
	{
		BeginBatchDraw();
		putimage(0, 0, &playbk);
		//putimage(20, 40, &img4);//设置
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < NUM; j++)
			{
				if (size[i][j])
				{
					putimage(put_X + 56 * i + INTERVAL * i, put_Y + 56 * j + INTERVAL * j, img1 + (size[i][j] - 1));
				}
			}
		}
		int a = 0;
		for (int i = 0; i < 7; i++)
		{
			if (store[i]) {
				putimage((a * 60) + 25, 635, img1 + (store[i] - 1));
				a++;
			}
		}

		EndBatchDraw();
		for (int i = 0; i < 7; i++) {
			map[i] = store[i];
		}
		for (int i = 0, a = 0; i < 7; i++) {
			if (map[i]) {
				store[i] = 0;
				store[a] = map[i];
				a++;
			}
		}
		//卡槽重排

		ExMessage clk = { 0 };
		clk = getmessage(EX_MOUSE);
		if (clk.message == WM_LBUTTONDOWN)
		{	
			printf("%d %d\n", clk.x, clk.y);
			for (int i = 0; i < NUM; i++)
			{
				for (int j = 0; j < NUM; j++)
				{
					//遍历是数组内所有图片的坐标
					int x = put_X + 56 * i + INTERVAL * i;
					int y = put_Y + 56 * j + INTERVAL * j;
					if (clk.x >= x && clk.x <= x + 56 && clk.y >= y && clk.y <= y + 56)
					{
						//如果点击的是图片的范围的话
						int col = (clk.x - put_X) / (56 + INTERVAL);
						int row = (clk.y - put_Y) / (56 + INTERVAL);

						for (int i = 0; i < 7; i++)
						{
							if (store[i] == 0)
							{
								store[i] = size[col][row];
								break;
							}
						}
						int cnt = 0;
						for (int i = 0; i < 7; i++)
						{
							if (store[i] == size[col][row])
							{
								cnt++;
							}
						}
						if (cnt == 3)
						{
							for (int i = 0; i < 7; i++)
							{
								if (store[i] == size[col][row])
								{
									store[i] = 0;
								}
							}
						}
						size[col][row] = 0;
					}
					//setting板块
					else if ((clk.x > 266) && (clk.x < 339) && (clk.y > 40) && (clk.y < 106))

					{
						SetPage();
						break;
					}
					else if ((clk.x > 363) && (clk.x < 455) && (clk.y > 44) && (clk.y < 108))
					{
						return case1 =4 ;
						break;
					}
				}
			}
			if (store[6] > 0)
			{
				LostGame();
				break;
			};//失败


			int cnt2 = 0;
			for (int i = 0; i < NUM; i++)
			{
				for (int j = 0; j < NUM; j++)
				{
					if (size[i][j] == 0)
					{
						cnt2++;
					}
				}
			}
			if (cnt2 == 36)
			{
				//cleardevice();
				WinGame();
				break;
			}
		}
	}
	return NULL;
}
	//简单模式界面
int GeneralMode()
{
	int offsetX = (WIDTH - (5.1 * (PCTSIZE + INTERVAL) + PCTSIZE)) / 2;//卡牌左上角X坐标
	int offsetY = (HEIGHT - (7 * (PCTSIZE + INTERVAL) + PCTSIZE)) / 2;
	int const tool1X = 10;//工具1的坐标
	int const tool1Y = 500;
	//卡槽区
	int store[7] = { 0 };
	int map1[7] = {0};
	//卡牌区
	int tool1[NUM][NUM] = {0};
	int col1 = 0, row1 = 0,i1=0;
	int map[NUM][NUM] = { 0 };
	//打乱卡牌
	random(map);

	while (1)
	{
		/******************* 绘制背景、卡槽、卡牌 ********************/
		//函数BeginBatchDraw()用于开始批量绘图。（双缓冲机制）
		BeginBatchDraw();
		cleardevice();
		//绘制背景、卡槽图片
		putimage(0, 0, &playbk23);//background
		//putimage(10, 580, &imgbolt);//slop
		//putimage(198, 535, &shuaxin);
		//putimage(298, 535, &yichu);
		//putimage(407, 20, &chehui);
		//putimage(20, 40, &img4);//设置

		//绘制、渲染卡牌区
		for (int r = 0; r < NUM; r++)
		{
			for (int c = 0; c < NUM; c++)
			{
				//渲染卡牌区
				if (map[r][c])
					putimage(offsetX + c * (PCTSIZE + INTERVAL), offsetY + r * (PCTSIZE + INTERVAL), img1 + (map[r][c] - 1));
			}
		}

		////渲染放入卡槽区的卡牌
		//for (int i = 0; i < 7; i++)
		//{
		//	;
		//	if (store[i])
		//		putimage((i * 60) + 26, 630, img1 + (store[i] - 1));
		//}

		////函数EndBatchDraw()用于结束批量绘制，并执行未完成的绘制任务。
		//EndBatchDraw();
		int a = 0;
		for (int i = 0; i < 7; i++)
		{
			if (store[i]) {
				putimage((a * 60) + 25, 635, img1 + (store[i] - 1));
				a++;
			}
		}

		EndBatchDraw();
		for (int i = 0; i < 7; i++) {
			map1[i] = store[i];
		}
		for (int i = 0, a = 0; i < 7; i++) {
			if (map[i]) {
				store[i] = 0;
				store[a] = map1[i];
				a++;
			}
		}
		//卡槽重排

		//ExMessage这个结构体用于保存鼠标消息
		ExMessage msg = { 0 };

		//函数peekmessage()用于获取一个消息，并立即返回。
		if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN)//点击鼠标 且 消息是左键
		{
			printf("坐标是=%d  =%d\n", msg.x, msg.y);
			for (int r = 0; r < NUM; r++)
			{
				for (int c = 0; c < NUM; c++)
				{
					//鼠标坐标x
					int x = offsetX + c * (PCTSIZE + INTERVAL);
					//鼠标坐标y
					int y = offsetY + r * (PCTSIZE + INTERVAL);

					/******************* 卡牌相关操作 ********************/
					//判断鼠标是否点击了卡牌
					if (msg.x > x && msg.x < x + PCTSIZE && msg.y>y && msg.y < y + PCTSIZE)//判断是否点击
					{
						//求出点击的卡牌对应的数组下标
						int col = (msg.x - offsetX) / (PCTSIZE + INTERVAL);
						int row = (msg.y - offsetY) / (PCTSIZE + INTERVAL);
						
						//把点击的卡牌添加到卡槽
						for (int i = 0; i < 7; i++)
						{
							if (store[i] == 0)
							{
								store[i] = map[row][col];
								tool1[row][col] = store[i];
								row1 = row;
								col1 = col;
								i1 = i;//记录横纵坐标以及值
								break;
							}
							/*if (map[row][col])
							{
								putimage(row, col, img1 + (map[r][c] - 1));
							}*/
						}

						/******************* 卡牌消除功能 ********************/
						//如果卡槽有三个一样的就消除
						int cnt = 0;
						for (int i = 0; i < 7; i++)
						{
							if (store[i] == map[row][col])
							{
								cnt++;
							}
						}
						if (cnt == 3)
						{
							for (int i = 0; i < 7; i++)
							{
								if (store[i] == map[row][col])
								{
									store[i] = 0;
								}
							}
						}
						//把点击的卡牌从卡牌区中删除
						map[row][col] = 0;
					}
					else if ((msg.x > 266) && (msg.x < 339) && (msg.y > 41) && (msg.y < 106))

					{
						SetPage();
						//return case1 = 4;
						break;
					}//进入设置
					else if ((msg.x > 363) && (msg.x < 455) && (msg.y > 44) && (msg.y < 108))

					{
						//SetPage();
						return case1 = 4;
						break;
					}//回退到模式选择
					else if ((msg.x > 304) && (msg.x < 357) && (msg.y > 559) && (msg.y < 611))

					{
						//SetPage();
						shuffle2(map);
						//, tool1, & row1, & col1

						break;
					}//重排
					else if ((msg.x > 385) && (msg.x < 439) && (msg.y > 561) && (msg.y < 611))

					{
						if (store[0] > 0)
						{
							map[row1][col1] = tool1[row1][col1];
							store[i1] = 0;
							break;
						}
					}//撤回
					

				}
			}

			/******************* 道具使用********************/


			/******************* 失败、成功界面跳转 ********************/
			//卡槽满了游戏失败 即数组的最后一个区域不存放0	
			if (store[6])
			{
				LostGame();
				break;
			}
			//卡牌区空了游戏成功 
			if (allEmpty(map))
			{	
				cleardevice();
				
				WinGame();
				break;
			}
		}
		
	}
	return NULL;
}
	//中等模式游戏界面
int HardMode()
{
	fuzhi(size1);
	Array(size1, size2, size3);
	//这个是放置的初始位置
	//这行是卡槽
	int store[7] = { 0 };
	int tool3[6][6] = {0};
	int box3[3] = { 0 };
	int pctcnt = 0;//图片消除次数计数器
	int put_X = (WIDTH - (NUM * 56 + (NUM - 1) * INTERVAL)) / 2;
	int put_Y = ((HEIGHT - 100) - (NUM * 56 + (NUM - 1) * INTERVAL)) / 2;
	//这行是输出图片到规定位置

	
		
	//这行实现数组的存储
		/*for (int i = 0; i < 7; i++)
		{
			store[i] = 1;
			if (store[i])
				putimage((i * 50) + 26, 635, img1 + (store[i] - 1));
		}*/
	int brige = 0, brige2 = 0, brige3 = 0, brige4 = 0;
	
		while (1)
		{

			
			//cleardevice();
			putimage(0, 0, &playbk23);
			//putimage(20, 10, &img4);				//设置
			//putimage(198, 535, &shuaxin);
			//putimage(298, 535, &yichu);
			//putimage(98, 535, &chehui);
			BeginBatchDraw();
			for (int i = 0; i < NUM; i++)
			{
				for (int j = 0; j < NUM; j++)
				{
					putimage(put_X + PCTSIZE * i + INTERVAL * i, put_Y + PCTSIZE * j + INTERVAL * j, img1 + (size1[i][j] - 1));
				}
			}
			for (int i = 0; i < 7; i++)
			{
				if (store[i]>0)
					putimage((i * 50) + 26, 635, img1 + (store[i] - 1));
			}
			/*for (int i = 0; i < 3; i++)
			{
				if (tool3[i] > 0)
					putimage((i * 50) + 26, 430, img1 + (tool3[i] - 1));
			}*/
			//FlushBatchDraw();
			//peekmessage(&clk, EX_MOUSE);
			EndBatchDraw();
			//printf("x=%d y=%d\n", clk.x, clk.y);
			ExMessage clk = { 0 };

			if (peekmessage(&clk) && clk.message == WM_LBUTTONDOWN)
			{
				
				for (int i = 0; i < NUM; i++)
				{	
					
					for (int j = 0; j < NUM; j++)
					{	
						int x = put_X + (PCTSIZE + INTERVAL) * i;
						int y = put_Y + (PCTSIZE + INTERVAL) * j;
						int toolx=26+ (PCTSIZE + INTERVAL) * i;
						int tooly = 575;
						printf("%d %d \n", clk.x, clk.y);
						
						if (clk.x >= x && clk.x <= x + PCTSIZE && clk.y >= y && clk.y <= y + PCTSIZE)
						{
							
							int col = (clk.x - put_X) / (PCTSIZE + INTERVAL);
							int row = (clk.y - put_Y) / (PCTSIZE + INTERVAL);
							//遍历size1里面的所有元素，赋值给卡槽
							//并当找到的元素下面的两个元素都不为0时，咱可以赋值给它


							
							for (int i = 0; i < 7; i++)
							{
								if (store[i] == 0)
								{
									brige4 = i;//卡槽的记号位置
									if (size1[col][row] != 0)
										store[i] = size1[col][row];
									brige = store[i];//把牌的值保存起来
									brige2 = col;//牌的横坐标
									brige3 = row;//牌的纵坐标
									tool3[col][row] = size1[col][row];
									pctcnt++;
									printf("brige4=%d %d\n", brige2, brige3);
									
									break;
								}
							}
							int cnt = 0;//卡槽计数器

							for (int i = 0; i < 7; i++)
							{
								if (store[i] == size1[col][row])
									cnt++;
							}
							if (cnt == 3)
							{
								for (int i = 0; i < 7; i++)
								{
									if (store[i] == size1[col][row])
									{
										store[i] = 0;
										
									}
								}
								//clilk();
							}
							size1[col][row] = 0;
							//pctcnt = 9;
							pctcnt = ArrayAssignment(col, row, &pctcnt);


						}
						else if ((clk.x > 266) && (clk.x < 339) && (clk.y > 41) && (clk.y < 106))
						{
							SetPage();
							break;
						}//设置
						else if ((clk.x > 363) && (clk.x < 455) && (clk.y > 44) && (clk.y < 108))
						{
							return case1 = 4;
							break;
						}//返回
						else if (clk.x > 304 && clk.x < 357 && clk.y>559 && clk.y < 611)

						{//点击在道具区 的重排 
							shuffle2(size1);
							//,tool3,&brige2,&brige3
							break;
						}
						else if (clk.x > 385 && clk.x < 439 && clk.y>561 && clk.y < 611)
						{//撤回
							store[brige4] = 0;
							size1[brige2][brige3] = tool3[brige2][brige3];
							break;
						}
						//else if (clk.x > 98 && clk.x < 98 + PCTSIZE && clk.y>535 && clk.y < 535 + PCTSIZE)
						//{//移出的功能没有实现了  所以注释掉了
						//	int j = 0;
						//	break;
						//	for (int i = 3; i >= 0; i--)
						//	{
						//		if (j == 3)
						//		{
						//			j = 0;
						//			break;
						//		}
						//		if (store[i])
						//		{		
						//			tool3[j] = store[i];
						//			store[i] = 0;
						//			printf("tool3=    %d| %d\n", tool3[j] ,j);
						//			j++;
						//			
						//		}
						//	}

						//}
						
					}
				}
				
			}
			EndBatchDraw();
		
			if (store[6] > 0)
			{
				LostGame();
				break;

			}//lost
			else if (WinGame(size1, size2, size3, store) == 0)
			{
				WinGame();
				break;
			}//win
		}
		return NULL;
	}
	//困难模式游戏界面
void PlayBgm()
{
	//mciSendString("open ./music/beijing.mp3 ", 0, 0, 0);
	//mciSendString("play ./music/beijing.mp3 repeat", 0, 0, 0);
}
	//放音乐


	int main()
	{	
		PlayBgm();
		SetWindowText(hnd, "狼了个狼");//修改窗口名字
		initgraph(WIDTH, HEIGHT,SHOWCONSOLE);
		Loadpicture();
		while (1)
		{
			switch (case1)
			{
			case 1:MainPage();break;
			case 2:SetPage(); break;
			case 3:BreakGame(); break;
			case 4:ModePage(); break;
			case 5:SimpleMode(); break;
			case 6:GeneralMode(); break;
			case 7:HardMode(); break;
			}
		}

		while (1);
	}
	//函数的声明放在前面
