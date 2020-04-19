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

int dp[60][6][10];
char a[1010];
int  mid,ans,sum;
int N,K,S;
int good(int pos,int vowel,int cons)
{
    if(vowel==3 || cons==5)
        return 0;
    if(pos==N)
        return 1;
    int &t=dp[pos][vowel][cons];
    if(t!=-1)
        return t;
    int ret;
    if(a[pos]=='?')
    {
        ret=good(pos+1,0,cons+1);
        ret=max(ret,good(pos+1,vowel+1,0));
    }
    else if(a[pos]=='A' || a[pos]=='E' || a[pos]=='I' || a[pos]=='O' || a[pos]=='U')
        ret=good(pos+1,vowel+1,0);
    else
        ret=good(pos+1,0,cons+1);
    t=ret;
    return t;
}

int bad(int pos,int vowel,int cons)
{

    if(vowel==3 || cons==5)
        return 1;
    if(pos==N)
        return 0;
    int &t=dp[pos][vowel][cons];
    if(t!=-1)
        return t;
    int ret;
    if(a[pos]=='?')
    {
        ret=bad(pos+1,0,cons+1);
        ret=max(ret,bad(pos+1,vowel+1,0));
    }
    else if(a[pos]=='A' || a[pos]=='E' || a[pos]=='I' || a[pos]=='O' || a[pos]=='U')
        ret=bad(pos+1,vowel+1,0);
    else
        ret=bad(pos+1,0,cons+1);
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
        int n,l,i,j;
        scanf("%s",&a);
        memset(dp,-1,sizeof(dp));
        N=strlen(a);
        int gd=good(0,0,0);
        memset(dp,-1,sizeof(dp));
        int bd=bad(0,0,0);
        if(gd & bd)
            printf("Case %d: MIXED\n",t++);
        else if(gd)
            printf("Case %d: GOOD\n",t++);
        else if(bd)
            printf("Case %d: BAD\n",t++);
    }
    return 0;
}
