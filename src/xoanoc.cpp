/*
Viết chương trình nhập từ bàn phím một cặp số m,n nguyên dương nhỏ hơn 10 
và in ra màn hình một bảng m dòng n cột chứa các giá trị từ 1 đến m∗n theo dạng xoắn ốc.
*/

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    int column = m, row =  n;
    int val = 1, p = 0;

    while (val <= m*n)
    {
        for (int i = p; i < row; i++) a[p][i] = val++;
        for (int i = p+1; i < column; i++) a[i][row - 1] = val++;
        if (p != column - 1)
        {
            for (int i = row - 2; i >= p; i--) a[column - 1][i] = val++;
        }
        if (p != row - 1)
        {
            for (int i = column - 2; i > p; i--) a[i][p] = val++;
        }
        p++;
        column--;
        row--;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}