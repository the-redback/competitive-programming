#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));

int view[20];
vector <int> v;
int a[20];
int N,K;
void call(int k)
{
    int i;
    if(k==K)
    {
        for(i=0;i<K;i++)
            printf("%d",v[i]);
        puts("");

    }
    for(i=0;i<K;i++)
    {
        if(!view[i])
        {
            if(i==0||a[i]!=a[i-1]||view[i-1])
            {
                view[i]=1;
                v.push_back(a[i]);
                call(k+1);
                v.pop_back();
                view[i]=0;
            }
        }
    }
}



main()
{
    int i,j=0,k,l,n,t;
    scanf("%d",&t);
    while(t--)
    {
        j++;
        scanf("%d %d",&K,&l);
        for(i=0;i<K;i++)
        {
            if(i<l)
            {
                a[i]=1;
            }
            else
                a[i]=0;
        }
        sort(a,a+K);
        if(j!=1)
            puts("");
        mem(view,0);
        call(0);
    }
    return 0;
}
