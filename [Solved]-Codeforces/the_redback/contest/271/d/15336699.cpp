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

#define ft         first
#define sd         second
#define mp         make_pair
#define pb(x)      push_back(x)
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define mem(a,b)   memset(a,b,sizeof(a))
#define repv(i,a)  for(i=0;i<(ll)a.size();i++)
#define revv(i,a)  for(i=(ll)a.size()-1;i>=0;i--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define sf(a)      scanf("%lld",&a)
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         100010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros


struct trie
{
    bool endmark;
    int next[26];
    trie()
    {
        endmark=0;
        for(int i=0; i<26; i++)
            next[i]=-1;
    }
};

vector<trie>tree;
char b[50];
int a[200];
int K;

int Insert(string arr,int start)    ///Insert arr string
{

    int node=0;
    int sum=0,cnt=0;
    for(int i=start; i<arr.size(); i++)
    {
        int id=arr[i]-'a';
        sum+=a[arr[i]];


        if(tree[node].next[id]==-1)
        {
            tree[node].next[id]=(int)tree.size();
            tree.pb(trie());
            if(sum<=K)
                cnt++;
        }
        node=tree[node].next[id];
    }
    tree[node].endmark=1; ///endmark marks the ending of a string
    return cnt;
}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    char arr[1600];


    int t=1,tc;
    //read(tc);       ///Test case
    int i,j,k,l,m,n;
    while(~scanf("%s",&arr))
    {
        tree.pb(trie());  ///Root node actually.

        scanf("%s",&b);
        scanf("%d",&K);
        for(i=0;b[i];i++)
            a[i+'a']=(b[i]-'0')^1;

        int sum=0;
        for(i=0; arr[i]; i++)
        {
            sum+=Insert(arr,i);   ///Insert arr string into dictionary.
        }

        printf("%d\n",sum);

        tree.clear(); ///Delete The Memory.
    }
    return 0;
}
