#include <iostream>
#include <seqan/graph_algorithms.h>
#include <seqan/basic/basic_math.h>

using namespace seqan;

int main() {
    typedef Graph<Hmm<Dna, LogProb<>, Default> > THmm;
    typedef VertexDescriptor<THmm>::Type TVertexDescriptor;
    
    Dna dnaA = Dna('A');
    Dna dnaC = Dna('C');
    Dna dnaG = Dna('G');
    Dna dnaT = Dna('T');

    THmm hmm;

    TVertexDescriptor beginState = addVertex(hmm);
    assignBeginState(hmm, beginState);

    TVertexDescriptor exonState = addVertex(hmm);
    emissionProbability(hmm, exonState, dnaA) = 0.25;
    emissionProbability(hmm, exonState, dnaC) = 0.25;
    emissionProbability(hmm, exonState, dnaG) = 0.25;
    emissionProbability(hmm, exonState, dnaT) = 0.25;

    TVertexDescriptor spliceState = addVertex(hmm);
    emissionProbability(hmm, spliceState, dnaA) = 0.05;
    emissionProbability(hmm, spliceState, dnaC) = 0.0;
    emissionProbability(hmm, spliceState, dnaG) = 0.95;
    emissionProbability(hmm, spliceState, dnaT) = 0.0;

    TVertexDescriptor intronState = addVertex(hmm);
    emissionProbability(hmm, intronState, dnaA) = 0.4;
    emissionProbability(hmm, intronState, dnaC) = 0.1;
    emissionProbability(hmm, intronState, dnaG) = 0.1;
    emissionProbability(hmm, intronState, dnaT) = 0.4;

    TVertexDescriptor endState = addVertex(hmm);
    assignEndState(hmm, endState);

    addEdge(hmm, beginState, exonState, 1.0);
    addEdge(hmm, exonState, exonState, 0.9);
    addEdge(hmm, exonState, spliceState, 0.1);
    addEdge(hmm, spliceState, intronState, 1.0);
    addEdge(hmm, intronState, intronState, 0.9);
    addEdge(hmm, intronState, endState, 0.1);

    std::cout << hmm << std::endl;

    return 0;
}

