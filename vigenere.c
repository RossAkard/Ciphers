#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<cs50.h>

int main(int argc, char *argv[])
{
    string t;
    string w;
    int x = 0;
    int key;
    bool isWord;
    
    if (argc!=2)
    {
        printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
        return 1;
    }
    else
    {
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
    
    w = argv[1];
    
    t = GetString();
    
    
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