/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : maruf.2hin
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 *
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
#define inf HUGE_VAL

vector<int>v;
int a[300030];

bool comp(int i,int j)
{
    return a[i]<a[j];
}


int main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    int tc,t=1;
    int i,j,k,n;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            v.push_back(i);
        }
        sort(v.begin(),v.end(),comp);
        int last=-inf;
        for(i=0;i<n;i++)
        {
            k=v[i];
            if(last<a[k])
            {
                last=a[k];
            }
            else
            {
                last++;
                a[k]=last;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}
