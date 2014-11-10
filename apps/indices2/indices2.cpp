#include <seqan/sequence.h>
#include <seqan/index.h>

using namespace seqan;

int main()
{
    DnaString genome = "TTATTAAGCGTATAGCCCTATAAATATAA";
    typedef Index<DnaString, IndexEsa<> > TIndex;
    TIndex esaIndex(genome); 
    Finder<TIndex> esaFinder(esaIndex);

    while (find(esaFinder, "TATAA")) {
        std::cout << position(esaFinder) << std::endl;
    }

    return 0;
}