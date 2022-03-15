#include <iostream>

using namespace std;

//dangling references 1
// int* weird_sum(int a, int b)
// {
//     int c;
//     c = a + b;
//     return &c;
// }

int main(int argc, const char *argv[])
{
    //lỗi con trỏ chưa khởi tạo
    // int *pX;
    // printf("%d\n", pX);
    // printf("%d\n", *pX);
    // *pX = 0;

    //lỗi truy nhập con trỏ NULL
    // int *pX = NULL;
    // printf("%d\n", pX);
    // printf("%d\n", *pX);
    // *pX = 0;

    //dangling references 2
    // int a = 20; b = 25, *pG;
    // {
    //     int g;
    //     pG = &g;
    //     g = gcd (a, b);
    // }
    // {
    //     int temp = 100;
    //     printf("temp is %d\n", temp);
    // }
    // printf("GCD(%d,%d)=%d\n", a, b, *pG);

    //dangling references 3
    // {
    //     int temp1;
    //     printf("%d\n", &temp1);
    // }
    // {
    //     int temp2;
    //     printf("%d\n", &temp2);
    // }

    //đổi kiểu
    // char a = 'a';
    // char* p1 = &a;
    // int* p2 = (int*) p1;
    // *p2 = 'b';
    
    return 0;
}