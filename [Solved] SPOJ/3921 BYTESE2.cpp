///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define inf 999999999;
vector<long>v;
vector<long>u;
main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,i,j;
        long k,l;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%ld%ld",&k,&l);
            u.push_back(k);
            v.push_back(l);
        }
        sort(v.rbegin(),v.rend());
        sort(u.rbegin(),u.rend());
        int s=-inf;
        int sum=0;
        while(1)
        {
            if(u.size()>0)
            {
                if(u[u.size()-1]<v[v.size()-1])
                {
                    sum++;
                    s=max(s,sum);
                    u.pop_back();
                }
                else
                {
                    sum--;
                    s=max(s,sum);
                    v.pop_back();
                }
            }
            else if(v.size()>0)
            {
                    sum--;
                    s=max(s,sum);
                    v.pop_back();
            }
            else
                break;
        }
        printf("%d\n",s);
    }
    return 0;
}
