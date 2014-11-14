#include <iostream>
#include <seqan/graph_types.h>
#include <seqan/graph_algorithms.h>
using namespace seqan;

int main ()
{
    typedef unsigned int TCargo;
    typedef Graph<Directed<TCargo> > TGraph;
    typedef VertexDescriptor<TGraph>::Type TVertexDescriptor;

    TGraph g;

    TVertexDescriptor vertBerlin = addVertex(g);
    TVertexDescriptor vertHamburg = addVertex(g);
    TVertexDescriptor vertHannover = addVertex(g);
    TVertexDescriptor vertMuenchen = addVertex(g);

    addEdge(g, vertBerlin, vertHamburg, 289u);
    addEdge(g, vertHamburg, vertHannover, 286u);
    addEdge(g, vertHannover, vertMuenchen, 572u);
    addEdge(g, vertMuenchen, vertHannover, 572u);

    String<unsigned int> scc;
    stronglyConnectedComponents(g, scc);

    typedef Iterator<TGraph, VertexIterator>::Type TVertexIterator;
    for (TVertexIterator it(g); !atEnd(it); ++it)
        std::cout << "vertex " << *it << ", scc " << getProperty(scc, *it) << std::endl;

    return 0;
}