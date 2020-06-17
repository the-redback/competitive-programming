#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

int main ()
{
  int i,j,k,l,m,n,h;
  int a[200];
  a[0]=0;
  while(~scanf("%d",&n))
  {
      for(i=1;i<=n;i++)
      {
          scanf("%d",&k);
          a[i]=a[i-1]+k;
      }
      scanf("%d%d",&m,&h);
      int flag=0;
      for(i=1;i<=n;i++)
      {
          k=a[i];
          j=a[n]-k;
          if(k>=m && k<=h &&j>=m &&j<=h)
          {
              flag=1;
              printf("%d\n",i+1);
          }
          if(flag)
            break;
      }
      if(!flag)
        puts("0");
  }
}