#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
main()
{
    vector <long> v;
    long i,j,r,l,p,k;
    int t,it,vsize;
    scanf("%d",&t);
    for(it=1;it<=t;it++)
    {
        scanf("%ld %ld",&p,&l);
        p=p-l;
        r=sqrt(p);
        for(j=1;j<=r;j++)
        {
            k=p/j;
            if(p%j==0)
            {
                if(k>l)
                    v.push_back(k);
                if(j>l && j!=k)
                    v.push_back(j);
            }
            if(j<l && k<l)
                break;
        }
        sort(v.begin(),v.end());
        printf("Case %ld:",it);
        vsize=v.size();
        for(i=0;i<vsize;i++)
        {
            printf(" %ld",v[i]);
        }
        if(i==0)
            printf(" impossible");
        printf("\n");
        v.clear();
    }
    return 0;
}
