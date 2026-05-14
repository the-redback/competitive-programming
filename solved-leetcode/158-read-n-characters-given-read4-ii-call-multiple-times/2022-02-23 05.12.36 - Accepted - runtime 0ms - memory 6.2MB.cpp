#include <iostream>
#include <string>

using namespace std;

int read4(char *buf);


/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    int length = 0;
    string s = "";

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        while (length < n) {
            char buf4[5];

            int tmp = read4(buf4);
            if (tmp == 0) break;
            length += tmp;

            buf4[tmp] = 0;  // null pointer

            s.append(buf4);
        }
        if (length < n) n = length;
        strcpy(buf, s.substr(0, n).c_str());

        // if(length>n)
        s = s.substr(n);
        // else
        // s="";
        length -= n;
        // cout<<s<<"\n";
        return n;
    }
};