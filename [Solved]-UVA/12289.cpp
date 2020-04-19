#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));

main()
{
    char a[10];
    int i,j,l,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        l=strlen(a);
        if(l==5)
            puts("3");
        else if(l==3)
        {
            if(a[0]=='o' && a[1]=='n'||a[0]=='o' && a[2]=='e'||a[1]=='n' && a[2]=='e')
                puts("1");
            else
                puts("2");
        }
    }
    return 0;
}
