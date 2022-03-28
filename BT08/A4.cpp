#include <iostream>

using namespace std;

int main()  
{ 
     char **s; 
    char foo[] = "Hello World"; 
    char *p;
    p = foo;
    *s = p; 
    printf("s is %d\n",s); 
    s[0] = foo; 
    printf("s[0] is %s\n",s[0]); 
    return(0); 
}