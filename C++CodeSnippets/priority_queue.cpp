#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                                  Max Heap                                  */
/* -------------------------------------------------------------------------- */

void printMaxHeap(priority_queue<int> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
}

/* -------------------------------------------------------------------------- */
/*                                  Min Heap                                  */
/* -------------------------------------------------------------------------- */

void printMinHeap(
    priority_queue<int,
        vector<int>,
        greater<int> > pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
}

/* -------------------------------------------------------------------------- */
/*                              Max Heap of Pair                              */
/* -------------------------------------------------------------------------- */

void printMaxPairHeap(
    priority_queue<pair<int, int> > pq) {
    while (!pq.empty()) {
        pair<int, int> top = pq.top();

        cout << "(" << top.first << ", "
                << top.second << ") ";
        pq.pop();
    }
    cout << '\n';
}

/* -------------------------------------------------------------------------- */
/*                              Min Heap of Pair                              */
/* -------------------------------------------------------------------------- */

void printMinPairHeap(
    priority_queue<pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> > > pq) {
    while (!pq.empty()) {
        pair<int, int> top = pq.top();

        cout << "(" << top.first << ", "
                << top.second << ") ";
        pq.pop();
    }
    cout << '\n';
}

int main() {
    // Max Heap

    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    printMaxHeap(maxHeap);

    // Min Heap

    priority_queue<int,
        vector<int>,
        greater<int> > minHeap;

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    printMinHeap(minHeap);

    // Max Heap of Pair

    priority_queue<pair<int, int> > maxPairHeap;

    maxPairHeap.push({10, 200});
    maxPairHeap.push({20, 100});
    maxPairHeap.push({15, 400});

    printMaxPairHeap(maxPairHeap);

    // Min Heap of Pair

    priority_queue<pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> > > minPairHeap;

    minPairHeap.push({10, 200});
    minPairHeap.push({20, 100});
    minPairHeap.push({15, 400});

    printMinPairHeap(minPairHeap);

    return 0;
}
