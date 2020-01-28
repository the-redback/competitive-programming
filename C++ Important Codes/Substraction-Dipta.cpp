int compare(string a, string b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;
    for (int i = 0; i <= a.size() - 1; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

string remove_leading_zeros(string str) {
    int zero = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') zero++;
        else break;
    }
    if (zero == str.size()) return "0";
    return str.substr(zero);
}

string subtract(string a, string b) {
    int cmp = compare(a, b);
    if (cmp == 0) return "0";
    if (cmp == -1) swap(a, b);

    string ans;
    int tmp, borrow = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
        if (j < 0) tmp = a[i] - '0';
        else tmp = a[i] - b[j];
        if (borrow) {
            tmp--;
            borrow = 0;
        }
        if (tmp < 0) {
            tmp += 10;
            borrow = 1;
        }
        ans += tmp + '0';
    }
    reverse(ans.begin(), ans.end());
    ans = remove_leading_zeros(ans);
    if (cmp == -1) ans = "-" + ans;
    return ans;
}

