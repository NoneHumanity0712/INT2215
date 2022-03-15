#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int rand_val()
{
    return rand() % 6 + 1;
}

void A(int one, int two)
{
    int count = 0;
    while (one != 100 && two != 100)
    {
        count++;
        int value = rand_val();
        if (count%2 != 0)
        {
            one += value;
            cout << "Player 1 has rolled a dice of " << value << ". Player 1 has of total of " << one << endl;
        } else 
        {
            two += value;
            cout << "Player 2 has rolled a dice of " << value << ". Player 2 has of total of " << two << endl;
        }
        if (one == 100) cout << "The winner is player 1!";
        else if (two == 100) cout << "The winner is player 2!";
        else if (one > 100 && two > 100)
        {
            cout << "No one won!";
            break;
        }
    }
}

void B(int one, int two)
{
    int prev = 2;
    while (one != 100 && two != 100)
    {
        int value = rand_val();
        if (one < two || (one == two && prev == 2))
        {
            prev = 1;
            one += value;
            cout << "Player 1 has rolled a dice of " << value << ". Player 1 has of total of " << one << endl;
        } else if (two < one || (one == two && prev == 1))
        {
            prev = 2;
            two += value;
            cout << "Player 2 has rolled a dice of " << value << ". Player 2 has of total of " << two << endl;
        }
        if (one == 100) cout << "The winner is player 1!";
        else if (two == 100) cout << "The winner is player 2!";
        else if (one > 100 && two > 100)
        {
            cout << "No one won!";
            break;
        }
    }
}

int main()
{
    int one = 0;
    int two = 0;

    srand(time(0));
    // A(one, two);
    B(one, two);
    return 0;
}