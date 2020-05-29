/**
 * C program to convert Hexadecimal to Decimal number system
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// use fscanf "%x" to retrieve these from a file instead of the main args. 
int main(int argc, char *argv[])
{
    int     numberOfArgs = argc;
    printf("number of byte pairs = %d\n", numberOfArgs);
    char *arg1 = argv[0];
    printf("argv[1] = %s\n", argv[1]);

    FILE *f_ptr = NULL;
    fpos_t position;

    f_ptr = fopen("outtie.txt", "w+");
    if (f_ptr == NULL) {
        printf ("Could not write to file");
         return 0;
    }
    
        // char *hex[] = argv[1];
    for(int y=1; y<numberOfArgs; y++)
    {
        if (y%4 == 1 || y%4 == 2)
            {
            char hex[5];
            strcpy(hex, argv[y]);
            printf("hex = %s\n", hex);
            long long decimal, place;
            int i = 0, val, len;

            decimal = 0;
            place = 1;

            // /* Input hexadecimal number from user */
            // // printf("Enter any hexadecimal number: ");
            // // gets(hex);

            /* Find the length of total number of hex digit */
            len = strlen(hex);
            len--;

            /*
            * Iterate over each hex digit
            */
            for(i=0; hex[i]!='\0'; i++)
            {
        
                /* Find the decimal representation of hex[i] */
                if(hex[i]>='0' && hex[i]<='9')
                {
                    val = hex[i] - 48;
                }
                else if(hex[i]>='a' && hex[i]<='f')
                {
                    val = hex[i] - 97 + 10;
                }
                else if(hex[i]>='A' && hex[i]<='F')
                {
                    val = hex[i] - 65 + 10;
                }

                decimal += val * pow(16, len);
                len--;
            }

            printf("Hexadecimal number = %s\n", hex);
            printf("Decimal number = %lld\n\n", decimal);
            if (y%4==1)
            {
            // fgetpos(f_ptr, &position);
            fprintf(f_ptr, "X");
            // fseek(f_ptr, (y*2), SEEK_SET);
            fprintf(f_ptr, "%lld ", decimal);
            }
            else if (y%4 == 2)
            {
            fprintf(f_ptr, " Y");
            fprintf(f_ptr, "%lld\n", decimal);
            }
        }
        
       
    }
     fclose(f_ptr);
    return 0;
}