
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[7];
int call(int i,int rem)
{
    if(i==5)
    {
        if(rem==23)
            return 1;
        else
            return 0;
    }
    int x=0,y=0,z=0;
        z=call(i+1,rem-a[i]);
        x=call(i+1,rem*a[i]);
        y=call(i+1,rem+a[i]);
        x=max(x,y);
        z=max(x,z);
    return z;
}
main()
{
    int i,j=0,k;
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]))
    {
        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0)
            return 0;
        sort(a,a+5);
        do
        {
            k=call(1,a[0]);
            if(k==1)
                break;
        }while(next_permutation(a,a+5));
        if(k==1)
            puts("Possible");
        else
            puts("Impossible");
    }
    return 0;
}
