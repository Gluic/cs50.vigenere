/**
* Vigenere
* Get a keyword and string to code with vigenere code
* Print coded string
*/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv [])
{
    // get argument
    string k = argv[1];
   
    // check if arguments more than 2 or 0
    if (argv[2] != NULL || k == NULL)
    {
        printf ("More than 1 or lack of arguments!\n");
        return 1;
    }
     // transform argument to numbers
    int z = strlen (k);
    int code [z];
     for (int i = 0; i < z; i++)
    {
        code [i] = toupper(k [i]) - 65;
        if (isdigit(k[i]))
        {
            printf ("More than 1 or lack of arguments!\n");
            return 1;
        }
    } 
    // get string to code  
    char x;
    string text = GetString();
    
    // coding
    int t = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check if character is letter
        if (isalpha(text[i]))
        {
            if (t >= z)
                 t = t % z;
                           
            x = text[i] + code[t];
            
            if (isalpha(x) && isupper(x) == isupper(text[i]))
                printf ("%c",x);
            else 
            {   
                x = x - 26;
                printf ("%c",x);
            }
            t = t + 1; 
        }
        // dont code non letters
        if (isalpha(text[i]) == false)
        {
            printf ("%c",text[i]);
        }    
    }
   printf ("\n");
   return 0;
}
