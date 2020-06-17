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


int main()
{
    vector<int>x;
    vector<int>y;
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&k,&l);
        x.push_back(k);
        y.push_back(l);
    }
    i=0;j=0;
    k=n;
    while(k)
    {
        if(x[i]<y[j])
        {
            i++;
            k--;
        }
        else if(x[i]>y[j])
        {
            j++;
            k--;
        }
    }
    k=n/2;
    for(l=0;l<n;l++)
    {
        if(l<i || l<k)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    for(l=0;l<n;l++)
    {
        if(l<j || l<k)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
