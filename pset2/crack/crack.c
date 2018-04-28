#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
int main(int argc, string argv[])
{
    string hash;
    char salt[3] ;
    char password[6] = "";
    string alpha = "abcdefghijklmnopqrstuvwsyzABCDEFGHIJKLMNOPQRSTUVWSYZ";

    //check for two command-line arguments
    if(argc != 2)
    {
        printf("Usage: ./crack [hash]\n");
        return 1;
    }

    //get encripted hash
    hash= argv[1];
    for(int i = 0; i < strlen(hash); i++)
    {
        if(!isalnum(hash[i]) && hash[i] != '.' && hash[i] != '/')
        {
            printf("Usage: ./crack [hash]\nHint: a-z A-Z ./ \n");
            return 1;
        }
    }
    //get salt
    salt[0] = hash[0];
    salt[1] = hash[1];

    //printf("%s \n", salt);

    //for each hash generated
    //encript and compare
    //once a match found print hash

    /*for one-char length passwords*/
    for(int i = 0; i < 52; i++)
    {
        password[0] = alpha[i];
        //printf("%s\n", password);
        if((strcmp(crypt(password, salt), hash)) == 0 )
        {
            printf("%s\n", password);
            return 0;
        }

    }

    /*for two-char length passwords*/
    for(int i = 0; i < 52; i ++)
    {
        for(int j = 0; j < 52; j++)
        {
            password[0] = alpha[i];
            password[1] = alpha[j];
            //printf("%s\n", password);
            if((strcmp(crypt(password, salt), hash)) == 0 )
            {
                printf("%s\n", password);
                return 0;
            }
        }

    }

    /*for three-char length passwords*/
    for(int i = 0; i < 52; i ++)
    {
        for(int j = 0; j < 52; j++)
        {
            for(int k = 0; k < 52; k++)
            {
                password[0] = alpha[i];
                password[1] = alpha[j];
                password[2] = alpha[k];
                //printf("%s\n", password);
                if((strcmp(crypt(password, salt), hash)) == 0 )
                {
                    printf("%s\n", password);
                    return 0;
                }
            }
        }

    }
    /*for four-char length passwords*/
    for(int i = 0; i < 52; i ++)
    {
        for(int j = 0; j < 52; j++)
        {
            for(int k = 0; k < 52; k ++)
            {
                for(int l = 0; l < 52; l++)
                {
                    password[0] = alpha[i];
                    password[1] = alpha[j];
                    password[2] = alpha[k];
                    password[3] = alpha[l];
                    //printf("%s\n", password);
                    if((strcmp(crypt(password, salt), hash)) == 0 )
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                }
            }

        }

    }

    /*for five-char length passwords*/
    for(int i = 0; i < 52; i ++)
    {
        for(int j = 0; j < 52; j++)
        {
            for(int k = 0; k < 52; k ++)
            {
                for(int l = 0; l < 52; l++)
                {
                    for(int m = 0; m < 52; m++)
                    {
                        password[0] = alpha[i];
                        password[1] = alpha[j];
                        password[2] = alpha[k];
                        password[3] = alpha[l];
                        password[4] = alpha[m];
                        //printf("%s\n", password);
                        if((strcmp(crypt(password, salt), hash)) == 0 )
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }

    }
}