#include <iostream>
#include <list>
#include <vector>
#include<queue>
using namespace std;

struct Pair {
	int index;
	int weight;
};

struct Node {
	list<Pair> neighbours;

	bool hasNeighbour(int index) {
		for (auto neighbour : neighbours) {
			if (neighbour.index == index) {
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int index, int weight) {
		neighbours.push_back(Pair{ index,weight });
	}
};

class Graph {
	vector<Node> nodes;

	Graph(int nodeCount = 0) {
		nodes.resize(nodeCount);
	}

	void connect(int from, int to, int weight) {
		if (!nodes[from].hasNeighbour(to)) {
			nodes[from].addNeighbour(to, weight);
		}
	}

	void print() const {
		for (int node = 0;node < nodes.size();node++) {
			cout << node << ": ";
			for (auto neighbour : nodes[node].neighbours) {
				cout << neighbour.index << " ";
			}
			cout << endl;
		}
	}

	void BFS(int start, vector<bool>& visited) {
		queue<int> nextToProcess;
		nextToProcess.push(start);
		visited[start] = true;

		while (!nextToProcess.empty()) {
			int current = nextToProcess.front();
			nextToProcess.pop();

			cout << current << " ";

			for (auto neighbour : nodes[current].neighbours) {
				if (!visited[neighbour.index]) {
					nextToProcess.push(neighbour.index);
					visited[neighbour.index] = true;
				}
			}
		}
	}

	void DFS(int current, vector<int>& visited) {
		cout << current << " ";
		visited[current] = true;

		for (auto neighbour : nodes[current].neighbours) {
			if (!visited[neighbour.index]) {
				DFS(neighbour.index, visited);
			}
		}
	}
};