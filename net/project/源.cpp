#include <string>
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
#define Width 40
#define height 15
void input(char pwd[],int size) {
	char c;
	int i = 0;
	while (1) {
		c = _getch();
		if (c == '\r') {
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		cout << '*';
	}
	cout << endl;
}
void login(void) {
	string name;
	char pwd[32];
	while (1) {
		int i = 0;
		system("cls");
		std::cout << "ÇëÊäÈëÕËºÅ£º";
		std::cin >> name;
		std::cout << "ÇëÊäÈëÃÜÂë£º";
		 input(pwd,sizeof(pwd));
	
		if (name == "54hk" && !strcmp(pwd,"123456")){
			break;

		}
		else {
			cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó!" << endl;
			system("pause");
		}
	}
}
void menuShow(void) {
	system("cls");
	std::cout << "1.ÍøÕ¾ 404 ¹¥»÷" << std::endl;
	std::cout << "2.ÍøÕ¾´Û¸Ä¹¥»÷" << std::endl;
	std::cout << "3.ÍøÕ¾¹¥»÷ÐÞ¸´" << std::endl;
	std::cout << "4.²é¿´¹¥»÷¼ÇÂ¼" << std::endl;
	std::cout << "5.ÍË³ö" << std::endl;
}
int menuChoise(void) {
	int n = 0;
	while (1) {
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "ÎÞÐ§ÊäÈë. ÇëÖØÐÂÊäÈë." << endl;
			system("pause");
		}
		else {
			break;
		}
	}
	return n;
}
void attack404(void) {
	system("cls");
	cout << "404 ¹¥»÷...";
	system("pause");
}
void siteEdit(void) {
	system("cls");
	cout << "ÍøÕ¾´Û¸Ä¹¥»÷...";
	system("pause");
}
void siteRepair(void) {
	system("cls");
	cout << "ÍøÕ¾ÐÞ¸´...";
	system("pause");
}
void attckRecord(void) {
	system("cls");
	cout << "²é¿´¹¥»÷¼ÇÂ¼";
	system("pause");
}
void init() {
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d,lines=%d",Width,height);
	system("mode con cols=40,lines=50");
}
int main(void) {
	login();
	while (1) {
		menuShow();
		int n = menuChoise();
		switch (n) {
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			siteRepair();
			break;
		case 4:
			attckRecord();
			break;
		case 5:
			//break;
			return 0;
		default:
			cout << "ÎÞÐ§ÊäÈë. ÇëÖØÐÂÊäÈë." << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}