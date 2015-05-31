/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 110
int a[NN+7];
vector<int>edge[NN+7];
vector<int>v;

void get(int n)
{
    int i,j,k,l,mn,in;

    while(v.size()<n)
    {
        mn=inf;
        for(i=1; i<=n; i++)
            if(a[i]<mn)
                mn=a[i],in=i;
        v.push_back(in);
        a[in]=inf;
        for(i=0; i<edge[in].size(); i++)
            a[edge[in][i]]--;
    }
    for(i=0; i<v.size(); i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<v[i];
    }
    cout<<"\n";
    for(i=0; i<=n; i++)
        edge[i].clear();
    v.clear();
    return;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    int tc,t=1,x=-1,m;
    //scanf("%d",&tc);
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        mem(a,0);
        while(m--)
        {
            cin>>k>>l;
            a[l]++;
            edge[k].push_back(l);
        }
        get(n);
    }
    return 0;
}





