#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

main()
{
    char a[1001],b[1001],c[1001];
    int i,j,k,l,m,n;
    while(gets(a))
    {
        gets(b);
        m=strlen(a);
        n=strlen(b);
        sort(a,a+m);
        sort(b,b+n);
        l=0;
        for(i=0,j=0;i<m && j<n;)
        {
            while(a[i]==' ')
            {
                i++;
                if(i>=m)
                break;
            }
            while(a[i]<b[j])
            {
                i++;
                if(i>=m)
                {
                    break;
                }
            }
            while(a[i]>b[j])
            {
                j++;
                if(j>=n)
                {
                    break;
                }
            }
            if(a[i]==b[j] && a[i]!=' ')
            {
                c[l]=a[i];
                l++;
                i++;
                j++;
            }
        }
        c[l]='\0';
        printf("%s\n",c);
    }
    return 0;
}
