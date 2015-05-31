#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector <int>v;
int array[20];
int n,f;
void check(int remain,int m)
{
    int i;
    if(remain==0)
    {
        for(i=0;i<v.size();i++)
        {
            if(i!=0)
                printf("+");
            printf("%d",v[i]);
        }
        puts("");
        f=1;
        return;
    }
    for(i=m;i<n;i++)
    {
        if(i==m|| array[i]!=array[i-1])
        {
            v.push_back(array[i]);
            check(remain-array[i],i+1);
            v.pop_back();
        }
    }
}

main()
{
    int i,j,k,m;
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0 && n==0)
            return 0;
        for(i=0;i<n;i++)
            scanf("%d",&array[i]);
        f=0;
        printf("Sums of %d:\n",m);
        check(m,0);
        if(f==0)
            puts("NONE");
    }

}
