#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
main()
{
    char s[10000];
    int i,j,k,l,n,sum,max;
    while(gets(s))
    {
        max=0;
        sum=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]>='0' && s[i]<='9' )
            {
                sum+=s[i]-'0';
                if(max<s[i]-'0')
                    max=s[i]-'0';
            }
            else if(s[i]>='A' && s[i]<='Z' )
            {
                sum+=s[i]-'A'+10;
                if(max<s[i]-'A'+10)
                    max=s[i]-'A'+10;
            }
            else if(s[i]>='a' && s[i]<='z' )
            {
                sum+=s[i]-'a'+36;
                if(max<s[i]-'a'+36)
                    max=s[i]-'a'+36;
            }
        }
        if(max==0)
            n=1;
        else
            n=max;
        while(n<=62)
        {
            if(sum%n==0)
                break;
            else
                n++;
        }
        if(n==63)
            printf("such number is impossible!\n");
        else
            printf("%d\n",n+1);
    }
    return 0;
}
