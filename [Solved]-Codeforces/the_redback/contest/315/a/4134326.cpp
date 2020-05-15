#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

main()
{
    vector <int> v;
    vector <int> v2;
    int i,j,k,l,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&k,&l);
        v.push_back(k);
        v2.push_back(l);
    }
    for(i=0;i<v2.size();i++)
    {
        for(j=0;j<v.size();j++)
        {
            if(v[j]==v2[i] && i!=j)
                v[j]=-1;
        }
    }
    n=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i]!=-1)
            n++;
    }
    printf("%d\n",n);
    return 0;
}
