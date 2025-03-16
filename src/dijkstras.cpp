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


vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {

}

void print_path(const vector<int>& v, int total) {

}