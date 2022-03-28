#include <iostream>

using namespace std;

int main( )
{ 
   double a[5] = {1, 2, 3, 4}; 
   for (double *cp = a; (*cp) != '\0'; cp+=2) {
      cout << (void*) cp << " : " << (*cp) << endl;
   } 
   return 0;
}

/*
a)
    0x61fe14 : a
    0x61fe15 : b
    0x61fe16 : c
b)
    0x61fe00 : 1
    0x61fe04 : 2
    0x61fe08 : 3
    0x61fe0c : 4
    kich thuoc kieu int: 4 bytes
c) 
    0x61fdf0 : 1
    0x61fdf8 : 2
    0x61fe00 : 3
    0x61fe08 : 4
    kich thuoc kieu double: 8 bytes
d) 
    0x61fdf0 : 1
    0x61fe00 : 3
*/