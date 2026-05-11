/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
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
