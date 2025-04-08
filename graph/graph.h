#pragma once

#include <vector>
using namespace std;

class Graph {
private:
    class Vertex {
    public:
        int id;
        vector<Vertex*> neighbors;

        Vertex(int id){this->id = id;}
    };
    vector<Vertex*> vertices;
    Vertex* findVertex(int id);

public:
    void insert(int id);
    void insert(int id, vector<int> neighbors);
};