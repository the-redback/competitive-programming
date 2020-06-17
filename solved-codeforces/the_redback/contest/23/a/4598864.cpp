#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
char a[1000],b[1000],c[1000];
int l;
int check(int i,int n)
{
    int j,k,sum=1,p;
    for( j=i+1; j<l; j++)
    {
        for( k=0,p=j; k<n; k++,p++)
        {
            c[k]=a[p];
        }
        c[k]=0;
        if(strcmp(c,b)==0)
            sum++;
    }
    return sum;
}

main()
{
    int tc,t,i,j,k,n,p;
    cin>>tc;
    gets(a);
        int sum=0,mx=0,il=0;
         l=strlen(a);
        for(int i=1; i<l; i++)
        {
            for(int j=0; j<l-i; j++)
            {
                for(k=0,p=j; k<i; k++,p++)
                    b[k]=a[p];
                b[k]=0;
                int sum=check(j,i);
                il=strlen(b);
                if(sum>=2 && mx<il)
                {
                    mx=il;
                }
            }
        }
        printf("%d\n",mx);
    return 0;
}
