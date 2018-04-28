#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height = 0;

    // promt and get valid integer
    do
    {
        printf("Height: ");
        height =    get_int();

    }while (height < 0 || height > 23);

    for (int  row  =  0; row < height; row++)
    {
        for(int column = 0; column < height; column++)
        {
            //print space or hash tag using formular nth row + space <= height - 1 print space else, print hash
            if( (row + column) < (height - 1))
                printf(" ");
            else
                printf("#");

        }
        printf("  ");

        for(int column = height - 1 ; column >= 0; column --)
        {
            //takes care of trailing spaces
            if(row + column >= (height - 1))
            {
                printf("#");
            }
            else
            {
                //printf("%d", column) ;
                printf(" ");
            }

        }
        printf("%d\n", row);

    }
    //print height here;
    //printf("height: %d\n", height);

    return 0;
}