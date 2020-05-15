#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char a[101],b[101],c[101];
    int i,j,k,l,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        l=strlen(a);
        if(l>4)
        {
            j=0;
            for(i=l-5;i<l;i++)
            b[j++]=a[i];
            b[j]=0;
            j=0;
            for(i=0;i<5;i++)
                c[j++]=a[i];
                c[j]=0;
            if(strcmp(b,"lala.")==0 && strcmp(c,"miao.")==0)
            {
                puts("OMG>.< I don't know!");
                continue;
            }
            if(strcmp(b,"lala.")==0)
            {
                puts("Freda's");
                continue;
            }
            else if(strcmp(c,"miao.")==0)
            {
                puts("Rainbow's");
                continue;
            }
        }
        puts("OMG>.< I don't know!");
    }
    return 0;
}
