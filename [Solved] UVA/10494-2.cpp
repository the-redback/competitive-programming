#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long div(char a[],long long n,char c[])
{
    int i,j,t=0,l,d=0,r=0;
    long long rem=0;
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        rem=(rem*10)+a[i]-48;

        if(rem>=n||r!=0)
        {
            j=rem/n;
            rem=rem%n;
            c[d]=j+48;
            d++;
            r=1;
        }
    }
    if(d==0)
    {
        c[d]='0';
        d++;
    }
    c[d]='\0';
    return rem;
}

main()
{
    long long n;
    char a[100000],c[100000];
    char ch;
    while(scanf("%s %c %lld",&a,&ch,&n)!=EOF)
    {
        if(ch=='%')
        {
            n=div(a,n,c);
            printf("%lld\n",n);
        }
        else if(ch=='/')
        {
            div(a,n,c);
            printf("%s\n",c);
        }
    }
    return 0;

}
