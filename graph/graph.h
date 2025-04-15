#pragma once

#include <vector>
using namespace std;

class Graph {
private:
    class Vertex {
    public:
        int id;
        vector<Vertex*> neighbors;
        int color = 0; // 0 = white, 1 = gray, 2 = black

        Vertex(int id){this->id = id;}
    };
    vector<Vertex*> vertices;
    Vertex* findVertex(int id);

public:
    void insert(int id);
    void insert(int id, vector<int> neighbors);
    void bfs(int id);
};