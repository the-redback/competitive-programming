#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
class ListeningIn
{
    public:
    string probableMatch(string s1,string s2)
    {
        string s3;
        int i=0,j=0,k;
        while(i<s1.size() && j<s2.size())
        {
            if(s1[i]!=s2[j])
            {
                s3.push_back(s2[j]);
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        while(j!=s2.size())
        {
            s3.push_back(s2[j]);
            j++;
        }
        if(i!=s1.size())
            return "UNMATCHED";
        return s3;
    }
};
