/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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
string s,ss,ans;
#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 800

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    int tc,t=1,m;
    double x;
    //scanf("%d",&tc);
    while(cin>>s)
    {
        cin>>ss;
        if((s.size()+ss.size())%2==0)
            puts("Impossible");
        else
        {
            for(i=0;i<s.size();i++)
            {
                if(s[i]=='|')
                    {
                        r=i;
                        break;
                    }
            }
            int left=r;
            int right=s.size()-left-1;
            if(left>right+ss.size() || right>left+ss.size())
            {
                puts("Impossible");
                return 0;
            }
            ans="";
            k=-1;
            int mid=(s.size()+ss.size())/2;
            for(i=0;i<r;i++)
                ans.push_back(s[i]);
            for(i=0;ans.size()!=mid;i++)
                ans.push_back(ss[i]),k=i;
            ans.push_back('|');
            for(i=r+1;i<s.size();i++)
                ans.push_back(s[i]);
            for(i=k+1;i<ss.size();i++)
                ans.push_back(ss[i]);
            printf("%s\n",ans.c_str());
        }

    }
    return 0;
}





