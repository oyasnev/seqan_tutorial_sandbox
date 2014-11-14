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

    typedef String<char> TProperties;
    TProperties labelMap;
    char labels[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    assignVertexMap(g, labelMap, labels);

    typedef Iterator<TGraph, DfsPreorder>::Type TDfsIterator;
    for(TDfsIterator itV(g, TVertexDescriptor(0)); !atEnd(itV); ++itV) {
        std::cout << *itV << ':' << getProperty(labels, *itV) << std::endl;
    }
    
    return 0;
}