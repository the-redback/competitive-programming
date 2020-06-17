///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAX 1010
#define inf 99999

main()
{
    int tc,n;
    int a[10010];
    while(scanf("%d",&n)==1)
    {
        int i,j,k;
        if(n==-1)
            return 0;
        int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            printf("-1\n");
        }
        else
        {
            k=sum/n;
            sum=0;
            for(i=0;i<n;i++)
            {
                if(a[i]>k)
                    sum+=a[i]-k;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
