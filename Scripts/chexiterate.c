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
    // int     numberOfArgs = argc;
    // printf("number of byte pairs = %d\n", numberOfArgs);
    // char *arg1 = argv[0];
    // printf("argv[1] = %s\n", argv[1]);
    int records;
    long long lastG = 1;
    

    FILE *ild = NULL;
    ild = fopen(argv[1], "r"); // "r" for read
    if (ild == NULL) {
        printf ("Could not read file");
         return 0;
    }

    FILE *f_ptr = NULL;
    fpos_t position;

    f_ptr = fopen("outtie1.txt", "w+");
    if (f_ptr == NULL) {
        printf ("Could not write to file");
         return 0;
    }
    

    // HEADER READING HERE:
    for(int y=1; y<17; y++)
    {
        char hex[5];
            fscanf(ild, "%s", hex);
        if (y==1) 
        {
            printf("first hexpair = %s", hex);
            if  (strcmp(hex, "494c")==0) 
                printf("I is first char");
            else 
            {
                printf("NOT ILDA FILE");
                exit(1);
            }    
        }
        if (y==13)  // checks the number of records 
        {
            // printf("y is 13 now");
            long long decimal, place;
            int i = 0, val, len;
            decimal = 0;
            place = 1;
            len = strlen(hex);
            len--;

            for(i=0; hex[i]!='\0'; i++)
            {
        
                
                if(hex[i]>='0' && hex[i]<='9')
                { val = hex[i] - 48; }
                else if(hex[i]>='a' && hex[i]<='f')
                { val = hex[i] - 97 + 10; }
                else if(hex[i]>='A' && hex[i]<='F')
                { val = hex[i] - 65 + 10; }

                decimal += val * pow(16, len);
                len--;
                
            }
            printf("number of records is %d\n", decimal);
           records = 4*decimal;
        }
        
    }
       
    for(int y=17; y<records; y++)
    {
        
        char hex[5];
            fscanf(ild, "%s", hex);

        if (y%4 != 3)
        {
            long long decimal, place;
            int G1; 
            int G;
            float X1;
            float Y1;
            int i = 0, val, len;
            decimal = 0;
            place = 1;
            len = strlen(hex);
            len--;
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

            // printf("Hexadecimal number = %s\n", hex);
            // printf("Decimal number = %lld\n\n", decimal);
            if (y%4==1)
            {
            X1 = decimal>>4;
            }
            else if (y%4 == 2)
            {
            Y1 = decimal>>4;
            }
            else if (y%4 == 0)
            {
                if (decimal > 0 && decimal <256)
                {
                    G = 2;
                }
                else 
                    {
                        G = 0;
                    }
                // if (lastG != G)
                // {
                //     fprintf(f_ptr, "G0%d\n", G);
                //     lastG = G;
                // }
            }
            fprintf(f_ptr, "G0%d X%f Y%f\n",G, X1, Y1);
        }
        
        
        
       
    }
     fclose(f_ptr);
    return 0;
}