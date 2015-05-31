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
#define NN        100007

#define read(a)   scanf("%lld",&a)


char arr[NN];
string str,ss;
map<string,ll>mymap;

vector<string> split(string str)
{
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream

    vector<string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
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
        mymap.clear();

        read(n);      ///No of word in dictionary.
        ll flag=1;
        for(i=0; i<n; i++)
        {
            scanf("%s",&arr);

            l=strlen(arr);
            if(l>3)
            {
                ss.assign(arr);
                str=ss.substr(1,l-2);
                sort(all(str));
                for(ll i=0,j=1; i<str.size(); i++,j++)
                {
                    arr[j]=str[i];
                }

            }
            mymap[arr]++;
        }

        read(m);   ///No of queries.
        getchar();
        printf("Case %lld:\n",t++);
        for(ll kk=0; kk<m; kk++)
        {
            gets(arr);
            vector<string>strv=split(arr);
            ll res=1;
            for(i=0;i<strv.size();i++)
            {
                ss=strv[i];
                l=(int)ss.size();
                str=ss.substr(1,l-2);
                sort(all(str));
                arr[0]=ss[0];
                arr[l-1]=ss[l-1];
                arr[l]=0;
                for(ll ii=0,jj=1; ii<str.size(); ii++,jj++)
                {
                    arr[jj]=str[ii];
                }
                if(mymap.find(arr)==mymap.end())
                {
                    res=0;
                    break;
                }
                res=res*mymap[arr];
            }
            printf("%lld\n",res);
        }

    }
    return 0;
}
