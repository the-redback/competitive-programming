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
    int l;
    vector <long>v;
    long n,k,fi,ki;
    scanf("%ld %ld",&n,&k);
    l=n;
    while(n--)
    {
        scanf("%ld %ld",&fi,&ki);
        if(ki<=k)
            v.push_back(fi);
        else
        {
            v.push_back(fi-(ki-k));
        }
    }
    sort(v.begin(),v.end());
    printf("%ld\n",v[l-1]);
    return 0;
}
