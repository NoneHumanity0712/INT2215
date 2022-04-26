

void binary(int n, string s)
{
    char set[] = {'0', '1'};
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    
    for (int i = 0; i < 2; i++)
    {
        string binary_s;
        binary_s = s + set[i];
        
        binary(binary_s, n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    binary(n, s);
}