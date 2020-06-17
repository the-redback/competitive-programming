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
    char a[10000];
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int i,j,k,l,m,n;
        scanf("%d",&l);
        getchar();
        gets(a);
        sort(a,a+l);
        printf("Case %d: ",t++);
            k=0;
            n=0;
            int dr=0;
            int ab=0;
            for(i=0;i<l;i++)
            {
                if(a[i]=='B')
                    k++;
                else if(a[i]=='W')
                    n++;
                else if(a[i]=='T')
                    dr++;
                else if(a[i]=='A')
                    ab++;
            }
            if(ab==l)
                puts("ABANDONED");
            else if(n>k && k>0 || n>k && dr>0)
                printf("WWW %d - %d\n",n,k);
            else if(k>n && n>0 || k>n && dr>0)
                printf("BANGLADESH %d - %d\n",k,n);
            else if(k+ab==l)
                puts("BANGLAWASH");
            else if(n+ab==l)
                puts("WHITEWASH");
            else if(n==k)
                printf("DRAW %d %d\n",n,dr);
    }
    return 0;
}
