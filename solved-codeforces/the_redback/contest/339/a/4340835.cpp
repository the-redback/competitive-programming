#include<stdio.h>
#include <string.h>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    char a[1000];
    int i=0,j,k,l;
    char ch,c;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch=='\n')
            break;
        else if(ch=='+')
            continue;
        else
            a[i++]=ch;
    }
    a[i]=0;
    l=strlen(a);
    sort(a,a+l);
    for(i=0;i<l;i++)
    {
        if(i!=0)
            printf("+");
        printf("%c",a[i]);
    }
    return 0;
}
