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
int a[100050];
long long mn=99999999999999;
long long sum;
main()
{

    int i,j,k,l,m,n;
    while(scanf("%d%d",&n,&k)==2)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int flag=-1;
        mn=99999999999999;
        if(k==n)
        {
            for(i=0; i<n; i++)
                if(mn>a[i])
                {
                    mn=a[i];
                    flag=i+1;
                }

        }
        else
        {
            for(i=0; i<k; i++)
            {
                sum=0;
                for(j=i; j<n; j+=k)
                    sum+=a[j];
                if(sum<mn)
                {
                    mn=sum;
                    flag=i+1;
                }
            }
        }
        printf("%d\n",flag);

    }
    return 0;
}
