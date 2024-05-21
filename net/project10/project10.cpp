#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
const double THRESHOLD = 1.5;
double power_p(double power[], int length, int n);
int main() {
	string filename;
	ifstream fin;
	int num=0,short_window=0,long_window=0;
	double time_incre=0;
	double short_power=0, long_power=0;
	double* session=NULL;
	cout << "Enter name  of input" << endl;
	cin >> filename;
	fin.open(filename.c_str());
	if (fin.fail()) {
		cerr << "error opening input file" << endl;
		exit(0);
	}
	else {
		fin >> num >> time_incre;
		cout << "num:" << num << " " << "time_incre:" << time_incre << endl;
		if (num >= 0) {
			session = new double[num];
			for (int i = 0; i < num; i++) {
				fin >> session[i];
			}
			cerr << "Enter number of points for-short window" << endl;
			cin >> short_window;
			cerr << "Enter number of points for - long window"<<endl;
			cin >> long_window;
			for (int i = long_window - 1; i <num; i++) {
				short_power = power_p(session, i, short_window);
				long_power = power_p(session, i, long_window);
				double radio = short_power / long_power;
				if (radio > THRESHOLD) {
					cout << "possible event at" << time_incre * i << "second/s"<<endl;
				}
			}
			delete[]session;
		}
		fin.close();
	}
	system("pause");
}
double power_p(double power[], int length, int n) {
	double x_square = 0;
	for (int i = 0; i <n; i++) {
		x_square += pow(power[length] - i, 2);
	}
	return x_square/n;
}