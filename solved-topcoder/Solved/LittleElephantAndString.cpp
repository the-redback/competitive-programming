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

struct LittleElephantAndString
{
    int getNumber(string A, string B)
    {
        int ret;
        int i,j,k,flag=0;
        string s=B;
        for(i=0; i<A.size(); i++)
        {
            k=0;
            for(j=0; j<s.size(); j++)
            {
                if(A[i]==s[j])
                {
                    k=1;
                    s[j]='#';
                    break;
                }
            }
            if(k==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            ret=-1;
        else
        {
            k=0;
            j=A.size()-1;
            for(i=A.size()-1;i>=0;i--)
                if(A[i]==B[j])
                {
                    k++;
                    j--;
                }
            ret=A.size()-k;
        }

        return ret;
    }

};

// BEGIN CUT HERE
int main()
{
    string s,s1;
    cin>>s;
    cin>>s1;
    int j=LittleElephantAndString().getNumber(s,s1);
    cout<<j;
}
// END CUT HERE
