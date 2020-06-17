/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 1000000000
#define NN 1000000

vector<int>v;
queue<int>q,p;
int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m,x,y,cnt=n;
    long long mx=0;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
            scanf("%d",&k),p.push(k);
        for(i=0;i<m;i++)
            scanf("%d",&k),q.push(k);
        while(q.size() && p.size())
        {
            k=p.front();
            l=q.front();
            if(k<=l)
            {
                q.pop();
                p.pop();
            }
            else
                q.pop();
        }
        printf("%d\n",p.size());

    }
    return 0;

}
