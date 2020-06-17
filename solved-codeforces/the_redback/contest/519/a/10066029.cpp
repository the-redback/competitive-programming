/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

#define read(a)   scanf("%lld",&a)

char a[111];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        ll white=0;
        ll black=0;

        for(i=0; i<8; i++)
        {
            if(a[i]!='.')
            {
                if(islower(a[i]))
                {
                    if(a[i]=='q')
                        black+=9;
                    if(a[i]=='r')
                        black+=5;
                    if(a[i]=='b')
                        black+=3;

                    if(a[i]=='n')
                        black+=3;
                    if(a[i]=='p')
                        black+=1;
                }
                else
                {
                    if(a[i]=='Q')
                        white+=9;
                    if(a[i]=='R')
                        white+=5;
                    if(a[i]=='B')
                        white+=3;

                    if(a[i]=='N')
                        white+=3;
                    if(a[i]=='P')
                        white+=1;
                }
            }
        }
            for(j=0; j<7; j++)
            {
                scanf("%s",&a);
                for(i=0; i<8; i++)
                {
                    if(a[i]!='.')
                    {
                        if(islower(a[i]))
                        {
                            if(a[i]=='q')
                                black+=9;
                            if(a[i]=='r')
                                black+=5;
                            if(a[i]=='b')
                                black+=3;

                            if(a[i]=='n')
                                black+=3;
                            if(a[i]=='p')
                                black+=1;
                        }
                        else
                        {
                            if(a[i]=='Q')
                                white+=9;
                            if(a[i]=='R')
                                white+=5;
                            if(a[i]=='B')
                                white+=3;

                            if(a[i]=='N')
                                white+=3;
                            if(a[i]=='P')
                                white+=1;
                        }
                    }
                }

            }
            if(black==white)
                cout<<"Draw\n";
            if(black>white)
                cout<<"Black\n";
            if(black<white)
                cout<<"White\n";



        }
        return 0;
    }

