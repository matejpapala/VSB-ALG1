#include "graph.h"

Graph::Vertex* Graph::findVertex(int id) {

    for(auto vertex : this->vertices) {
        if(vertex->id == id) {
            return vertex;
        }
    }

    for(int i = 0; i < vertices.size();i++) {
        if(this->vertices[i]->id == id) {
            return this->vertices[i];
        }
    }
    return nullptr;
}

void Graph::insert(int id) {
    Vertex* v = new Vertex(id);
    vertices.push_back(v);
}

void Graph::insert(int id, vector<int> neighborIDs) {
    Vertex* newVertex = new Vertex(id);
    vertices.push_back(newVertex);

    for(auto neighborID : neighborIDs) {
        Vertex* neighbor = findVertex(neighborID);
        if(neighbor) {
            newVertex->neighbors.push_back(neighbor);
            if(newVertex != neighbor)
                neighbor->neighbors.push_back(newVertex);
        }
    }
    

}

