// this program obtains a word to be encrypted, and encrypts the word
// based on the user's input as a "key" where the original code word
// is changed by the ASCII numerical equivalent of the "key" word

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<cs50.h>

int main(int argc, char *argv[])
{
    // declare variables
	
    string t;
    string w;
    int x = 0;
    int key;
    bool isWord;
    
    // if 2 arguments are not entered, return usage
    
    if (argc!=2)
    {
        printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
        return 1;
    }
    else
    {
    	    // determine if only letters were entered by user,
    	    // if not, prompt for letters only
    	    
        for (int i = 0, x = strlen(argv[1]); i<x; i++)
        {
            isWord = isalpha(argv[1][i]);
        }
        if (isWord == false)
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }
    }
    
    // assign variable "w" to the 2nd argument entered by the user
    
    w = argv[1];
    
    // assign variable "t" to obtain and store the users input
    
    t = GetString();
    
    // assign variable "m" for the string leght of the users input
    // loop through each letter of the users input only if letters only were
    // entered, then encrypt the codeword by the keyword using ASCII values
    // print results
    
    for (int i = 0, m = strlen(t); i< m; i++)
    {
        if (isalpha(t[i]))
        {
            x = x % strlen(w);
            if (isupper(w[x]))
            {
                key = w[x] - 'A';
            }
            else
            {
                key = w[x] - 'a';
            }
            if (isupper(t[i]))
            {
                t[i] = (t[i] - 'A' + key) % 26;
                t[i] = t[i] + 'A';
                x++;
            }
            else
            {
                t[i] = (t[i] - 'a' + key) % 26;
                t[i] = t[i] + 'a';
                x++;
            }
        }
    }
    for (int i = 0, m = strlen(t); i<m; i++)
    {
        printf("%c", t[i]);
    }
    printf("\n");
}
