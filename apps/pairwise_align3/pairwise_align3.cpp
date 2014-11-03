#include <iostream>
#include <seqan/align.h>

using namespace seqan;

int main()
{
    typedef String<Rna> TSequence;                 // sequence type
    typedef Align<TSequence, ArrayGaps> TAlign;     // align type
    typedef Row<TAlign>::Type TRow;
    typedef Iterator<TRow>::Type TRowIterator;

    TSequence seq1 = "AAGUGACUUAUUG";
    TSequence seq2 = "AGUCGGAUCUACUG";

    TAlign align;
    resize(rows(align),2);
    assignSource(row(align,0),seq1);
    assignSource(row(align,1),seq2);

    int score = globalAlignment(align, MyersHirschberg());
    std::cout << "Score: " << score << std::endl;
    std::cout << align << std::endl;

    for (unsigned i = 0; i < length(rows(align)); ++i)
    {
        std::cout << "Row " << i << ": ";
        TRow row1 = row(align, i);
        unsigned pos = 0;
        for (TRowIterator it = begin(row1); it != end(row1); ++it, ++pos)
        {
            if (isGap(it))
                std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
