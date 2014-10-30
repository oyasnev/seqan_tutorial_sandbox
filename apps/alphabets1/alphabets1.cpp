#include <seqan/sequence.h>
#include <seqan/basic.h>
#include <iostream>

using namespace seqan;

// We want to define a function, which takes 
// the alphabet type as an argument
template <typename TAlphabet>
void showAllLettersOfMyAlphabet(TAlphabet const &)
{
    typedef typename ValueSize<TAlphabet>::Type Type;
    Type size = ValueSize<TAlphabet>::VALUE;
    for (Type i = 0; i < size; ++i)
        std::cout << TAlphabet(i) << " ";
    std::cout << std::endl;
}

int main()
{
    showAllLettersOfMyAlphabet(AminoAcid());
    showAllLettersOfMyAlphabet(Dna());
    showAllLettersOfMyAlphabet(Dna5());
    return 0;
}