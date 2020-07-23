/* -------------------------------------------------------------------------- */
/*                                  Max Heap                                  */
/* -------------------------------------------------------------------------- */
// Note that by default C++ creates a max-heap 
// for priority queue 
#include <iostream> 
#include <queue> 

using namespace std; 

void showpq(priority_queue <int> gq) 
{ 
	priority_queue <int> g = gq; 
	while (!g.empty()) 
	{ 
		cout << '\t' << g.top(); 
		g.pop(); 
	} 
	cout << '\n'; 
} 

int main () 
{ 
	priority_queue <int> gquiz; 
	gquiz.push(10); 
	gquiz.push(30); 
	gquiz.push(20); 
	gquiz.push(5); 
	gquiz.push(1); 

	cout << "The priority queue gquiz is : "; 
	showpq(gquiz); 

	cout << "\ngquiz.size() : " << gquiz.size(); 
	cout << "\ngquiz.top() : " << gquiz.top(); 


	cout << "\ngquiz.pop() : "; 
	gquiz.pop(); 
	showpq(gquiz); 

	return 0; 
} 

// The priority queue gquiz is :     30    20    10    5    1

// gquiz.size() : 5
// gquiz.top() : 30
// gquiz.pop() :     20    10    5    1

/* -------------------------------------------------------------------------- */
/*                                  Min Heap                                  */
/* -------------------------------------------------------------------------- */
// C++ program to demonstrate min heap 
#include <iostream> 
#include <queue> 

using namespace std; 

void showpq(priority_queue <int, vector<int>, greater<int>> gq) 
{ 
	priority_queue <int, vector<int>, greater<int>> g = gq; 
	while (!g.empty()) 
	{ 
		cout << '\t' << g.top(); 
		g.pop(); 
	} 
	cout << '\n'; 
} 

int main () 
{ 
	priority_queue <int, vector<int>, greater<int>> gquiz; 
	gquiz.push(10); 
	gquiz.push(30); 
	gquiz.push(20); 
	gquiz.push(5); 
	gquiz.push(1); 

	cout << "The priority queue gquiz is : "; 
	showpq(gquiz); 

	cout << "\ngquiz.size() : " << gquiz.size(); 
	cout << "\ngquiz.top() : " << gquiz.top(); 


	cout << "\ngquiz.pop() : "; 
	gquiz.pop(); 
	showpq(gquiz); 

	return 0; 
}
// The priority queue gquiz is :     1    5    10    20    30

// gquiz.size() : 5
// gquiz.top() : 1
// gquiz.pop() :     5    10    20    30

/* -------------------------------------------------------------------------- */
/*                              Max heap of Pair                              */
/* -------------------------------------------------------------------------- */
// C++ program to create a priority queue of pairs. 
// By default a max heap is created ordered 
// by first element of pair. 
#include <bits/stdc++.h> 

using namespace std; 

// Driver program to test methods of graph class 
int main() 
{ 
	// By default a max heap is created ordered 
	// by first element of pair. 
	priority_queue<pair<int, int> > pq; 

	pq.push(make_pair(10, 200)); 
	pq.push(make_pair(20, 100)); 
	pq.push(make_pair(15, 400)); 

	pair<int, int> top = pq.top(); 
	cout << top.first << " " << top.second; 
	return 0; 
} 

// 20 100

/* -------------------------------------------------------------------------- */
/*                              Min Heap of Pairs                             */
/* -------------------------------------------------------------------------- */

// C++ program to create a priority queue of pairs. 
// We can create a min heap by passing adding two 
// parameters, vector and greater(). 
#include <bits/stdc++.h> 

using namespace std; 

typedef pair<int, int> pi; 

// Driver program to test methods of graph class 
int main() 
{ 
	// By default a min heap is created ordered 
	// by first element of pair. 
	priority_queue<pi, vector<pi>, greater<pi> > pq; 

	pq.push(make_pair(10, 200)); 
	pq.push(make_pair(20, 100)); 
	pq.push(make_pair(15, 400)); 

	pair<int, int> top = pq.top(); 
	cout << top.first << " " << top.second; 
	return 0; 
} 
// 10 200
