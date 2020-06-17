/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10e9 //10^9
#define meminf 100
#define eps 10e-5
#define NN 1010
int arr[NN];
int a[NN];
int MIN,pivot,k,n;
void check(int pvt)
{
    int i=0,ret=0;
    arr[pvt]=a[pvt];
    for(i=pvt+1; i<n; i++)
    {
        arr[i]=a[i];
        if(arr[i]-k!=arr[i-1])
        {
            arr[i]=arr[i-1]+k;
            ret++;
        }
        if(arr[i]<=0)
            ret=inf;
    }
    if(pvt!=0)
    for(i=pvt-1; i>=0; i--)
    {
        arr[i]=a[i];
        if(arr[i]+k!=arr[i+1])
        {
            arr[i]=arr[i+1]-k;
            ret++;
        }
        if(arr[i]<=0)
            ret=inf;
    }
    if(ret<MIN)
    {
        MIN=ret;
        pivot=pvt;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int j,r,l,m;
    int y,z,u,w,xx,yy,zz,d,h,e;
    int aa,bb,cc,p,dd,res;
    //cin>>tc;
    while(cin>>n>>k)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        MIN=inf;
        for(int i=0; i<n; i++)
        {
            check(i);
        }
        check(pivot);
        printf("%d\n",MIN);
        for(int i=0;i<n;i++)
        {
            if(arr[i]>a[i])
            {
                printf("+ %d %d\n",i+1,arr[i]-a[i]);
            }
            else if(arr[i]<a[i])
            {
                printf("- %d %d\n",i+1,a[i]-arr[i]);
            }
        }
    }
    return 0;
}
