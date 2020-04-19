/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        1001000

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

struct D
{
    int x,y;
    D(int X,int Y)
    {
        x=X,y=Y;
    }
    D(){ }
}a[50100];

int N;
int tree[NN];
int b[50100];
vector<int>v;
map<int,int>mymap;

int update(int idx,int val)
{
    while(idx<=N)
    {
        tree[idx]+=val;
        idx+=idx & (-idx);
    }
    return 0;
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx & (-idx);
    }
    return sum;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l,m,n;
    while(tc--)
    {
        v.clear();
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>k>>l;
            a[i]=D(k,l);
            v.pb(k);
            v.pb(l);
        }
        for(i=0;i<m;i++)
        {
            cin>>k;
            b[i]=k;
            v.pb(k);
        }
        sort(all(v));

        mymap.clear();
        j=1;
        for(i=0;i<v.size();i++)
        {
            if(mymap.find(v[i])==mymap.end())
                mymap[v[i]]=j++;
        }
        N=j;
        memset(tree,0,sizeof(int)*(N+1));
        for(i=0;i<n;i++)
        {
            k=mymap[a[i].x];
            l=mymap[a[i].y];
            update(k,1);
            update(l+1,-1);
        }
        printf("Case %d:\n",t++);
        for(i=0;i<m;i++)
        {
            k=mymap[b[i]];
            int ret=query(k);
            printf("%d\n",ret);
        }

    }
    return 0;
}
