#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
char a[100];
bool comp(char b,char c)
{
    if(tolower(b)==tolower(c))
        return b<c;    //porer ta Capital hole swap kore age jaba
    else
        return tolower(b)<tolower(c);  //eki thakbe
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
        sort(a,a+l,comp);
        do
        {
            puts(a);
        }while(next_permutation(a,a+l,comp));
    }
    return 0;
}
