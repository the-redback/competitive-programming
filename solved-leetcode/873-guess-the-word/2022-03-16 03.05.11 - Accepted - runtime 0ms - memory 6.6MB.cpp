#include <vector>
using namespace std;

class Master {
public:
    int guess(string word);
};


/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(NULL));
        for (int i = 0, x = 0; i < 10 & x != 6; i++) {
            string guess = wordlist[rand() % wordlist.size()];
            x = master.guess(guess);

            vector<string> candidates;
            for (auto word : wordlist) {
                if (match(guess, word) == x) candidates.push_back(word);
            }
            wordlist = candidates;
        }
        return;
    }

    int match(string& a, string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) count++;
        }
        return count;
    }
};