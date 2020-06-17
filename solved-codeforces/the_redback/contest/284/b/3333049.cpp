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
    int m,n,i,j,k,A=0,F=0,I=0;
    char a[200001];
    scanf("%d",&n);
    getchar();
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='A')
            A++;
        else if(a[i]=='I')
            I++;
    }
    if(I==0)
    {
        printf("%d\n",A);
    }
    else if(I==1)
        printf("%d\n",I);
    else
        printf("0\n");
}
