#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

main()
{
    char a[100];
    int i,l;
    while(gets(a))
    {
        if(a[0]=='#')
        {
            break;
        }
        l=strlen(a);
        if(next_permutation(a,a+l))
        {
            for(i=0;i<l;i++)
            {
                printf("%c",a[i]);
            }
            printf("\n");
        }
        else
        {
            printf("No Successor\n");
        }
    }
}
