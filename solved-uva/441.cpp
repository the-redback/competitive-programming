#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[20];
bool view[20];
vector <int> v;
int n;
void call(int m)
{
    if(v.size()==6)
    {
        for(int i=0;i<6;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",v[i]);
        }
        puts("");
        return;
    }
    for(int i=m;i<n;i++)
    {
        if(!view[i])
        {
            view[i]=1;
            v.push_back(a[i]);
            call(i+1);
            v.pop_back();
            view[i]=0;
        }
    }
    return;
}

main()
{
    int i,j=0;
    while(scanf("%d",&n))
    {
        memset(view,0,sizeof(view));
        if(n==0)
            return 0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(j!=0)
            puts("");
        call(0);
        j++;
    }
    return 0;
}
