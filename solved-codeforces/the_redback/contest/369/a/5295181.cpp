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
    int n,d,p;
   // int a[2000];
    while(~scanf("%d%d%d",&n,&d,&p))
    {
        int i,j,k,l;
        int ret=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                if(d>0)
                    d--;
                else
                    ret++;
            }
            else if(k==2)
            {
                if(p>0)
                    p--;
                else if(d>0)
                    d--;
                else
                    ret++;
            }
        }
        printf("%d\n",ret);
    }
}
