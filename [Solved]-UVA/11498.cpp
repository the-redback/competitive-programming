#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
main()
{
    int i,j,flag,k,l,x,n,y;
    while(scanf("%d",&n))
    {
        if(n==0)
            return 0;
        scanf("%d %d",&k,&l);
        while(n--)
        {
            scanf("%d %d",&x,&y);
            if(x==k || y==l)
            {
                puts("divisa");
            }
            else if(x>k)
            {
                if(y>l)
                    puts("NE");
                else
                    puts("SE");
            }
            else
            {
                if(y>l)
                    puts("NO");
                else
                    puts("SO");
            }
        }
    }
    return 0;
}
