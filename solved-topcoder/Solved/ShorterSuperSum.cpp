#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
int call(int k,int n)
{
    int sum=0,i=0;
    if(k==0)
        return (n*(n+1))/2;
    while(i!=n)
    {
        sum+=call(k-1,i+1);
        i++;
    }
    return sum;
}

struct ShorterSuperSum
{
    int calculate(int k, int n)
    {
        int ret=0;
        ret=call(k-1,n);
        return ret;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
