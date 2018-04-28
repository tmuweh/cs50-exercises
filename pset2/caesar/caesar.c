#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    int key = 0; //initialize key
    string plaintext;

    //get key from command-line argument
    if( argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //convert key from string to integer
        key = atoi(argv[1]);
    }

    //prompt for plaintext
    plaintext = get_string("plaintext: ");

    //for each character in plaintext
    for(int i = 0; i < strlen(plaintext); i++)
    {
        //if char is alphabethical
        if(isalpha(plaintext[i]))
        {
            //preserve case
            //shift plaintext by key

            if(isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'A') + key) % 26 + 'A';
            }

            if(islower(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'a') + key) % 26 + 'a';
            }
        }
        else
        {
            plaintext[i] = plaintext[i];
        }

    }

    //print ciphertext
    printf("ciphertext: %s\n", plaintext);
}