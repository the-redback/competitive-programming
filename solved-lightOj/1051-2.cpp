///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 22550
#define inf 99999

int dp[51][4][6];
char a[51];
int N;
int go(int pos,int vowel,int cons)
{
    if(vowel==3 || cons==5)
        return 2;
    if(pos==N)
        return 1;
    int &t=dp[pos][vowel][cons];
    if(t!=-1)
        return t;
    int ret;
    if(a[pos]=='?')
    {
        ret= go(pos+1,0,cons+1) | go(pos+1,vowel+1,0);
    }
    else if(a[pos]=='A' || a[pos]=='E' || a[pos]=='I' || a[pos]=='O' || a[pos]=='U')
        ret=go(pos+1,vowel+1,0);
    else
        ret=go(pos+1,0,cons+1);
    t=ret;
    return t;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        scanf("%s",&a);
        memset(dp,-1,sizeof(dp));
        N=strlen(a);
        int ret=go(0,0,0);
        if(ret==2)
            printf("Case %d: BAD\n",t++);
        else if(ret==1)
            printf("Case %d: GOOD\n",t++);
        else
            printf("Case %d: MIXED\n",t++);
    }
    return 0;
}
