#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

main()
{
    int x,y,z,sum;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d %d",&x,&y,&z);
            sum+=x*z;
        }
        printf("%d\n",sum);
    }
    return 0;
}
