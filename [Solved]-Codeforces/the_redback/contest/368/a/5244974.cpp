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
 int a[1000];
main()
{
   int i,j,k,l,sum,d,n,m;
   scanf("%d%d",&n,&d);
   for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    sort(a,a+n);
    sum=0;
    for(i=0;i<n && i<m;i++)
    {
        sum+=a[i];
    }
    sum-=(m-i)*d;
    printf("%d\n",sum);
    return 0;

}
