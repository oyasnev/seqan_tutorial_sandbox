#include <iostream>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

int main()
{
    Dna5String genome = "ANTGGTTNCAACNGTAANTGCTGANNNACATGTNCGCGTGTA";
    for (Iterator<Dna5String>::Type it = begin(genome); it != end(genome); ++it)
    {
        if (*it == 'N')
            *it = 'A';
    }
    std::cout << "Modified genome: " << genome << std::endl;
    return 0;
}