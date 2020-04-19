#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char a[1001][10000];

void swap(char b[10000])
{
    int temp,i,j,l;
    l=strlen(b);
    for(i=0,j=l-1;i<l/2;i++,j--)
    {
        temp=b[i];
        b[i]=b[j];
        b[j]=temp;
    }
}

void work(char a[10000],char b[10000],int n)
{
    int i,j,onhand=0,k,l;
    l=strlen(a);
    for(i=l-1,j=0;i>=0;i--)
    {
        k=((a[i]-48)*n)+onhand;
        b[j]=(k%10)+48;
        onhand=k/10;
        j++;
    }
    while(onhand>0)
    {
        b[j]=(onhand%10)+48;
        onhand/=10;
        j++;
    }
    b[j]='\0';
    swap(b);
}

main()
{
    int i,j,n,c[10];
    strcpy(a[0],"1");
    strcpy(a[1],"1");
    for(i=2;i<=366;i++)
    {
        work(a[i-1],a[i],i);

    }
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            return 0;
        memset(c,0,sizeof(c));
        for(i=0;a[n][i]!='\0';i++)
        {
            j=a[n][i]-48;
            c[j]++;
        }
        printf("%d! --\n",n);
        for(i=0;i<=9;i++)
        {
            if(i==5)
                printf("\n");
            printf("   (%d)%5d",i,c[i]);
        }
        printf("\n");
    }
    return 0;
}
