/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
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
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        1000000

#define read(a)   scanf("%lld",&a)


struct trie
{
    int total;
    int next[4];
    trie()
    {
        total=0;
        for(ll i=0; i<4; i++)
            next[i]=-1;
    }
};

vector<trie>tree;
ll ans=0;
char arr[100];

void Insert(void)
{
    ll len=strlen(arr);

    ll node=0;
    for(ll i=0; i<len; i++)
    {
        ll id;

        if(arr[i]=='A') id=0;
        else if(arr[i]=='C') id=1;
        else if(arr[i]=='G') id=2;
        else if(arr[i]=='T') id=3;

        if(tree[node].next[id]==-1)
        {
            tree[node].next[id]=(int)tree.size();
            tree.pb(trie());
        }
        node=tree[node].next[id];   ///Go to next node, then increase total.
        tree[node].total++;
        ans=max(ans,tree[node].total*(i+1));

    }

}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif


    ll t=1,tc;
    read(tc);       ///Test case
    ll i,j,k,l,m,n;
    while(tc--)
    {
        tree.pb(trie());  ///Root node actually.

        read(n);
        ans=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",&arr);
            Insert();
        }
        printf("Case %lld: %lld\n",t++,ans);


        tree.clear(); ///Delete The Memory.
    }
    return 0;
}
