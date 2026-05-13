#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";
    }
    vector<int> product(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int value = (a[i] - '0') * (b[j] - '0') + product[i + j + 1];

            product[i + j + 1] = value % 10;
            product[i + j] += value / 10;
        }
    }

    string result;

    for (int num : product) {
        if (!(result.empty() && num == 0)) {
            result.push_back(num + '0');
        }
    }

    return result;
}

int main() {
    string a = "34";
    string b = "57";

    cout << multiply(a, b) << '\n';

    return 0;
}
