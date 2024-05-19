#include <iostream>
#include<fstream>
#include<string>
#include<assert.h>
#include<Windows.h>
#define cols 256
using namespace std;
bool isvalley(int a[cols][cols], int r, int c) {
	assert(r >= 0 && r < cols);
	assert(c >= 0 && c < cols);
	if ((a[r][c] < a[r - 1][c]) && (a[r][c] < a[r + 1][c] )&& (a[r][c] < a[r][c - 1] )&& (a[r][c] < a[r][c + 1] )) {
		return true;
	}
	return false;
}
void extremes(const int a[][cols], int r, int c) {
	int max = a[0][0];
	int min = a[0][0];
	int pos[2][2] = { 0 };
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (max < a[i][j]) {
				max = a[i][j];
				pos[0][0] = i;
				pos[0][1] = j;
			}
			if (min > a[i][j]) {
				min = a[i][j];
				pos[1][0] = i;
				pos[1][1] = j;
			}
		}
	}
	cout << "最大值为" << max << endl; ;
	printf("位置为%d %d", pos[0][0], pos[0][1]);
	cout << "最小值为" << min << endl;
	printf("位置为%d %d", pos[1][0], pos[1][1]);
}
bool ispeak(int a[cols][cols], int r, int c) {
	assert(r>=0&&r<cols);
	assert(c >= 0 && c < cols);
	if ((a[r][c] > a[r - 1][c]) && (a[r][c] > a[r + 1][c]) && (a[r][c] > a[r][c - 1]) && (a[r][c] > a[r][c + 1])&&(a[r][c]>a[r-1][c-1])&&(a[r][c]>a[r+1][c+1])&&(a[r][c]>a[r+1][c-1])&&(a[r][c]>a[r-1][c+1])) {
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
	int total_peaks = 0;
	for (int i = 0; i < nrows; ++i) {
		for (int j = 0; j < ncols; ++j) {
			file >> map[i][j];
			if (ispeak(map, i, j)) {
				cout << "峰点出现在:" << i<< "行" << j << "列" << endl;
				total_peaks++;

			}else if (isvalley(map, i, j)) {
				cout << "谷点出现在:" << i <<"行"  << j <<"列" << endl;
			}
		}
	}
	extremes(map, nrows, ncols);
	printf("有%d个峰点\n", total_peaks);
	system("pause");
	file.close();
}


