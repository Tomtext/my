#include <iostream>
#include<iomanip>
using namespace std;
#define N 10
int main()
{
    int a[N][N] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <=i; j++) {
            if (i == j || j== 0) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int k = 2* (N - i);
        cout << setw(k)  << a[i][0];
        for (int j = 1; j <= i; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

