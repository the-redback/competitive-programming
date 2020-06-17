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

main()
{
    int a[20];
    int i,j,k,l,m,n;
    while(scanf("%d",&n)==1)
    {
        int flag=0;
        for(m=0;m<4;m++)
        {
            scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
            k=min(a[0],a[1]);
            l=min(a[2],a[3]);
            if(k+l<=n && flag==0)
            {
                i=k;
                j=l;
                flag=m+1;
            }
        }
        if(flag==0)
            puts("-1");
        else
        {
            printf("%d %d %d\n",flag,i,n-i);
        }
    }
    return 0;
}
