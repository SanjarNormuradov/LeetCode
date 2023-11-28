#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


void dfsMap(const string& node, unordered_map<string, set<string>>& graph, set<string>& connected) {
    stack<string> stck;
    stck.push(node);
    while (!stck.empty()) {
        string current = stck.top();
        stck.pop();
        if (connected.find(current) == connected.end()) {
            connected.insert(current);
            for (const auto& neighbor : graph[current]) {
                stck.push(neighbor);
            }
        }
    }
}

void dfsPlain(int vertex, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfsPlain(neighbor, visited, graph);
        }
    }
}

void bfsPlain(int start, vector<bool>& visited, const vector<vector<int>>& graph) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Neighbors of vertex 0
        {0, 3, 4}, // Neighbors of vertex 1
        {0, 4},    // Neighbors of vertex 2
        {1, 5},    // Neighbors of vertex 3
        {1, 2},    // Neighbors of vertex 4
        {3}        // Neighbors of vertex 5
    };

    vector<bool> visited(graph.size(), false);

    // Perform BFS starting from vertex 0
    bfsPlain(0, visited, graph);

    fill(visited.begin(), visited.end(), false);
    // Perform BFS starting from vertex 0
    dfsPlain(0, visited, graph);

    return 0;
}