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
#define NN        100009

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

struct D
{
    char a[55],b[55];
    int id;
}arr[100009],brr[NN];

bool comp(D ac,D bc)
{
    return ac.id < bc.id;
}

char aa[55],bb[55],last[55];

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",&aa,&bb);
        if(strcmp(aa,bb)<0)
        {
            strcpy(arr[i].a,aa);
            strcpy(arr[i].b,bb);
        }
        else
        {
            strcpy(arr[i].a,bb);
            strcpy(arr[i].b,aa);
        }
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        arr[j-1].id=i;
    }
    sort(arr,arr+n,comp);

    strcpy(last,arr[0].a);

    for(i=1;i<n;i++)
    {
        int fst=strcmp(arr[i].a,last);
        int snd=strcmp(arr[i].b,last);
        if(fst<0 && snd<0)
        {
            puts("NO");
            return 0;
        }
        if(fst>0)
            strcpy(last,arr[i].a);
        else
            strcpy(last,arr[i].b);
    }
    puts("YES");
    return 0;
}
