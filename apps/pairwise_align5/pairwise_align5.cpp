#include <iostream>
#include <seqan/align.h>

using namespace seqan;

int main()
{
    typedef String<char> TSequence;                 // sequence type
    typedef Gaps<TSequence, ArrayGaps> TGaps;
    typedef Iterator<TGaps>::Type TGapIterator;

    TSequence text = "MISSISSIPPIANDMISSOURI";
    TSequence pattern = "SISSI";

    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    std::cout << std::endl;

    StringSet<int> positions;
    for (unsigned i = 0; i < length(text) - length(pattern) + 1; ++i)
    {
        TSequence subseq = infixWithLength(text, i, length(pattern));
        if (globalAlignmentScore(subseq, pattern, MyersBitVector()) >= -2)
            appendValue(positions, i);
    }

    TGaps gapsText;
    TGaps gapsPattern(pattern);
    for (Iterator<StringSet<int> >::Type it = begin(positions); it != end(positions); ++it)
    {
        clearGaps(gapsText);
        clearGaps(gapsPattern);

        TSequence subseq = infixWithLength(text, *it, length(pattern));
        assignSource(gapsText, subseq);

        int score = globalAlignment(gapsText, gapsPattern, Score<int,Simple>(0,-1,-1), AlignConfig<true, false, false, true>(), -2, 2);

        // Let's build a cigar string

        // Let's remove leading/trailing gaps
        // trailing
        TGapIterator patternIt = end(gapsPattern);
        while (isGap(patternIt))
            --patternIt;
        unsigned endCnt = end(gapsPattern) - patternIt - 1;
        setClippedEndPosition(gapsPattern, length(gapsPattern) - endCnt);
        setClippedEndPosition(gapsText, length(gapsText) - endCnt);
        // leading
        patternIt = begin(gapsPattern);
        while (isGap(patternIt))
            ++patternIt;
        unsigned beginCnt = patternIt - begin(gapsPattern);
        setClippedBeginPosition(gapsPattern, beginCnt);
        setClippedBeginPosition(gapsText, beginCnt);

        TGapIterator textIt = begin(gapsText);
        patternIt = begin(gapsPattern);
        std::stringstream cigar;
        while (textIt != end(gapsText))
        {
            unsigned cnt = 0;
            
            // insertions
            if (isGap(textIt))
            {
                cnt = countGaps(textIt);
                cigar << cnt << "I";
                textIt += cnt;
                patternIt += cnt;
                continue;
            }

            // deletions
            if (isGap(patternIt))
            {
                cnt = countGaps(patternIt);
                cigar << cnt << "D";
                textIt += cnt;
                patternIt += cnt;
                continue;
            }

            // match
            cnt = 0;
            while (textIt != end(gapsText) && *textIt == *patternIt)
            {
                ++cnt;
                ++textIt;
                ++patternIt;
            }
            if (cnt != 0)
            {
                cigar << cnt << "M";
                continue;
            }

            // mismatch
            cnt = 0;
            while (textIt != end(gapsText) && *textIt != *patternIt)
            {
                ++cnt;
                ++textIt;
                ++patternIt;
            }
            if (cnt != 0)
            {
                cigar << cnt << "S";
            }
        }

        std::cout << "Pos: " << *it << "\t" << "Edits: " << abs(score) << "\t" << "cigar: " << cigar.str() << std::endl;
    }

    return 0;
}