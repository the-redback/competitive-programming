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
        if(node == nullptr)
            return node;
        
        queue<Node*> q;
        unordered_map<Node*, Node*>visited;

        q.push(node);
        Node* clonedGraph = new Node(node->val);
        visited[node] = clonedGraph;

        while(!q.empty()){
            auto u = q.front();
            q.pop();
            auto cloneU = visited[u];
            
            for(auto v: u->neighbors){
                if(visited.find(v) == visited.end()){
                    auto vClone = new Node(v->val);
                    visited[v] = vClone;
                    q.push(v);
                }
                cloneU->neighbors.push_back(visited[v]);
            }
        }

        return clonedGraph;

    }
};