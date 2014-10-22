#include <iostream>
#include <seqan/file.h>
#include <seqan/sequence.h>
#include <seqan/score.h>

template <typename TText, typename TPattern>
int computeLocalScore(TText const & subText, TPattern const & pattern)
{
    int localScore = 0;
    for (unsigned i = 0; i < seqan::length(pattern); ++i)
        if (subText[i] == pattern[i])
            ++localScore;
    
    return localScore;
}

template <typename TText>
int computeLocalScore(TText const & subText, seqan::String<seqan::AminoAcid> const & pattern)
{
    int localScore = 0;
    for (unsigned i = 0; i < seqan::length(pattern); ++i)
        localScore += seqan::score(seqan::Blosum62(), subText[i], pattern[i]);
    
    return localScore;
}

template <typename TText, typename TPattern>
seqan::String<int> computeScore(TText const & text, TPattern const & pattern)
{
    seqan::String<int> score;
    seqan::resize(score, seqan::length(text) - seqan::length(pattern) + 1, 0);

    for (unsigned i = 0; i < seqan::length(text) - seqan::length(pattern) + 1; ++i)
        score[i] = computeLocalScore(infix(text, i, i + seqan::length(pattern)), pattern);
    
    return score;
}

template <typename TText, typename TSpec>
void print(TText const & text, TSpec const & /*tag*/)
{
    for (unsigned i = 0; i < seqan::length(text); ++i)
        std::cout << text[i] << " ";
    std::cout << std::endl;
}

struct MaxOnly {};

template <typename TText>
void print(TText const & score, MaxOnly const & /*tag*/)
{
    int maxScore = score[0];
    seqan::String<int> output;
    appendValue(output, 0);
    for (unsigned i = 1; i < seqan::length(score); ++i)
    {
        if (score[i] > maxScore)
        {
            maxScore = score[i];
            clear(output);
            resize(output, 1, i);
        }
        else if (score[i] == maxScore)
            appendValue(output, i);
    }
    for (unsigned i = 0; i < seqan::length(output); ++i)
        std::cout << output[i] << " ";
    std::cout << std::endl;
}

struct PairScore {};

template <typename TText>
void print(TText const & score, PairScore const & /*tag*/)
{
    seqan::String<seqan::Pair<int, int> > output;
    for (unsigned i = 0; i < seqan::length(score); ++i)
    {
        if (score[i] > 0)
        {
            appendValue(output, seqan::Pair<int, int>(i, score[i]));
        }
    }
    print(output, 0);
}

int main()
{
    seqan::String<char> text = "This is an awesome tutorial to get to know SeqAn!";
    seqan::String<char> pattern = "tutorial";
    seqan::String<int> score = computeScore(text, pattern);

    print(text, 0);
    print(pattern, 0);
    print(score, MaxOnly());    
    print(score, 0);    
    print(score, PairScore());

    // And now for a protein pattern
    seqan::String<seqan::AminoAcid> protein = "tutorial";
    seqan::String<int> proteinScore = computeScore(text, protein);
    print(text, 0);
    // > This is an awesome tutorial to get to now SeqAn!
    print(protein, 0);
    // > TXTXRIAL
    print(proteinScore, 0);
    // > 6 -9 -3 -6 -6 0 -9 -8 -7 -3 -9 -5 -8 -4 -5 -6 -6 1 -6 25 -7 2 -6 -6 -9 -6 -5 -7 1 -7 -5 -4 -6 2 -6 -3 -8 -9 -10 -4 -6 0 0 0 0 0 0 0
    print(proteinScore, MaxOnly());
    // > 19
    print(proteinScore, PairScore());
    // > (17; 1) (19; 25) (21; 2) (28; 1) (33; 2)

    return 0;
}