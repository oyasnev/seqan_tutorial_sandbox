#include <iostream>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

int main()
{
    /*
    In this task you will compare whole sequences. Reuse the code from above. 
    Instead of a String<Dna5> we will now deal with a String<Dna5String>. 
    Build a string which contains the Dna5Strings "ATATANGCGT", "AAGCATGANT" and "TGAAANTGAC".
    Now check for all elements of the container, if they are lexicographically smaller or bigger 
    than the given reference sequence "GATGCATGAT" and append them to a appropriate list. 
    Print out the final lists.
    */

    String<Dna5String> dna5List;
    resize(dna5List, 3);
    dna5List[0] = "ATATANGCGT";
    dna5List[1] = "AAGCATGANT";
    dna5List[2] = "TGAAANTGAC";
    String<Dna5String> lesser;
    String<Dna5String> greater;
    for (unsigned i = 0; i < length(dna5List); ++i){
        Lexical<> comp(dna5List[i], "GATGCATGAT");
        if (isLess(comp)) 
            appendValue(lesser, dna5List[i]);
        else if (isGreater(comp))
            appendValue(greater, dna5List[i]);
    }
    std::cout << "Lesser sequences: \n";
    for (unsigned i = 0; i < length(lesser); ++i)
        std::cout << lesser[i] << std::endl;
    std::cout << "Greater sequences: \n";
    for (unsigned i = 0; i < length(greater); ++i)
        std::cout << greater[i] << std::endl;
    return 0;
}