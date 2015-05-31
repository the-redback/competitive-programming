#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int a[4];
int n;
int check(int rem,int pos)
{
    if(rem==0)
        return 1;
    if(pos==4)
        return 0;
    int x=0,y=0;
    if(rem-a[pos]>=0)
        x=check(rem-a[pos],pos+1);
    y=check(rem,pos+1);
    return max(x,y);
}
class LotteryTicket
{
    public:
    string buy(int m,int b1,int b2,int b3,int b4)
    {
        n=m;
        a[0]=b1;
        a[1]=b2;
        a[2]=b3;
        a[3]=b4;
        string s;
        if(check(n,0)==1)
            s="POSSIBLE";
        else
            s="IMPOSSIBLE";
        return s;
    }
};

main()
{
    LotteryTicket c;
    string g;
    g=c.buy(1000,999,998,997,996);
    cout<<g;
    return 0;
}
