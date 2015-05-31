#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int I;
int arr[125][5];
int a[7];
bool view[7];
vector <int>v;
void perm(void)
{
        int i;
    if(v.size()==5)
    {
        for(i=0;i<5;i++)
        {
            arr[I][i]=v[i];
        }
        I++;
    }
    for(i=0;i<5;i++)
    {
        if(!view[i])
        {
            view[i]=1;
            v.push_back(a[i]);
            perm();
            v.pop_back();
            view[i]=0;
        }
    }
}
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
        v.clear();
        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0)
            return 0;
        memset(view,0,sizeof(view));
        I=0;
        sort(a,a+5);
        perm();
        for(i=0;i<120;i++)
        {
            for(j=0;j<5;j++)
                a[j]=arr[i][j];
            k=call(1,a[0]);
            if(k==1)
            {
                break;
            }
        }
        if(k==1)
            puts("Possible");
        else
            puts("Impossible");
    }
    return 0;
}
