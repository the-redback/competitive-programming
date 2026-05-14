class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > pq;

        char last1 = '#';
        char last2 = '#';

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string res = "";

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            if (ch1 == last1 && ch1 == last2) {
                if (pq.empty()) return res;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                res += ch2;

                last2 = last1;
                last1 = ch2;

                pq.push({cnt1, ch1});

                if (--cnt2 > 0) pq.push({cnt2, ch2});
            } else {
                res += ch1;

                last2 = last1;
                last1 = ch1;

                if (--cnt1 > 0) pq.push({cnt1, ch1});
            }
        }

        return res;
    }
};