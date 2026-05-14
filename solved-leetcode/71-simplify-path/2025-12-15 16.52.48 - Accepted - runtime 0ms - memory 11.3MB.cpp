#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        istringstream ss(path);
        string str;

        while (getline(ss, str, '/')) {
            if (str.size() == 0 || str == ".") continue;

            if (str == "..") {
                if (stack.size() != 0) stack.pop_back();
            } else {
                stack.push_back(str);
            }
        }

        string ans = "";
        for (auto s : stack) {
            ans += "/" + s;
        }

        return ans.empty() ? "/" : ans;
    }
};