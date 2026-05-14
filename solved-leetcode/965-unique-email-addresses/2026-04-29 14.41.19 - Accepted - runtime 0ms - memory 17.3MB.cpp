#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        int result = 0;

        for (auto& email : emails) {
            string str = "";
            for (auto& ch : email) {
                if (ch == '+' || ch == '@') break;

                if (ch == '.') continue;
                str += ch;
            }

            string domain = "";
            for (int i = email.size() - 1; i >= 0; i--) {
                domain += email[i];
                if (email[i] == '@') break;
            }

            reverse(domain.begin(), domain.end());
            str += domain;

            unique_emails.insert(str);
        }

        return unique_emails.size();
    }
};