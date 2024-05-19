#include<iostream>
#include <Windows.h>
#include<mmsystem.h>
#include<graphics.h>
#include<string.h>
#include<string>
#include<stdio.h>
#define count 148
#pragma comment(lib,"winmm.lib")
using namespace std;
int main() {
	char filename[128];
	
	IMAGE images[count];
	while (1) {
		for (int i = 1; i <= 148; i++) {
			sprintf(filename, "C:\\Users\\30352\\Desktop\\images2\\_%04d_Í¼²ã-%d.jpg", count - i, i);
			loadimage(&images[i - 1], filename);
		}
		
	}
	initgraph(800, 513);
	mciSendString(_T("play ¹Â¶ÀµÄµº.mp3 repeat"), 0, 0, 0);
	while (1) {
		for (int i = 0; i < count; i++) {
			putimage(0, 0, &images[i - 1]);
			Sleep(75);
		}
	}
	system("pause");
	closegraph();
	return 0;
}