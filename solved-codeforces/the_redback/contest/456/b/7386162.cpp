/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1000050


char a[NN];

int check(void)
{
    int ret=0,i;
    for(i=0;a[i]!=0;i++)
        ret+=a[i]-'0';
    return ret;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t,tc;
    //cin>>tc;
    int sum,ret;
    int i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        l=strlen(a);
        if(l<=1)
        {
            k=a[0]-'0';
            sum=pow(1,k);
            sum=sum%5;
            sum+=pow(2,k);
            sum=sum%5;
            sum+=pow(3,k);
            sum=sum%5;
            sum+=pow(4,k);
            sum=sum%5;
            ret=sum%5;
        }
        else
        {
            sum=1;
            k=(a[l-2]-'0')*10+(a[l-1]-'0');
            m=check();
            n=a[l-1]-'0';
            if(k%4==0)
            {
                sum=1+1+1+1;
                ret=sum%5;
            }
            else if(m%3==0)
            {
                sum=3+2+4+1;
                ret=sum%5;
            }
            else if(n%2==0)
            {
                sum=4+4+1+1;
                ret=sum%5;
            }
            else
            {
                sum=2+3+4+1;
                ret=sum%5;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}
