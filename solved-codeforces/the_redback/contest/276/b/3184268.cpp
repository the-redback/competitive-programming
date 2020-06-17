#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

main()
{
    char a[1001];
    int i,j,k,l=0;
    int b[150];
    memset(b,0,sizeof(b));
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='a' && a[i]<='z')
        {
            j=a[i];
            b[j]++;
        }
    }
    for(i=60;i<150;i++)
    {
        if(b[i]%2!=0)
        {
            l++;
        }
    }
    if(l%2!=0 || l==0)
        printf("First\n");
    else
        printf("Second\n");
        return 0;
}
