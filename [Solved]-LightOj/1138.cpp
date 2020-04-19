#include <bits/stdc++.h>
using namespace std;

int M=400000015;
int N;

int check(int n)
{
    int sum=0;
    for(int i=1; i<=n && sum<=N; i++)
    {
        int m=pow(5.0,i);
        m=n/m;
        if(m>0)
        {
            sum+=m;
        }
        else
            return sum;
    }
    return sum;
}

int call(int n)
{
    int high=M,low=1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        int sum=check(mid);
        if(sum==n)
            return mid;
        if(n<sum)
            high=mid-1;
        else if(n>sum)
            low=mid+1;
    }
    return -1;
}

main()
{
    int tc,t;
    cin>>tc;
    for(t=1; t<=tc; t++)
    {
        cin>>N;
        long mx=call(N);
        if(mx==-1)
            printf("Case %d: impossible\n",t);
        else
        {
            mx-=mx%5;
            printf("Case %d: %ld\n",t,mx);
        }
    }
    return 0;
}
