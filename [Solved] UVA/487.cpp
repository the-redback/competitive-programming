#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
char a[30][30];
int N,M;
vector<string>vv;
string s;
vector<char>v;
int xx[]= {-1,-1,-1,0,0,1,1,1};
int yy[]= {-1,0,1,-1,1,-1,0,1};
void call(int i,int j)
{
    if(i<0 || j<0||i>=N||j>=N)
        return;
    if(v.size()>=3)
    {
        s.clear();
        for(int k=0; k<v.size(); k++)
        {
            s+=v[k];
        }
        vv.push_back(s);
    }
    for(int k=0; k<8; k++)
    {
        int r=i+xx[k];
        int c=j+yy[k];
        if(r>=0 && c>=0 && r<N && c<N && a[r][c]>a[i][j])
        {
            v.push_back(a[r][c]);
            call(r,c);
            v.pop_back();
        }
    }
    return;
}

bool comp(string s, string x)
{
    if(s.size()==x.size())
        return s<x;
    else
        return s.size()<x.size();
}

main()
{
    int tc,n;
    int t=0;
    scanf("%d",&tc);
    for(t=0; t<tc; t++)
    {
        scanf("%d",&N);
        int i,j,k;
        getchar();
        for(i=0; i<N; i++)
            gets(a[i]);
        vv.clear();
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                v.clear();
                v.push_back(a[i][j]);
                call(i,j);
            }
        }
        sort(vv.begin(),vv.end(),comp);
        if(t!=0)
            puts("");
        for(i=0; i<vv.size(); i++)
        {
            if(i==0 || vv[i]!=vv[i-1])
                printf("%s\n",vv[i].c_str());
        }
    }
    return 0;
}
