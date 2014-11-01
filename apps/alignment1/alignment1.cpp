#include <iostream>
#include <seqan/align.h>

using namespace seqan;

typedef Row<Align<DnaString> >::Type TRow;

unsigned countGaps(TRow row)
{
    unsigned cnt = 0;
    Iterator<TRow>::Type it = begin(row);
    for (; it != end(row); ++it)
    {
        if (isGap(it))
            ++cnt;
    }
    return cnt;
}


int main()
{
    /*
    Construct an alignment using the Align data structure for the sequences
    "ACGTCACCTC" and "ACGGGCCTATC". Insert two gaps at the second position and 
    insert one gap at the fifth position of the first sequence. Insert one gap 
    at the ninth position of the second sequence. Iterate over the rows of 
    your Align object and print the total count of gaps that exist within the alignment.
    */

    DnaString str1 = "ACGTCACCTC";
    DnaString str2 = "ACGGGCCTATC";
    Align<DnaString> align;
    resize(rows(align), 2);
    
    TRow & row1 = row(align, 0);
    TRow & row2 = row(align, 1);
    assignSource(row1, str1);
    assignSource(row2, str2);
    insertGap(row1, 5);
    insertGaps(row1, 2, 2);
    insertGaps(row2, 9, 2);
    
    unsigned gaps = 0;
    Iterator<Rows<Align<DnaString> >::Type>::Type it = begin(rows(align));
    for (; it != end(rows(align)); ++it)
    {
        unsigned cnt = countGaps(*it);
        std::cout << *it << "\t\tgaps count: " << cnt << std::endl;
        gaps += cnt;
    }

    std::cout << "Total gaps count: " << gaps << std::endl;

    return 0;
}