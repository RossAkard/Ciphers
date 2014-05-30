#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void usage(char *c);

int main(int argc, char *argv[])
{
    if (argc !=2)
        usage(argv[0]);
        
    char *key = argv[1];
    int ln = strlen(key);
    
    for (int i=0; i<ln; i++)
    {
        if (!(isdigit(key[i])))
            usage(argv[0]);
    }
    
    int w = atoi(argv[1]);
    
    if (w<0)
        usage(argv[0]);
        
    char *tex = GetString();
    
    ln = strlen(tex);
    
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