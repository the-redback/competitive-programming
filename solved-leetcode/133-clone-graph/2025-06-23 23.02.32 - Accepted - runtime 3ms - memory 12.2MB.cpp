#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        if (visited.find(node) != visited.end()) return visited[node];

        Node* cloneNode = new Node(node->val);

        visited[node] = cloneNode;

        for (auto v : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(v));
        }
        return cloneNode;
    }
};