#include<bits/stdc++.h>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

char aaa[3009],frstc;
int n,frstin;
int main()
{
     scanf("%d",&n);
     scanf("%s",&aaa);
     bool fl=true;
     int res=0,i;
     for(i=0;i<n;i++)
     {

         if(fl&&aaa[i]!='.')
         {
             fl=false;
             if(aaa[i]=='L')
             {
                 res=0;
                  frstc='L';
                  frstin=i;
             }
             else
             {
                 frstc='R';
                 res+=i;
                 frstin=i;
             }
            // cout<<frstc<<"jjj"<<endl;

         }
         else if(fl==false&&aaa[i]!='.')
         {
             if(aaa[i]=='L')
             {
                 if(frstc=='L')
                 {
                     frstin=i;
                 }
                 else
                 {
                     int df=(i-frstin-1);
                  //   cout<<df<<"rl"<<endl;
                     if(df%2)
                     {
                         res++;
                     }
                     frstc='L';
                     frstin=i;
                 }
             }
             else
             {
                 if(frstc=='L')
                 {

                     res+=(i-frstin-1);
                     frstc='R';
                     frstin=i;
                 }
                 else
                 {
                     frstin=i;
                 }
             }

         }
     }
     //cout<<frstc;
    if(frstc=='L')
    {
        res+=(n-frstin-1);
    }
    if(fl)
        res=n;
    cout<<res<<endl;
    return 0;
}
