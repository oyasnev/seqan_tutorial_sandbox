#include <iostream>
#include <seqan/align.h>

using namespace seqan;

int main()
{
    Align< String<AminoAcid> > align;
    resize(rows(align), 2);
    assignSource(row(align, 0), "PNCFDAKQRTASRPL");
    assignSource(row(align, 1), "CFDKQKNNRTATRDTA");

    Score<int> scoring(3, -2, -1, -5);
    LocalAlignmentEnumerator<Score<int>, Unbanded> enumerator(scoring);
    unsigned count = 0;
    while (nextLocalAlignment(align, enumerator) && count < 3)
    {
        std::cout << "Score = " << getScore(enumerator) << std::endl;
        std::cout << align;
        std::cout << "Aligns Seq1[" << clippedBeginPosition(row(align, 0)) << ":" << (clippedEndPosition(row(align, 0))-1) << "]";
        std::cout << " and Seq2[" << clippedBeginPosition(row(align, 1)) << ":" <<  (clippedEndPosition(row(align, 1))-1) << "]" << std::endl << std::endl;
        ++count;
    }

    return 0;
}