#include <iostream>
using namespace std;
#define inf -1
class Graphic {
private:
    int vertices;
    int** edges;
public:
    Graphic(int vertices);
    ~Graphic();
    void addEdge(int u, int v, int w);
    void printGraph();
};
Graphic::Graphic(int vertices) {
    this->vertices = vertices;
    edges = new int* [vertices];
    for (int i = 0; i < vertices; ++i) {
        edges[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j) {
            edges[i][j] = inf;
        }
    }
}
Graphic::~Graphic() {
    for (int i = 0; i < vertices; ++i) {
        delete[]edges[i];
    }
    delete[]edges;
}
void Graphic::addEdge(int u, int v, int w) {
    edges[u][v] = w;
}
void Graphic::printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int vertices=5;
    Graphic graph(vertices);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 5);
    graph.addEdge(4, 0, 2);
    graph.addEdge(4, 2, 5);
    graph.printGraph();
    return 0;
}