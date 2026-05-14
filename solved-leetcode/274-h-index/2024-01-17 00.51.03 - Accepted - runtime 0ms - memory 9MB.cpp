class Solution {
public:
    int hIndex(vector<int>& citations) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(citations.begin(), citations.end(), greater<int>());

        for (int i = 0; i < citations.size(); i++) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }
        return citations.size();
    }
};