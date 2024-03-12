#include <stdio.h>
#include <string.h>

using namespace std;

int cnv(char *s)
{
    int i=0;
    int nr=0;
    int c;
    while(s[i]!='\0')
    {
        c=s[i]-'0';
        nr=nr*10+c;
        i++;
    }
    return nr;
}

int main()
{
    char s[100], *t;
    int n, suma=0;
    FILE * f = fopen("/home/skullface/Documents/oop/source/in.txt", "r");
    if (f==NULL)
    {
        printf("Error file not found \n");
        fclose(f);
    }
    else{
        while(fgets(s,100,f))
        {
            t=strtok(s, " \t\n");
            n=cnv(t);
            suma+=n;
        }

        printf("Sum=%d\n", suma);
        fclose(f);
    }
}