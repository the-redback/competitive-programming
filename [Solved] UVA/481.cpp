#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));

vector <int> v;
vector <int> L;
vector <int> I;
stack <int> ans;
int LIS(void)
{
    int i,low,high,mid;
    for(i=0;i<v.size();i++)
    {
        low=0;
        high=I.size()-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(v[i]>I[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        if(low==I.size())
            I.push_back(v[i]);
        else
            I[low]=v[i];
        L[i]=low;
    }
    return I.size()-1;
}

main()
{
    v.clear();
    int i,j=0,k=0,l,n,m;
    while(scanf("%d",&n)==1)
    {
        v.push_back(n);
    }
    for(i=0;i<v.size();i++)
        L.push_back(1);
    k=20000000;
    I.push_back(-1*k);
    printf("%d\n-\n",LIS());
    k=0;
    for(i=1 ; i<=v.size() ; i++)
    {
        if(k<L[i])
        {
            k=L[i];
            j=i;
        }
    }
    ans.push(v[j]);
    for(i=j-1,k=k-1;i>=0 && k>=1;i--)
    {
        if(L[i]==k && v[i]<v[j])
        {
            ans.push(v[i]);
            k--;
            j=i;
        }
    }
    while(ans.size())
    {
        printf("%d\n",ans.top());
        ans.pop();
    }
    return 0;
}
