class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        return LCP(strs, 0, strs.size() - 1);
    }

    string LCP(vector<string>& strs, int l, int r) {
        if (l == r) return strs[l];
        int mid = (l + r) / 2;
        string left = LCP(strs, l, mid);
        string right = LCP(strs, mid + 1, r);
        return commonPrefix(left, right);
    }

    string commonPrefix(string left, string right) {
        int n = min(left.size(), right.size());
        string prefix = "";
        for (int i = 0; i < n; i++) {
            if (left[i] != right[i]) return prefix;
            prefix += left[i];
        }
        return prefix;
    }
};