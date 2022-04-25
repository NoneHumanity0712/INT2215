#include <iostream>

using namespace std;

const int postion[8][2] = 
{
    {1, 0}, //left
    {1, 1}, //upper left
    {0, 1}, //above
    {-1, 1}, //upper right
    {-1, 0}, //right
    {-1, -1}, //lower right
    {0, -1}, //below
    {1, -1}
};

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    char map[m][n];
    int mine_map[m][n];
    int check[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = -1;
            cin >> map[i][j];
            if (map[i][j] == 'M') mine_map[i][j] = -1;
            else mine_map[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mine_map[i][j] == -1)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (i + postion[k][0] >= 0 && i + postion[k][0] < m 
                        && j + postion[k][1] >= 0 && j + postion[k][1] < n
                        && mine_map[i + postion[k][0]][j + postion[k][1]] != -1)
                        mine_map[i+postion[k][0]][j+postion[k][1]]++;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (mine_map[x][y] == -1) 
        {
            cout << "YOU'RE DEAD!" << endl;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }

            break;
        } else
        {
            check[x][y] = 0;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << check[i][j] << " ";
                }
                cout << endl;
            }

        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (map[i][j] == '*') cout << "* ";
    //         else cout << mine_map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}