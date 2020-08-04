#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
	vector<vector<int>> adjMatrix;

	Graph(int nodeCount = 0) {
		adjMatrix.resize(nodeCount);
		for (int row = 0;row < adjMatrix.size();row++) {
			adjMatrix[row].resize(nodeCount);
			for (int col = 0;col < adjMatrix.size();col++) {
				adjMatrix[row][col] = 0;
			}
		}

	}

	void print() const {
		for (auto neighbours : adjMatrix) {
			for (auto neighbour : neighbours) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}

	void connect(int from, int to, int weight = 1) {
		adjMatrix[from][to] = weight;
	}
};

