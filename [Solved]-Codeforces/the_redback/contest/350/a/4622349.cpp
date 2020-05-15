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
    int ret;
    int n,m,i,j,sum,k;
    vector<int>r;
    vector<int>w;
    scanf("%d%d",&n,&m);
    for( i=0;i<n;i++)
    {
        scanf("%d",&k);
        r.push_back(k);
    }
    for( i=0;i<m;i++)
    {
        scanf("%d",&k);
        w.push_back(k);
    }
    sort(r.begin(),r.end());
    sort(w.begin(),w.end());
    sum=r[0]*2;
    if(r[r.size()-1]>sum)
        sum=r[r.size()-1];
    if(w[0]<=sum)
        puts("-1");
    else
        printf("%d\n",sum);
    return 0;
}
