#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class TypingDistance
{
    public:
    int minDistance(string a,string b)
    {
        int sum,k,l,m,n;
        l=a.size();
        k=b.size();
        sum=0;
        int j=0;
        for(m=0;m<k;m++)
        {
            for(n=0;n<l;n++)
            {
               if(b[m]==a[n])
               {
                   if(m==0)
                   {
                       j=n;
                   }
                   else
                   {
                       sum+=abs(n-j);
                       j=n;
                   }
               }
            }
        }
        return sum;
    }
};
