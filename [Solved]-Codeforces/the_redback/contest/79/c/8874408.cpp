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
#define NN        30100

#define read(a)   scanf("%lld",&a)

int arr[100010];
char a[100010];
char b[100];
vector<string>v;
int N;

bool comp(string s,string ss)
{
    return (int)s.size()<(int)ss.size();
}

/*
int check(int pos)
{
    int l=strlen(a);
    int i,j,k;
    int mn=inf;

    for(j=0; j<N; j++)
    {
        int fl=0;
        for(i=pos,k=0; k<v[j].size() && i<l; k++,i++)
        {
            if(a[i]!=v[j][k])
            {
                fl=1;
                break;
            }
        }
        if(fl==0 && k==v[j].size())
        {
            mn=min(mn,i);
            return mn;
        }
    }
    return mn;
}
*/

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(gets(a))
    {
        //l=strlen(a);

        scanf("%d",&n);
        getchar();
        N=n;
        for(i=0; i<n; i++)
        {
            gets(b);
            v.pb(b);
        }
        sort(all(v),comp);
        int anslast=0;
        int last=-1;
        int len=0;
        l=strlen(a);
        len=0;

        for(i=l; i>=0; i--)
        {
            ll mn=inf;
            ll pos=i,r;
            for(j=0; j<N; j++)
            {
                int fl=0;
                for( r=pos,k=0; k<v[j].size() && r<l; k++,r++)
                {
                    if(a[r]!=v[j][k])
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl==0 && k==v[j].size())
                {
                    mn=min(mn,r);
                    break;;
                }
            }
            ll mid=mn;
            if(mid==inf)
                arr[i]=l;
            else
                arr[i]=mid-1;
            if(i==l-1)
            {
                if(arr[l-1]-(l-1)>0)
                {
                    len=arr[l-1]-(l-1);
                    anslast=l-1;
                }
            }
            else
            {
                arr[i]=min(arr[i],arr[i+1]);
                if(arr[i]-i>len)
                {
                    len=arr[i]-i;
                    anslast=i;
                }
            }

        }

        printf("%d %d\n",len,anslast);

//        v.clear();
    }
    return 0;
}
