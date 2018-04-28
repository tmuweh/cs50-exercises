#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    string alpha_key = "";    //initialize alpha_key
    int n;              //string length of entered alpha_key
    int j = 0;          // index for alpha_key array
    string plaintext;

    //get alpha_key from command-line argument
    if( argc != 2)
    {
        printf("Usage: ./vigenere alpha_key\n");
        return 1;
    }
    else
    {
        alpha_key = argv[1];
        n = strlen(alpha_key);
        //check that alpha_key is alpha
        for(int i = 0; i < n; i++)
        {
            if(!isalpha(alpha_key[i])) // is any character found in alpha_key isn't a alpha, exit.
            {
                printf("Usage: ./vigenere alpha_alpha_key\n");
                return 1;
            }
        }

    }

    //prompt for plaintext
    plaintext = get_string("plaintext: ");

    //for each character in plaintext
    for(int i = 0; i < strlen(plaintext); i++)
    {
        //if char is alphabethical
        if(isalpha(plaintext[i]))
        {

            // makes sure the j index of the alpha_key doesn't exceed length of alpha_key by j % n where n is the strlen of alpha_key
            j = j % n;

            if(isupper(plaintext[i]))
            {
                alpha_key[j] = toupper(alpha_key[j]); //  convert at this point key char to required case for connect indexing
                plaintext[i] = ((plaintext[i] - 'A') + (alpha_key[j] - 'A')) % 26 + 'A';
            }

            if(islower(plaintext[i]))
            {
                alpha_key[j] = tolower(alpha_key[j]); //  convert at this point key char to required case for connect indexing
                plaintext[i] = ((plaintext[i] - 'a') + (alpha_key[j]) - 'a') % 26 + 'a';
            }

            //increment index of j now to move to next char in alpha_key array
            j++;

        }
        else
        {
            plaintext[i] = plaintext[i];
        }

    }

    //print ciphertext
    printf("ciphertext: %s\n", plaintext);
}