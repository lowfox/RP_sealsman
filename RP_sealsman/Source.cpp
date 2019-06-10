#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Header.h"

#define CITY_NUM 64
#define LINE_GROUPS 5//一列、一行内のグループの個数。

int main(void) {
	CITY city[CITY_NUM];

	int gr[LINE_GROUPS*LINE_GROUPS];
	memset(gr, 0, sizeof(gr));

	srand((unsigned)time(NULL));


	/*
	city[i].x = (float)(rand() % 100000);
	city[i].x = city[i].x / 100000.0f;
	printf("_x=%f", city[i].x);
	num_x = (float)(rand() % 100);
	city[i].x += num_x;//丸め誤差が生じる

	city[i].y = (float)(rand() % 100000);
	city[i].y = city[i].y / 100000.0f;
	printf("		_y=%f", city[i].y);
	num_y = (float)(rand() % 100);
	city[i].y += num_y;//丸め誤差が生じる
	*/

	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	double aa = 0;

	//ランダムで座標を生成

	for (int i = 0; i < CITY_NUM; i++) {
		city[i].x = 0;
		city[i].y = 0;
		a1 = rand() % 10000;
		a2 = rand() % 1000;
		a3 = a1 * a2;
		aa = (double)a3;
		//printf("aa=%lf	", aa);
		city[i].x = aa / 100000.0f;

		a1 = rand() % 10000;
		a2 = rand() % 1000;
		a3 = a1 * a2;
		aa = (double)a3;
		//printf("aa=%lf	", aa);
		city[i].y = aa / 100000.0f;

		printf("x=%lf	y=%lf\n", city[i].x,city[i].y);
	}
	

	//グループ分けして分布を把握する。
	int bucket = 0;
	//memset(bucket, 0, sizeof(bucket));
	for (int y = 0; y < LINE_GROUPS; y++) {
		for (int x = 0; x < LINE_GROUPS; x++) {
			for (int i = 0; i < CITY_NUM; i++) {
				if ((city[i].x >= (x * 100/LINE_GROUPS) && (city[i].x < (x+1)*100/LINE_GROUPS)) &&
					((city[i].y >= (y * 100 / LINE_GROUPS))&& (city[i].y < (y+1)*100/LINE_GROUPS))) {
					gr[x + (y * LINE_GROUPS)] += 1;			
				} 
			}
		}
	}

	for (int i = 0; i < LINE_GROUPS*LINE_GROUPS; i++) {
		printf("gr[%d]=%d\n", i, gr[i]);
	}


	getchar();
	return 0;
}