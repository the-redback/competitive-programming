#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
char ans[2000];
char a[2000];
int div(int n)
{
    int i,j,t=0,l,d=0,r=0;
    int rem=0;
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        rem=(rem*10)+a[i]-48;
        if(rem>=n||r!=0)
        {
            j=rem/n;
            rem=rem%n;
            ans[d]=j+48;
            d++;
            r=1;
        }
    }
    if(d==0)
    {
        ans[d]='0';
        d++;
    }
    ans[d]='\0';
    return rem;
}

int add(int n)
{
    int i,j,k,l,hand=n;
    l=strlen(a);
    for(i=l-1,j=0;i>=0;i--,j++)
    {
        k=a[i]-'0'+hand;
        hand=k/10;
        ans[j]=k%10+'0';
    }
    while(hand>0)
    {
        ans[j]=hand%10+'0';
        hand/=10;
        j++;
    }
    ans[j]=0;
    reverse(ans,ans+strlen(ans));
}

main()
{
    int i,j,k,l,n,m;
    while(~scanf("%d%d",&k,&n))
    {
        if(k==1)
        {
            printf("%d\n",n);
            continue;
        }
        if(n==0 && k!=1)
        {
            puts("No solution");
            continue;
        }
        if(n==9)
            n=0;
        a[0]='1';
        for(i=1;i<k;i++)
        {
            a[i]='0';
        }
        a[i]=0;
        k=div(9);
        add((9-k)+n);
        puts(ans);
    }
    return 0;
}
