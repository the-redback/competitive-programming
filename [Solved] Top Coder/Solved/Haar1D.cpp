#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector <int> call(vector <int> v,int n,int m)
{
    if(n==0)
        return v;
    int j;
    vector <int>c;
    c=v;
    j=0;
    for(int i=0;i<m;i+=2)
    {
        v[j++]=c[i]+c[i+1];
    }
    for(int i=0;i<m;i+=2)
    {
        v[j++]=c[i]-c[i+1];
    }
    return call(v,n-1,m/2);
}
class Haar1D
{
    public:
    vector <int> transform(vector <int> v,int n)
    {
        v=call(v,n,v.size());
        return v;
    }
};

main()
{
    int a[]={1,2,3,5};
    vector<int> v(a,a+4);
    Haar1D d;
    d.transform(v,2);
    return 0;
}
