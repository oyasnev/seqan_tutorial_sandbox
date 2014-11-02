#include <iostream>
#include <seqan/align.h>

using namespace seqan;

int main()
{
    /*
    Construct a multiple sequence alignment using the Alignment Graph data structure. 
    Use the three sequences GARFIELDTHECAT, GARFIELDTHEBIGCAT and THEBIGCAT and align them
    such that you obtain the maximal number of matches.
    
    GARFIELDTHE   CAT
    GARFIELDTHEBIGCAT
            THEBIGCAT
    */

    typedef String<char> TSequence;

    TSequence seq1 = "GARFIELDTHECAT";
    TSequence seq2 = "GARFIELDTHEBIGCAT";
    TSequence seq3 = "THEBIGCAT";

    StringSet<TSequence> seqSet;
    appendValue(seqSet, seq1);
    appendValue(seqSet, seq2);
    appendValue(seqSet, seq3);

    typedef StringSet<TSequence, Dependent<> > TDepStringSet;
    Graph<Alignment<TDepStringSet> > alignGraph(seqSet);
    TDepStringSet graphSet = stringSet(alignGraph);
    unsigned id1 = positionToId(graphSet, 0);
    unsigned id2 = positionToId(graphSet, 1);
    unsigned id3 = positionToId(graphSet, 2);

    // GARFIELD 1 - GARFIELD 2
    addEdge(alignGraph, addVertex(alignGraph, id1, 0, 8), addVertex(alignGraph, id2, 0, 8));
    // THE 1 - THE 2
    addEdge(alignGraph, addVertex(alignGraph, id1, 8, 3), addVertex(alignGraph, id2, 8, 3));
    // BIG 2
    addVertex(alignGraph, id2, 11, 3);
    // CAT 1 - CAT 2
    addEdge(alignGraph, addVertex(alignGraph, id1, 11, 3), addVertex(alignGraph, id2, 14, 3));
    // THE 1 - THE 3
    addEdge(alignGraph, findVertex(alignGraph, id1, 8), addVertex(alignGraph, id3, 0, 3));
    // THE 2 - THE 3
    addEdge(alignGraph, findVertex(alignGraph, id2, 8), findVertex(alignGraph, id3, 0));
    // BIG 2 - BIG 3
    addEdge(alignGraph, findVertex(alignGraph, id2, 11), addVertex(alignGraph, id3, 3, 3));
    // CAT 1 - CAT 3
    addEdge(alignGraph, findVertex(alignGraph, id1, 11), addVertex(alignGraph, id3, 6, 3));
    // CAT 2 - CAT 3
    addEdge(alignGraph, findVertex(alignGraph, id2, 14), findVertex(alignGraph, id3, 6));

    std::cout << alignGraph << std::endl;

    return 0;
}