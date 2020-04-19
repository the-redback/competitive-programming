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
    long v,j,n,k,count,l;
    while(scanf("%ld",&n)==1)
    {
        k=ceil(((double)sqrt(1+8*n)-1.0)/(double)2.0);
        v=(k*(k+1))/2.0;
        l=v-n;
        j=1+l;
        l=k-l;
        if(k%2!=0)
            printf("TERM %ld IS %ld/%ld\n",n,j,l);
        else
            printf("TERM %ld IS %ld/%ld\n",n,l,j);
    }
}
