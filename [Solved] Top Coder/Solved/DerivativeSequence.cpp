#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class DerivativeSequence
{
    public:
      vector <int>  derSeq(vector <int> v,int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<v.size()-1;j++)
            {
                v[j]=v[j+1]-v[j];
            }
            v.pop_back();
        }
        return v;
    }
};

main()
{
    vector <int>a={5,6,3,9,-1};
    DerivativeSequence d;
    d.derSeq(a,1);
    return 0;
}
