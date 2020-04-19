#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
char a[100];
bool view[100];
int N;
vector <char>v;
bool comp(char b,char c)
{
    if(tolower(b)==tolower(c))
        return b<c;    //porer ta Capital hole swap kore age jabe
    else
        return tolower(b)<tolower(c);  //eki thakbe
}

void call(int k)
{
    int i;
    if(k==N)
    {
        for(i=0;i<N;i++)
            printf("%c",v[i]);
        puts("");
        return;
    }
    for(i=0;i<N;i++)
    {
        if(!view[i])
        {
            if(i==0||a[i]!=a[i-1] || view[i-1])
            {
                view[i]=1;
                v.push_back(a[i]);
                call(k+1);
                view[i]=0;
                v.pop_back();
            }
        }
    }
    return;
}


main()
{
    int l,T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        gets(a);
        l=strlen(a);
        N=l;
        sort(a,a+l,comp);
        mem(view,0);
        call(0);
    }
    return 0;
}
