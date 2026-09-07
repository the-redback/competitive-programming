#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ifstream file("application.log");
    string line;
    unordered_map<string, int> mp;

    while (getline(file, line)) {
        istringstream iss(line);
        string tmp;
        string host, level;

        iss >> tmp;
        iss >> tmp;
        iss >> host;
        iss >> level;

        if (level == "ERROR") mp[host]++;
    }

    vector<pair<int, string>> hosts;
    for (auto [s, k] : mp) {
        hosts.push_back({k, s});
    }

    sort(hosts.rbegin(), hosts.rend());

    for (auto [count, host] : hosts) {
        cout << count << " " << host << endl;
    }
}
