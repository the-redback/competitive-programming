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
        int cnt[6][26];

        for (int i = 0, x = 0; i < 10 & x != 6; i++) {
            memset(cnt, 0, sizeof(cnt));

            for (auto w : wordlist) {
                for (int i = 0; i < w.size(); i++) {
                    cnt[i][w[i] - 'a']++;
                }
            }
            int best = 0;
            string guess;
            for (auto w : wordlist) {
                int score = 0;
                for (int i = 0; i < 6; i++) {
                    score += cnt[i][w[i] - 'a'];
                }
                if (score > best) {
                    guess = w;
                    best = score;
                }
            }

            x = master.guess(guess);

            vector<string> candidates;
            for (auto w : wordlist) {
                if (match(w, guess) == x) candidates.push_back(w);
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