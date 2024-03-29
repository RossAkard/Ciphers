// Encrpt a word of your choice using the Caesar cipher
// which is selecting a number to cycle through the alphabet
// by which is the "key" applied to each letter of you code word



#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

// declare pointer usage

void usage(char *c);

int main(int argc, char *argv[])
// if 2 variables being code word and key are not entered, return "usage"
{
    if (argc !=2)
        usage(argv[0]);

// have word chosen to be encrypted be pointed to by the char variable
// and have the numerical length of the string be assigned to variable "ln"

    char *key = argv[1];
    int ln = strlen(key);
  
    // loop through each letter verifying letters only were used for the word
    // that is to be encrypted, the code word.
    
    for (int i=0; i<ln; i++)
    {
        if (!(isdigit(key[i])))
            usage(argv[0]);
    }
    // assign integer variable "w" the ASCII numerical equivalent
    // of the corresponding letter from the code word to be encrypted
    
    int w = atoi(argv[1]);
    
    if (w<0)
        usage(argv[0]);
        
// have the character "tex" variable which is an abbreviation of text, collect
// and store the user's entry for the code word

    char *tex = GetString();
    
    // assign variable "ln" to represent the string length of the "tex" variable
    ln = strlen(tex);
    
    // loop through each letter of the code word applying encryption code
    // to the ASCII values of the code word, and then print the results
    
    for (int i=0; i<ln; i++)
    {
        char alph;
        if (isupper(tex[i]))
            alph='A';
        else if (islower(tex[i]))
            alph='a';
        else
            continue;
        tex[i] -= alph;
        tex[i] += w;
        tex[i] %= 26;
        tex[i] += alph;
    }
    printf("%s\n", tex);
    
    return (EXIT_SUCCESS);
}

void usage(char *c)  {
    printf("%s is positive integer, n.\n", c);
    exit(EXIT_FAILURE);
}
