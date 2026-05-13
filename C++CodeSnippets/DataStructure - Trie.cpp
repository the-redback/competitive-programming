#include <iostream>
#include <string>
using namespace std;

struct node {
    bool endmark;
    node *next[26];

    node() {
        endmark = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

node *root = new node();

void insert(string &s) {
    node *curr = root;

    for (char ch: s) {
        int id = ch - 'a';
        if (curr->next[id] == nullptr) {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(string &s) {
    node *curr = root;
    for (char ch: s) {
        int id = ch - 'a';
        if (curr->next[id] == nullptr) {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}

void removeTrie(node *curr) {
    for (int i = 0; i < 26; i++) {
        if (curr->next[i] != nullptr) {
            removeTrie(curr->next[i]);
        }
    }
    delete curr;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        if (search(s)) {
            cout << "FOUND\n";
        } else {
            cout << "NOT FOUND\n";
        }
    }

    removeTrie(root);

    return 0;
}

/*
Sample Input:
5
apple
app
bat
ball
cat
6
app
apple
bat
bad
ball
dog

Output:
FOUND
FOUND
FOUND
NOT FOUND
FOUND
NOT FOUND

*/
