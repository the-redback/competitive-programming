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
#define inf 9999999
int dp[100][100][100];
bool taken[60][60][60];
char a[100];
char b[100];
char c[100];
int N,M,L;
int check(int x,int y,int z)
{
    int sum=max(x,y);
    sum=max(sum,z);
    return sum;
}
int go(int i,int j,int k)
{
    if(i<0 || j<0 || k<0)
    {
        return 0;
    }
    int &t=dp[i][j][k];
    bool &bl=taken[i][j][k];
    if(bl)
        return t;
    if(a[i]==b[j] && a[i]==c[k])
        t=1+go(i-1,j-1,k-1);
    else
    {
        t=check(go(i-1,j,k),go(i,j-1,k),go(i,j,k-1));
    }
    bl=1;
    return t;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    char aa[100];
    char bb[100];
    char cc[100];
    while(tc--)
    {
        int sum=inf;
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
        N=strlen(a);
        M=strlen(b);
        L=strlen(c);
        memset(taken,0,sizeof(taken));
        sum=go(N-1,M-1,L-1);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
