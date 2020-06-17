#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

main()
{
    int tc,i,j,t=0,f=0,k,n,l;
    scanf("%d",&n);
    int flag=0,ret=0;
    while(n--)
    {
        scanf("%d",&k);
        if(k==25)
        {
            flag=1;
            t++;
        }
        else if((k==50 && flag==0) ||( k==100 &&flag==0))
        {
            ret=1;
        }
        else if(k==50)
        {
            t--;
            f++;
            if(t<0)
                ret=1;
        }
        else if(k==100)
        {
            if(f>=1)
            {
                f-=1;
                i=50;
            }
            else
            {
                i=0;
            }
            i=75-i;
                if((t*25)<i)
                    ret=1;
                else
                    t-=i/25;
        }
    }
    if(ret==0)
        puts("YES");
    else
        puts("NO");
    return 0;
}
