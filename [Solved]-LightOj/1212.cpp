#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <deque>
using namespace std;
main()
{
    deque<int>v;
    int i,j,k,l,m,n,t,T;
    char a[15];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        v.clear();
        scanf("%d %d",&n,&m);
        k=0;
        printf("Case %d:\n",t);
        while(m--)
        {
            scanf("%s",&a);
            if(strcmp(a,"pushLeft")==0 || strcmp(a,"pushRight")==0)
            {
                scanf("%d",&j);
                if(v.size()<n)
                {
                    if(strcmp(a,"pushLeft")==0)
                    {
                        v.push_front(j);
                        printf("Pushed in left: %d\n",j);
                    }
                    else if(strcmp(a,"pushRight")==0)
                    {
                        v.push_back(j);
                        printf("Pushed in right: %d\n",j);
                    }
                }
                else
                {
                    printf("The queue is full\n");
                }
            }
            else if(strcmp(a,"popLeft")==0 || strcmp(a,"popRight")==0)
            {
                if(v.size()>0)
                {
                    if(strcmp(a,"popLeft")==0)
                    {
                        printf("Popped from left: %d\n",v[0]);
                        v.pop_front();
                    }
                    else if(strcmp(a,"popRight")==0)
                    {
                        printf("Popped from right: %d\n",v[v.size()-1]);
                        v.pop_back();
                    }
                }
                else
                {
                    puts("The queue is empty");
                }

            }
        }
    }
    return 0;
}
