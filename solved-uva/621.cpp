#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

main()
{
    int t,l;
    char a[10000];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        scanf("%s",&a);
        l=strlen(a);
        if(l==1)
        {
            if(a[0]=='1' || a[0]=='4')
                puts("+");
        }
        else if(l==2 && a[0]=='7' && a[1]=='8' )
            puts("+");
        else if(a[l-2]=='3' && a[l-1]=='5')
            puts("-");
        else if(a[0]=='9' && a[l-1]=='4')
            puts("*");
        else if(a[0]=='1' && a[1]=='9' && a[2]=='0')
            puts("?");
    }
    return 0;
}
