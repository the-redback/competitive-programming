#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            };
            i++;
            j--;
        }
        return true;
    }

    //     bool isAlphabetNum(char ch){
    //         if(ch>='a' && ch<='z') return true;
    //         if(ch>='A' && ch<='Z') return true;
    //         if(ch>='0' && ch<='9') return true;
    //         return false;
    //     }

    //     char toLower(char ch){
    //         if(ch>='A' && ch<='Z')
    //             ch=ch-'A'+'a';
    //         return ch;
    //     }
};