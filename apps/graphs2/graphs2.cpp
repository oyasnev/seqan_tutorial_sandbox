#include <iostream>
#include <seqan/graph_types.h>
#include <seqan/graph_algorithms.h>
using namespace seqan;

int main ()
{
    typedef Graph<Directed<> > TGraph;
    typedef VertexDescriptor<TGraph>::Type TVertexDescriptor;
    
    TGraph g;
    TVertexDescriptor edges[] = {
        1,0, 0,4, 2,1, 4,1, 5,1, 6,2, 3,2, 2,3, 7,3, 
        5,4, 6,5, 5,6, 7,6, 7,7
    };
    unsigned int vertexCnt = sizeof(edges) / sizeof(*edges) / 2;

    addEdges(g, edges, vertexCnt);

    FILE* strmWrite = fopen("graph.dot", "w");
    write(strmWrite, g, DotDrawing());
    fclose(strmWrite);

    std::cout << g << std::endl;

    return 0;
}