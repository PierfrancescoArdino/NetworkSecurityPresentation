#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void bof(){
    printf("BOF!\n");
    exit(0);
}
int main (int argc, char **argv)
{
    char buff[32];
    strcpy(buff,argv[1]);
    printf("%s\n",buff);
    return 0;
}
