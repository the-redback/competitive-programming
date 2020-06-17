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
    int view[20011];
    int parent[20011];
    vector <int> v[20010];
    vector <int> data;
    queue<int>q;
    int tc,t,n,m,i,j,k,l,sum;
    int tw,on;
    cin>>tc;
    for(t=1;t<=tc;t++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&j,&k);
            v[j].push_back(k);
            v[k].push_back(j);
            data.push_back(k);
            data.push_back(j);
        }
        sum=0;
        memset(view,0,sizeof(view));
        memset(parent,-1,sizeof(parent));
        for(i=0;i<data.size();i++)
        {
            on=0,tw=0;
            l=data[i];
            if(view[l]==0)
            {
                q.push(l);
                l=data[i];
                 parent[l]=0;
                while(q.size()!=0)
                {
                    k=q.front();
                    q.pop();
                    l=parent[k];
                    l=view[l];
                    if(l==0||l==2)
                    {
                        on++;
                        view[k]=1;
                    }
                    else if(l==1)
                    {
                        tw++;
                        view[k]=2;
                    }
                    for(j=0;j<v[k].size();j++)
                        {
                            m=v[k][j];
                            if(parent[m]==-1)
                            {
                                q.push(v[k][j]);
                                parent[m]=k;
                            }
                        }
                }
                sum+=max(tw,on);
            }
        }
        printf("Case %d: %d\n",t,sum);
                data.clear();
        for(i=0;i<20010;i++)
            v[i].clear();
    }
    return 0;
}
