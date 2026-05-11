/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
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
