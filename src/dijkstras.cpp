#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int num = G.numVertices;
    vector res(num, INF);
    vector visited(num, false);
    res[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sg;
    sg.push({source, 0});

    while (!sg.empty()) {
        int u = sg.top().first;
        sg.pop();
        if (visited[u])continue;
        visited[u] = true;
        for (auto e : G[u]) {
            int v = e.dst;
            int weight = e.weight;
            if (!visited[v] && res[u] + weight < res[v]) {
                res[v] = res[u] + weight;
                previous[v] = u;
                sg.push({v, weight});
            }
        }
    }
    return res;

}

void reverse_vector(vector<int>& vec) {
    int i = 0, j = vec.size() - 1;
    while(i < j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
        i++;
        j--;
    }
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at])
        path.push_back(at);
    reverse_vector(path);
    return path;

}

void print_path(const vector<int>& v, int total) {
    cout << "Path: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\nTotal cost: " << total << endl;
}