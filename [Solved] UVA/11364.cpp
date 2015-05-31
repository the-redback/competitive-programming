#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
main()
{
    vector <int> v;
    int n,t,i,j;
    int sum;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            v.push_back(j);
        }
        sort(v.begin(),v.end());
        j=v[n-1]-v[0];
        printf("%d\n",2*j);
    }
    return 0;
}
