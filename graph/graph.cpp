#include "graph.h"
#include <queue>
#include <iostream>

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

void Graph::bfs(int id) {
    Vertex* startVertex = findVertex(id);
    queue<Vertex*> que;

    que.push(startVertex);
    startVertex->color = 1;

    while(!que.empty()) {
        Vertex* currentVertex = que.front();
        que.pop();


        cout << currentVertex->id << endl;
        currentVertex->color = 2;

        for(auto neighbor : currentVertex->neighbors) {
            if(neighbor->color == 0) {
                que.push(neighbor);
                neighbor->color = 1;  
            }
        }    
    }

    
}