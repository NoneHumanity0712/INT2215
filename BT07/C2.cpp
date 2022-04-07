#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void move_turtle(int &turtle)
{
    int move = rand()%10 + 1;
    if (move == 1 || move == 2 || move == 3 || move == 4 || move == 5)
    {
        turtle += 3;
        cout << "Rua tien dai. Vi tri hien tai la: " << turtle;
    } else if (move == 6 || move == 7 || move == 8)
    {
        turtle += 1;
        cout << "Rua tien ngan. Vi tri hien tai la: " << turtle;
    } else
    {
        turtle -= 6;
        cout << "Rua truot. Vi tri hien tai la: " << turtle;
    }
    cout << endl;
}

void move_rabbit(int &rabbit)
{
    int move = rand()%10 + 1;
    if (move == 1 || move == 2)
    {
        cout << "Tho ngu. Vi tri hien tai la: " << rabbit;
    } else if (move == 3 || move == 4)
    {
        rabbit += 9;
        cout << "Tho tien dai. Vi tri hien tai la: " << rabbit;
    } else if (move == 5)
    {
        rabbit -= 12;
        cout << "Tho truot dai. Vi tri hien tai la: " << rabbit;
    } else if (move == 6 || move == 7 || move == 8)
    {
        rabbit += 1;
        cout << "Tho truot dai. Vi tri hien tai la: " << rabbit;
    } else
    {
        rabbit -= 2;
        cout << "Tho truot ngan. Vi tri hien tai la: " << rabbit;
    }
    cout << endl;
}

int main()
{
    int turtle = 0;
    int rabbit = 0;

    srand(time(0));
    cout << "Cuoc dua bat dau!!!" << endl;
    cout << endl;
    while (turtle < 70 && rabbit < 70)
    {
        move_turtle(turtle);
        move_rabbit(rabbit);
        
        if (turtle < 0) turtle = 0; 
        if (rabbit < 0) rabbit = 0;
        if (turtle >= 70) 
        {
            cout << endl;
            cout << "Cuoc dua ket thuc!" << endl;
            cout << "Rua da chien thang o vi tri " << turtle << endl;
            cout << "Tho dang o vi tri " << rabbit << endl;
            break;
        }
        else if (rabbit >= 70)
        {
            cout << endl;
            cout << "Cuoc dua ket thuc!" << endl;
            cout << "Tho da chien thang o vi tri " << rabbit << endl;
            cout << "Rua dang o vi tri " << turtle << endl;
            break;
        }
    }
    return 0;
}