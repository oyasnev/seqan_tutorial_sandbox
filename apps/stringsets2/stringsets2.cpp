#include <iostream>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

bool isElement(StringSet<DnaString, Dependent<> > depSet, unsigned id) 
{
    for (unsigned i = 0; i < length(depSet); ++i)
    {
        if (positionToId(depSet, i) == id)
            return true;
    }
    return false;
}

int main()
{
    // Build strings
    DnaString str0 = "TATA";
    DnaString str1 = "CGCG"; 
    DnaString str2 = "TTAAGGCC"; 
    DnaString str3 = "ATGC"; 
    DnaString str4 = "AGTGTCA"; 

    // Your code
    StringSet<DnaString> stringSet;
    appendValue(stringSet, str0);
    appendValue(stringSet, str1);
    appendValue(stringSet, str2);
    appendValue(stringSet, str3);
    appendValue(stringSet, str4);

    unsigned id0 = positionToId(stringSet, 0);
    unsigned id1 = positionToId(stringSet, 1);
    unsigned id2 = positionToId(stringSet, 2);
    unsigned id3 = positionToId(stringSet, 3);
    unsigned id4 = positionToId(stringSet, 4);

    StringSet<DnaString, Dependent<> > depSet;
    assignValueById(depSet, str0, 0);
    assignValueById(depSet, str1, 1);
    assignValueById(depSet, str3, 3);

    std::cout << "Is id 3 in set: " << isElement(depSet, 3) << std::endl;
    std::cout << "Is id 2 in set: " << isElement(depSet, 2) << std::endl;

    return 0;
}