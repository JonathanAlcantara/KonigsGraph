#include<string>
#ifndef VERTEX_H
#define VERTEX_H

    struct Vertex {
        int vertexID;
        float totalCost;
        bool operator<(const Vertex& anotherVertex) const
        {
            return totalCost < anotherVertex.totalCost;
        }
    };

#endif
