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
    char a[10];
    int i=0;
    while(gets(a))
    {
        i++;
        if(strcmp(a,"*")==0)
            return 0;
        else if(strcmp(a,"Hajj")==0)
            printf("Case %d: Hajj-e-Akbar\n",i);
        else if(strcmp(a,"Umrah")==0)
            printf("Case %d: Hajj-e-Asghar\n",i);
    }
    return 0;
}
