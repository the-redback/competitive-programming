#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};
char a[222][222];
int N;
int call(int i,int j,char ch)
{
    if(i==N && ch=='b')
        return 1;
    if(j==N && ch=='w')
        return 1;
    if(i<0||j<0||i>=N||j>=N)
        return 0;
    if(a[i][j]!=ch)
        return 0;
    a[i][j]='.';
    int sum=0;
    for(int k=0;k<6;k++)
    {
        sum=max(sum,call(i+dx[k],j+dy[k],ch));
    }
    return sum;
}


main()
{
    int n,m,tc,t=1;
    while(scanf("%d",&n))
    {
        if(n==0)
            return 0;
        N=n;
        getchar();
        int mxw=0,mxb=0;
        for(int i=0;i<n;i++)
            gets(a[i]);
        for(int i=0;i<n;i++)
        {
            if(a[0][i]=='b')
            {
                int k=call(0,i,a[0][i]);
                if(k>mxb)
                    mxb=k;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i][0]=='w')
            {
                int k=call(i,0,a[i][0]);
                if(k>mxw)
                    mxw=k;
            }
        }
        if(mxb>mxw)
            printf("%d B\n",t++);
        else
            printf("%d W\n",t++);
    }
    return 0;
}
