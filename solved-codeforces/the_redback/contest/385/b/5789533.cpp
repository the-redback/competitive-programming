/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 5000
char a[NN+7];
main()
{
    int tc,t=1;
    int i,j,k,l,m,n,count,r;
    //scanf("%d",&tc);
    while(~scanf("%s",&a))
    {
        count=0;
        l=strlen(a);
        r=l;
        for(i=l-1;i>2;i--)
        {
            if(a[i]=='r'&&a[i-1]=='a'&&a[i-2]=='e'&&a[i-3]=='b')
            {
                k=r-i;
                r=i;
                n=i-3+1;
                count+=n*k;
            }
        }
        printf("%d\n",count);

    }
    return 0;
}




