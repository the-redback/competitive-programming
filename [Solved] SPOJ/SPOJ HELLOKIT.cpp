#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

main()
{
    int tc,t,i,j;
    cin>>tc;
    char a[1000],b[1000],c[1000];
    while(scanf("%s",&a))
    {
        if(strcmp(a,".")==0)
            return 0;
        int n;
        scanf("%d",&n);
        strcpy(b,a);
        n--;
        while(n--)
            strcat(b,a);
        strcpy(c,b);
        puts(b);
        int l=strlen(b);
        for( i=1, j=0;i<l;i++,j++)
            a[j]=b[i];
        a[j]=b[0];
        j++;
        a[j]=0;
        while(strcmp(a,c)!=0)
        {
            puts(a);
            strcpy(b,a);
            for( i=1,j=0;i<l;i++,j++)
            a[j]=b[i];
            a[j++]=b[0];
            a[j]=0;
        }
    }
    return 0;
}
