/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : maruf.2hin@gmail.com
 */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010



int main()
{
    int t,tc;
    int n,arr[105],i;
    while(cin>>n)
    {
        for(i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        cout<<arr[0];
        for(i=1; i<n; i++)
         cout<<" "<<arr[i];
        puts("");
    }
    return 0;
}
