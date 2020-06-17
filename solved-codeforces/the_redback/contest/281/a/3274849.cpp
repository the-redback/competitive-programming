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
    char a[10000];
    int i,j,k;
    gets(a);
    if(a[0]>='a' && a[0]<='z')
    {
        a[0]=a[0]-'a'+'A';
    }
    printf("%s\n",a);
    return 0;
}
