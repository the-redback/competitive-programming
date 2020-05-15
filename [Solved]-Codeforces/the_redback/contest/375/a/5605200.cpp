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

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))


main()
{
    int tc,t=1;
    int i,j,k,l;
    char a[1000010];
    int b[]={1,6,8,9};
    int s[11];
    vector<int>v;
    while(gets(a))
    {
        mem(s,-1);
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            int k=a[i]-'0';
            if(k==1 || k==6||k==8||k==9)
            {
                if(s[k]!=-1)
                    v.push_back(k);
                else
                    s[k]=1;
            }
            else
                v.push_back(k);
        }

        int carry=0;

        sort(v.rbegin(),v.rend());

        for(i=0;i<v.size();i++)
        {
            if(v[i]==0)
                break;
            carry=carry*10+v[i];
            carry%=7;
            printf("%d",v[i]);
        }
        sort(b,b+4);
        int sum=carry;
        do
        {
            carry=sum*10000;
            carry+=b[0]*1000;
            carry+=b[1]*100;
            carry+=b[2]*10;
            carry+=b[3];
            carry%=7;
            if(carry==0)
            {
                printf("%d%d%d%d",b[0],b[1],b[2],b[3]);
                break;
            }
        }while(next_permutation(b,b+4));

        while(i<v.size())
        {
            printf("%d",v[i]);
            i++;
        }
        puts("");
    }
    return 0;
}
