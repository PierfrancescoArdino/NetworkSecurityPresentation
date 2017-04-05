#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
main (int argc, char **argv)
{
   // char test[5] = {'N', 'e', 't', 's', '\0'};
    int pass=0;
    char buff[8];
    strcpy(buff,argv[1]);
    printf("%s\n",buff);
    printf("%d\n",pass);
    if(strcmp("password",buff)==0)
    {
        printf("the password is correct!\n");
        pass=1;
    }
    else{
        printf("Wrong password\n");
    }
    if(pass)
    {
        printf("permission granted\n");
    }
    else
    {
        printf("permission denied\n");
    }
    exit(0);
}
