#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

int LCS(string s, string t)
{
    int f[MAX][MAX];
    //f[i][j]: do dai day con chung max cua s[0 ... i-1] voi t[0 ... j-1]
    int M = s.length();
    int N = t.length();

    for (int i = 0; i <= M; i++) f[i][0] = 0;
    for (int j = 0; j <= N; j++) f[0][j] = 0;

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (s[i] == t[j]) f[i][j] = 1 + f[i-1][j-1];
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    return f[M-1][N-1];
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;


}