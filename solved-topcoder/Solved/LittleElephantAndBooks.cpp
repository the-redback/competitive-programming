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

struct LittleElephantAndBooks
{
    int getNumber(vector <int> pages, int number)
    {
        int ret;
        sort(pages.begin(),pages.end());
        int i,j,k;
        ret=0;
        for(i=0; i<number-1; i++)
            ret+=pages[i];
        ret+=pages[number];
        return ret;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
