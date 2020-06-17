#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,tc;
    int x,y,n;
    int m,i,l=0,r=0,k=0;
    char a[50];
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d%d",&x,&y);
        if(x&1 && y&1)
            k++;
        else if(x&1)
            l++;
        else if(y&1)
            r++;
    }
    k%=2;
    if((k+r)%2==0 && (k+l)%2==0)
        puts("0");
    else if(k)
    {
        if(r+l>=2)
        {
            r--;
            l--;
            if((r+l)%2==0)
                puts("1");
            else
                puts("-1");
        }
        else
            puts("-1");
    }
    else if((r+l)%2==0)
        puts("1");
    else
        puts("-1");
    return 0;
}
