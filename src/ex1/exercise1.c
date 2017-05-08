#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char **argv)
{
    int pass=0;
    char buff[8];
    strcpy(buff,argv[1]);
    if(strcmp("password",buff)==0)
    {
        printf("the password is correct!\n");
        pass=1;
    }
    else{
        printf("Wrong password\n");
    }
    printf("buff: %s\n",buff);
    printf("pass: %d\n",pass);
    if(pass)
    {
        printf("permission granted\n");
    }
    else
    {
        printf("permission denied\n");
    }
    return 0;
}
