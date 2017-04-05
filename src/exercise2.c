#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void bof(){
    printf("BOF!\n");
    exit(0);
}
main (int argc, char **argv)
{
    char buff[1004];
    strcpy(buff,argv[1]);
    printf("%s\n",buff);
}
