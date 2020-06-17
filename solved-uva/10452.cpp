#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
char a[15][15];
string s="IEHOVA";
int dir[15][15];
int X,Y;

int call(int x,int y,int i)
{
    if(a[x][y]=='#')
    {
        return 1;
    }
    if(x<0|| y<0|| y==Y || i>5 )
        return 0;
    if(a[x][y]!=s[i])
        return 0;
    int p=0,q=0,r=0;
    p=call(x,y-1,i+1);
    q=call(x,y+1,i+1);
    r=call(x-1,y,i+1);
    if(r==1)
        dir[x][y]=2;
    else if(p==1)
        dir[x][y]=1;
    else if(q==1)
        dir[x][y]=3;
    return p|q|r;
}

main()
{
    int t=1,i,j,k,l;
    scanf("%d",&t);
    while(t--)
    {
        mem(dir,-1);
        scanf("%d%d",&X,&Y);
        for(i=0;i<X;i++)
        {
            scanf("%s",&a[i]);
        }
        for(i=0;i<Y;i++)
            if(a[X-1][i]=='@')
            {
                k=X-1;
                l=i;
                break;
            }
        if(call(k-1,l,0))
            dir[k][l]=2;
        else if(call(k,l-1,0))
            dir[k][l]=1;
        else if(call(k,l+1,0))
             dir[k][l]=3;
        i=0;
        while(dir[k][l]!=-1)
        {
            if(i!=0)
                printf(" ");
            if(dir[k][l]==1)
            {
                printf("left");
                l--;
            }
            else if(dir[k][l]==2)
            {
                printf("forth");
                k--;
            }
            else if(dir[k][l]==3)
            {
                printf("right");
                l++;
            }
            i=1;
        }
        puts("");
    }
    return 0;
}
