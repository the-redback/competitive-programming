#include <sstream>
#include <iomanip>

using namespace std;

class Codec {
public:
    string int2str(int n) {
        stringstream ss;
        ss << setw(4) << setfill('0') << n;
        return ss.str();
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = "";

        for (auto str : strs) {
            ans += int2str(str.size());
            ans += str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s == "") return {""};
        vector<string> ans;
        for (int i = 0; i < s.size() - 3;) {
            int in = stoi(s.substr(i, 4));
            i += 4;
            string str = s.substr(i, in);
            i += in;
            ans.push_back(str);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));