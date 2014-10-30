#include <seqan/sequence.h>
#include <seqan/file.h>
#include <iostream>

using namespace seqan;


int main()
{
    StringSet<DnaString> stringSet;
    appendValue(stringSet, "AAA");
    appendValue(stringSet, "CCC");
    appendValue(stringSet, "GGG");
    appendValue(stringSet, "TTT");
    
    std::cout << length(stringSet) << std::endl;

    for (unsigned i = 0; i < length(stringSet); ++i) 
    {
        std::cout << stringSet[i] << std::endl;
    }

    return 0;
}