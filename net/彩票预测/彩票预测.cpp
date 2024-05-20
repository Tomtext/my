#include<iostream>
#include<fstream>
#include<string>
#define N 7
using namespace std;
bool statistics(const char* path, int ball_16[33]);
int main() {
	string filename;
	int ball_16[33] = { 0 };
	cout << "请输入文件名：" << endl;
	cin >> filename;
	if (statistics(filename.c_str(), ball_16)) {
		for (int i = 0; i < 33; ++i) {
			cout << "第" << i + 1 << "球出现次数：" << ball_16[i] << endl;
		}
	}
	else {
		cerr << "统计失败";
	}
}
bool statistics(const char* path, int ball_16[33]) {
	int result[N];
	ifstream file;
	int i = 0;
	if (!path) {
		cerr << "path is Null" << endl;
		return false;
	}
	file.open(path);
	if (file.fail()) {
		cerr << "文件名输入有误" << endl;
		return false;
	}
	do {
		i = 0;
		for (int i = 0; i < N; ++i) {
			file >> result[i];
			if (file.eof()) {
				break;
			}
			if (file.fail()) {
				cerr << "读取文件有误，原因" << endl;
				break;
			}
			if (i == 0)break;
			if (i < N) {
				cerr << "仅读到" << i << "个记录,预期读取七个" << endl;
				file.close();
				return false;
			}
			for (int i = 0; i < N; i++) {
				cout << " " << result[i];
			}
			cout << endl;
			for (int i = 0; i < N - 1; i++) {
				int index = *(result + i) - 1;
				if (index < 0 || index>7) {
					cerr << "数组越界" << endl;
				}
			}
		}
	} while (1);
	file.close();
	system("pause");
	return true;
}