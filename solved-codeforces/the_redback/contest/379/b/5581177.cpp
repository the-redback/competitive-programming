/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
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
int b[333];
int c[333];
int main()
{
    int tc,t=1;
    int i,j,k,n;
    int left=0;
    int a[333];
    string s;
    while(~scanf("%d",&n))
    {
        int S=0;
        int ss=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            S+=a[i];
        }
        s="";
        int flag=0;
        while(ss<S)
        {
            for(j=0; j<n; j++)
            {
                if(ss<S)
                {
                    if(c[j]<a[j])
                    {
                        c[j]+=1;
                        s+="P";
                        ss++;
                    }
                    if(j!=n-1 && ss<S)
                        s+="R";
                }
            }

            if(c[n-1]!=a[n-1])
            {
                s+="L";
                if(c[n-2]!=a[n-2])
                {
                    c[n-2]++;
                    s+="P";
                    ss++;
                }
                s+="R";
            }
            for(j=n-1; j>=0; j--)
            {
                if(ss<S)
                {
                    if(c[j]<a[j])
                    {
                        c[j]++;
                        s+="P";
                        ss++;
                    }
                    if(j!=0 && ss<S)
                        s+="L";
                }
            }
            if(c[0]!=a[0])
            {
                s+="R";
                if(c[1]!=a[1])
                {
                    c[1]++;
                    s+="P";
                    ss++;
                }
                s+="L";
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
