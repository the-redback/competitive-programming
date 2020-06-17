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
#define NN        100010

#define read(a)   scanf("%lld",&a)

struct node
{
    bool endmark;
    node *next[10];
    node()
    {
        endmark=0;
        for(ll i=0; i<10; i++)
            next[i]=NULL;
    }
}*root;

char arr[20];

ll Insert(void)
{
    ll len=strlen(arr);

    node *cur=root;
    for(ll i=0; i<len; i++)
    {
        ll id=arr[i]-'0';

        if(cur->next[id]==NULL)
        {
            cur->next[id]=new node();
        }
        else
        {
            if(i+1==len)  ///If a string exists where arr is a prefix.
                return 0;
        }
        if(cur->endmark) ///If a string exists where that string is a prefix of arr.
            return 0;
        cur=cur->next[id];
    }
    cur->endmark=1;
    return 1;
}

void del(node *cur)
{
    for(int i=0; i<10; i++)
        if(cur->next[i])
            del(cur->next[i]) ;

    delete(cur) ;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif



    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        root=new node();
        ll flag=1;
        for(i=0; i<n; i++)
        {
            scanf("%s",&arr);
            if(flag)
            {
                flag=Insert();
            }
        }
        if(flag)
            printf("Case %lld: YES\n",t++);
        else
            printf("Case %lld: NO\n",t++);
        del(root);
    }
    return 0;
}

