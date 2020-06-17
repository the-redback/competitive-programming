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
 int a[100100];
 int b[100100];
 int c[100100];
main()
{
   int i,j,k,l,sum,d,n,m;
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for(i=0;i<n;i++)
   {
       scanf("%d",&c[i]);
   }
   b[n-1]=1;
   b[n]=0;
   a[c[n-1]]=1;
    for(i=n-2;i>=0;i--)
   {
       k=c[i];
       if(a[k]==0)
       {
           a[k]=1;
           b[i]=b[i+1]+1;
       }
       else
            b[i]=b[i+1];
   }
   for(i=0;i<m;i++)
   {
       scanf("%d",&k);
       k=b[k-1]-b[n];
       printf("%d\n",k);
   }
   return 0;
}
