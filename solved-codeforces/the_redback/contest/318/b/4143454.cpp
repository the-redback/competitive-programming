#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
char a[1000010];
main()
{
    vector <int> v;
    vector <int> v2;
    char b[20];
    __int64 sum;
    int i,j,l,flag;
    v.push_back(0);
    v2.push_back(0);
    gets(a);
    l=strlen(a);
    flag=0;
    for(i=0;i<l;i++)
    {
        if(a[i]=='l' && i>=4)
        {
            j=0;
            b[j++]=a[i-4];
            b[j++]=a[i-3];
            b[j++]=a[i-2];
            b[j++]=a[i-1];
            b[j++]=a[i];
            b[j]=0;
            if(strcmp(b,"metal")==0)
            {
                v2.push_back(v2[v2.size()-1]+1);
                v.push_back(v[v.size()-1]);
            }
        }
        else if(a[i]=='y' && i>=4)
        {
            j=0;
            b[j++]=a[i-4];
            b[j++]=a[i-3];
            b[j++]=a[i-2];
            b[j++]=a[i-1];
            b[j++]=a[i];
            b[j]=0;
            if(strcmp(b,"heavy")==0)
            {
                v.push_back(v[v.size()-1]+1);
                v2.push_back(v2[v2.size()-1]);
            }
        }
    }
    sum=0;
    for(i=1;i<v.size();i++)
    {
        if(v[i]-v[i-1]==1)
        {
            sum+=(v2[v2.size()-1]-v2[i]);
        }
    }
    printf("%I64d\n",sum);
    return 0;
}