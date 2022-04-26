#include <bits/stdc++.h>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) 
{
    for (int i = 0; i < d; i++)
    {
        vector<int>::iterator it;
        it = arr.begin();
        int temp = arr[0];
        arr.erase(it);
        arr.push_back(temp);
    }
    return arr;
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<int> result = rotateLeft(d, a);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    
    system("pause");
    return 0;
}