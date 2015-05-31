#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <long> v;
main()
{
    long i,j,n,k,count,l;
    v.push_back(0);
    for(i=1;1;i++)
    {
        k=v[i-1]+i;
        v.push_back(k);
        if(k>=10000000)
            break;
    }
    while(scanf("%ld",&n)==1)
    {
        for(i=1;1;i++)
        {
            if(v[i]>=n)
            {
                k=i;
                break;
            }
        }
        l=v[k]-n;
        j=1+l;
        l=k-l;
        if(k%2!=0)
            printf("TERM %ld IS %ld/%ld\n",n,j,l);
        else
            printf("TERM %ld IS %ld/%ld\n",n,l,j);
    }
}
