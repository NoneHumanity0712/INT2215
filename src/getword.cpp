#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> words;

int main()
{
    ifstream fin("words.txt");
    if (fin.is_open()) 
    {
        string line;
        while (getline(fin, line))
        {
            words.push_back(line);
        }
        fin.close();
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
    return 0;
}