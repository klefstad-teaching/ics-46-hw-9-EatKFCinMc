#include "dijkstras.h"

int main() {
    string file_name = "../src/small.txt";
    Graph G;
    fstream in(file_name);
    in>>G;
    // cout<<"input complete"<<endl;
    vector previous(G.numVertices, -1);
    // cout<<"before function"<<endl;
    vector res = dijkstra_shortest_path(G, 0, previous);
    // cout<<"after function"<<endl;
    for (auto e : res)cout<<e<<" ";
    // cout<<"output?"<<endl;
}