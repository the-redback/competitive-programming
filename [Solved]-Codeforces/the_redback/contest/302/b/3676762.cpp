#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
main()
{
    int i,n,m,c,t;
    long j,k;
    vector <long> v;
    scanf("%d%d",&n,&m);
    for( i=0;i<n;i++)
    {
        scanf("%d %d",&c,&t);
        if(i==0)
            v.push_back(t*c);
        else
            v.push_back((t*c)+v[i-1]);
    }
    i=0;
    while(m--)
    {
        scanf("%ld",&k);
        for( ;i<n;i++)
        {
            if(i==0 && k<=v[i])
                break;
            else if(k<=v[i] && k>=v[i-1])
                break;
        }
        printf("%d\n",i+1);
    }
    return 0;
}
