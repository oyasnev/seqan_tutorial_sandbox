#include <seqan/sequence.h>
#include <seqan/basic.h>
#include <iostream>
#include <seqan/file.h>
#include <seqan/modifier.h>

using namespace seqan;

Dna getRevCompl(Dna const & nucleotide)
{
    if(nucleotide == (Dna)'A')
        return (Dna)'T';
    if(nucleotide == (Dna)'T')
        return (Dna)'A';
    if(nucleotide == (Dna)'C')
        return (Dna)'G';
    return (Dna)'C';
}

DnaString myReverseComplement(DnaString const & str)
{
    DnaString reverse;
    size_t len = length(str);
    resize(reverse, len);
    for (size_t i = 0; i < len; ++i)
    {
        reverse[i] = getRevCompl(str[len - i - 1]);
    }
    return reverse;
}

int main()
{
    DnaString genome = "TATATACGCGCGAGTCGT";
    DnaString revComplGenome = myReverseComplement(genome);
    
    std::cout << genome << std::endl;
    std::cout << revComplGenome << std::endl;

    reverseComplement(genome);
    std::cout << genome << std::endl;
    return 0;
}