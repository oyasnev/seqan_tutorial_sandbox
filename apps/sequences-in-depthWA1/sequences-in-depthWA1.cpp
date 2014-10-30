#define SEQAN_PROFILE // enable time measurements
#include <iostream>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

int main()
{
    SEQAN_PROTIMESTART(loadTime);    
    String<Dna> dna;
    for (unsigned i = 0; i < 1000000; ++i)
        appendValue(dna, 'A', Exact());
    std::cout << "Exact strategy takes " << SEQAN_PROTIMEDIFF(loadTime) << " seconds\n";

    SEQAN_PROTIMESTART(loadTime2);
    String<Dna> dna2;
    for (unsigned i = 0; i < 1000000; ++i)
        appendValue(dna2, 'A', Generous());
    std::cout << "Generous strategy takes " << SEQAN_PROTIMEDIFF(loadTime2) << " seconds\n";

    return 0;
}