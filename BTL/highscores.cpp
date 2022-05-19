#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct player
{
    string name;
    double score;
};


int main()
{
    player newGamer;
    newGamer.score = 15500;
    newGamer.name = "NTPT";
    ifstream fin("highscores.txt");
    if (fin.is_open())
    {
        int n;
        fin >> n;
        if (n > 0)
        {
            player gamers[n];
            for (int i = 0; i < n; i++)
            {
                fin >> gamers[i].score;

                fin.ignore();
                string temp;
                getline(fin, temp);
                gamers[i].name = temp;
            }

            int index = n;

            for (int i = n - 1; i >= 0; i--)
            {
                if (newGamer.score > gamers[i].score)
                {
                    index--;
                } else break;
            }

            if (index < n)
            {
                for (int i = index; i < n; i++)
                {
                    player temp = newGamer;
                    newGamer = gamers[i];
                    gamers[i] = temp;
                }
            }
            ofstream fout("highscores.txt");
            cout << "HIGHSCORES" << endl;
            if (n + 1 < 5) fout << n + 1 << endl;
            else fout << 5 << endl;
            for (int i = 0; i < n; i++)
            {
                fout << gamers[i].score << endl << gamers[i].name << endl;
                cout << i+1 << " " << gamers[i].name << " " << gamers[i].score << endl;
            }
            if (n + 1 <= 5) 
            {
                fout << newGamer.score << endl << newGamer.name << endl;
                cout << n+1 << " " << newGamer.name << " " << newGamer.score << endl;
            }
        }
        else
        {
            ofstream fout("highscores.txt");
            fout << 1 << endl;
            fout << newGamer.score << endl << newGamer.name << endl;
            cout << "HIGHSCORES" << endl;
            cout << 1 << " " << newGamer.name << " " << newGamer.score << endl;
        }
        fin.close();
    }
    return 0;
}