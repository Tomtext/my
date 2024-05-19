#include <iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#define cols 256
using namespace std;
bool ispeak(int a[cols][cols], int r, int c) {
	if ((a[r][c] > a[r - 1][c]) && (a[r][c] > a[r + 1][c] )&& (a[r][c] > a[r][c - 1]) && (a[r][c] > a[r][c + 1])) {
		return true;
	}
	return false;
}
int main()
{
	int nrows ,ncols;
	int map[cols][cols];
	string filename;
	ifstream file;
	cout << "请输入文件名：" ;
	cin >> filename;
	file.open(filename.c_str());
	if (file.fail()) {
		cout << "文件名不存在,出错了......" << endl;
		exit(1);
	}
	file >> nrows >> ncols;
	if (nrows > cols || ncols > cols) {
		cout << "网格太大,调整程序。" << endl;
		exit(1);
	}
	for (int i = 0; i < nrows; ++i) {
		for (int j = 0; j < ncols; ++j) {
			file >> map[i][j];
		}
	}
	for (int i = 0; i < nrows; ++i) {
		for (int j = 0; j < ncols; ++j) {
			file >> map[i][j];
			if (ispeak(map, i, j)) {
				cout << "峰点出现在行:" << i << "列:" << j << endl;
			}
		}
	}
	system("pause");
	file.close();
}


