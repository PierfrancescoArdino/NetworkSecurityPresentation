#include <stdio.h>
void test(int a , int b , int c ) {
    char buffer1[4] = { 'A' , 'B' , 'C' , 'D' } ;
    int buffer2[3] = {a, b, c};
}

int main (int argc, char **argv) {
    test(1, 2, 3);
    return 0;
}
