#include <iostream>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

int main()
{
    String<Dna5> nucleotides = "AGTCGTGNNANCT";
    String<Dna5> lesser;
    String<Dna5> greater;
    // Append all elements of nucleotides, apart of Gs, 
    // to the list `selected` 
    for (unsigned i = 0; i < length(nucleotides); ++i){
        /*
        if (nucleotides[i] < 'G') 
            appendValue(lesser, nucleotides[i]);
        else if (nucleotides[i] > 'G')
            appendValue(greater, nucleotides[i]);
        */
        Lexical<> comp(nucleotides[i], 'G');
        if (isLess(comp)) 
            appendValue(lesser, nucleotides[i]);
        else if (isGreater(comp))
            appendValue(greater, nucleotides[i]);
    }
    std::cout << "Lesser nucleotides: " << lesser << std::endl;
    std::cout << "Greater nucleotides: " << greater << std::endl;
    return 0;
}