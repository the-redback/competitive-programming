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
    string str = "";

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        char buf4[5];
        while (length < n) {
            int len = read4(buf4);
            if (len == 0) break;
            buf4[len] = 0;

            str += buf4;
            length += len;
        }

        if (length < n) n = length;

        strcpy(buf, str.substr(0, n).c_str());
        str = str.substr(n);
        length -= n;
        return n;
    }
};