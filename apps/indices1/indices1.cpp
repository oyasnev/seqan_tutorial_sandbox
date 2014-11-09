#include <seqan/sequence.h>
#include <seqan/index.h>

using namespace seqan;

int main()
{
    DnaString dna = "ACGTACGTACGT";
    Index<DnaString, IndexEsa<> > index(dna);
    
    typedef StringSet<DnaString> DnaSet;
    DnaSet dnaSet;
    appendValue(dnaSet, dna);
    appendValue(dnaSet, DnaString("CCCCCC"));
    appendValue(dnaSet, DnaString("GGGGGG"));
    Index<DnaSet, IndexEsa<> > indexSet(dnaSet);

    return 0;
}