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

main()
{
    stack<int>s;
    queue<int>q;
    queue<int>parent;
    int i,j,k,l,n,t=0;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        while(scanf("%d",&k))
        {
            if(k==0)
                break;
            parent.push(k);
            for(i=2; i<=n; i++)
            {
                scanf("%d",&k);
                parent.push(k);
            }
            for(i=1; i<=n; i++)
                q.push(i);
            int flag=0;
            while(q.size()!=0 || parent.size()!=0)
            {
                if(q.front()==parent.front())
                {
                    q.pop();
                    parent.pop();
                }
                else if(s.size()!=0 && s.top()==parent.front())
                {
                    s.pop();
                    parent.pop();
                }
                else if(q.size()==0 && parent.front()!=s.top())
                {
                    flag=1;
                    break;
                }
                else
                {
                    s.push(q.front());
                    q.pop();
                }
            }
            if(s.size()==0 && flag==0)
                puts("Yes");
            else
                puts("No");
            while(q.size()!=0)
                q.pop();
            while(s.size()!=0)
                s.pop();
            while(parent.size()!=0)
                parent.pop();
        }
        printf("\n");
    }
    return 0;
}
