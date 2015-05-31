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

vector<int>v;
int dv[1000010];
void call(void)
{
    int i,j,k,l;
    memset(dv,0,sizeof(dv));
    for(i=1;i<=1000000;i++)
    {
        for(j=i;j<=1000000;j+=i)
            dv[j]++;
    }
    v.push_back(1);
    k=1;
    while(k<1000000)
    {
        k=k+dv[k];
        v.push_back(k);
    }
}

main()
{
    call();
    int tc,i,j,k,l;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        scanf("%d %d",&k,&l);
        vector<int>::iterator low,high;
        low=lower_bound(v.begin(),v.end(),k);
        high=upper_bound(v.begin(),v.end(),l);
        int sum=(high-v.begin())-(low-v.begin());
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}
