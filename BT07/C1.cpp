/*
1.	Viết hàm mô phỏng quá trình đổ 1 quân xúc xắc (trả về giá trị trong khoảng từ 1-6),
Sử dụng hàm đổ xúc xắc trên viết chương trình mô phỏng trò chơi sau: 
Hai người chơi, lần lượt đổ 1 xúc xắc, tổng điểm được cộng gộp vào cho mỗi người chơi. 
Ai có tổng điểm BẰNG 100 trước là thắng. Đổi lượt đổ xúc xắc cho người chơi kia theo 2 cách:
	A. Mỗi người chơi lần lượt đổ xúc xắc.
	B. Người có tổng điểm nhỏ hơn sẽ được đổ xúc xắc.
*/

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