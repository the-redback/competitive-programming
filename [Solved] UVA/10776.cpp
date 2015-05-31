#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

char arr[50];
vector<char>result;
int n,k;
void call(int m)
{
    if(result.size()==n)
    {
        for(int i=0;i<n;i++)
        printf("%c",result[i]);
        puts("");
        return;
    }
    for(int i=m;i<k;i++)
    {
        if(i==m || arr[i]!=arr[i-1])
        {
            result.push_back(arr[i]);
            call(i+1);
            result.pop_back();
        }
    }
}

main()
{
    while(scanf("%s %d",arr,&n)==2)
    {
        k=strlen(arr);
        sort(arr,arr+k);
        call(0);
    }
    return 0;
}
