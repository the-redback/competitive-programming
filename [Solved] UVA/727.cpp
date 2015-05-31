#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
stack<char> mid;
queue <char> ans;

main()
{
    int i=0,n;
    char ch[10];
    scanf("%d",&n);
    getchar();
    getchar();
    while(n--)
    {
        i++;
        mid.push('(');
        while(gets(ch) && strlen(ch))
        {
            if(ch[0]>='0' && ch[0]<='9')
            {
                ans.push(ch[0]);
            }
            else if(ch[0]==')')
            {
                while(mid.top()!='(')
                {
                    ans.push(mid.top());
                    mid.pop();
                }
                mid.pop();
            }
            else if(ch[0]=='+' || ch[0]=='-')
            {
                while(mid.top()!='(')
                {
                    ans.push(mid.top());
                    mid.pop();
                }
                mid.push(ch[0]);
            }
            else if(ch[0]=='*' || ch[0]=='/')
            {
                while(mid.top()=='/' || mid.top()=='*')
                {
                    ans.push(mid.top());
                    mid.pop();
                }
                mid.push(ch[0]);
            }
            else
                mid.push(ch[0]);
        }
        while(mid.top()!='(')
        {
            ans.push(mid.top());
            mid.pop();
        }
        mid.pop();
        if(i!=1)
            puts("");
        while(ans.size())
        {
            printf("%c",ans.front());
            ans.pop();
        }
        puts("");
    }
    return 0;
}
