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
    long k;
    vector<long>v;
    vector<long>::iterator low,high;
    int tc,i,j,q,n,l;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        scanf("%ld",&k);
        v.push_back(k);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%ld",&k);
        low=lower_bound(v.begin(),v.end(),k);
        high=upper_bound(v.begin(),v.end(),k);
        j=low-v.begin()-1;
        l=high-v.begin();
        if(j>=0)
            printf("%d ",v[j]);
        else
            printf("X ");
        if(l<n)
            printf("%d\n",v[l]);
        else
            printf("X\n");
    }
    return 0;
}
