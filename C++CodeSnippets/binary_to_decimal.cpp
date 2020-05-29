ll binaryToDecimal(string bi) {
    ll ans = 0;
    ll carry = 1;

    for (int i = bi.size() - 1; i >= 0; i--) {
        if (bi[i] == '1') {
            ans += carry;
        }
        carry = carry << 1;
    }
    return ans;
}
