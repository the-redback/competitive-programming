#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
main()
{
    stack<char>s;
    char a[500];
    int tc;
    cin>>tc;
    getchar();
    while(tc--)
    {
        gets(a);
        int l=strlen(a);
        while(s.size())
            s.pop();
        int flag=0;
        for(int i=0;i<l;i++)
        {
            if(a[i]=='('||a[i]=='[')
               s.push(a[i]);
            else if(a[i]==')')
            {
                if(s.size() && s.top()=='(')
                   s.pop();
                else
                    flag=1;
            }
            else if(a[i]==']')
            {
                if(s.size() &&s.top()=='[')
                   s.pop();
                else
                    flag=1;
            }
            if(flag)
                break;
        }
        if(flag||s.size())
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
