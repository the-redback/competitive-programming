#include<stdio.h>
#include <string.h>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    __int64 sum;
    int i=0,j,k,l,n,m;
    scanf("%d %d",&n,&m);
    sum=0;
    j=1;
    while(m--)
    {
        scanf("%d",&i);
        if(i>=j)
            sum+=i-j;
        else if(i<j)
            sum+=(n-j)+i;
        j=i;
    }
    printf("%I64d\n",sum);
    return 0;
}
