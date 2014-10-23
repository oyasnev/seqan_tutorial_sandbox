/*
Write a generic program that swaps the value ranges [i,i+k) and [j,j+k) of a container str.
The container should be specified as a template argument T.
*/

#include <iostream>
#include <seqan/file.h>
#include <seqan/sequence.h>
#include <seqan/basic.h>



template <typename T>
void exchangeFirstValues(T & str) 
{ 
    if (length(str) < 2) return; 
    typename seqan::Value<T>::Type temp = str[0]; 
    str[0] = str[1]; 
    str[1] = temp; 
}

template <typename T> 
void printLenOfFixedSizeString(T const &) 
{ 
    ::std::cout << seqan::LENGTH<T>::VALUE << std::endl; 
}

template <typename T>
void swapRange(T & str, size_t i, size_t j, size_t k)
{
    size_t len = seqan::length(str);
    if (i + k > len || j + k > len)
        return;
    for (size_t m = 0; m < k; ++m) {
        typename seqan::Value<T>::Type temp = str[i + m];
        str[i + m] = str[j + m];
        str[j + m] = temp;
    }
}

int main()
{
    seqan::String<char> str1 = "0123456789";
    std::cout << str1 << std::endl;
    swapRange(str1, 1, 6, 5);
    std::cout << str1 << std::endl;

    seqan::String<seqan::AminoAcid> str2 = "ABCDEFGH";
    std::cout << str2 << std::endl;
    swapRange(str2, 1, 5, 2);
    std::cout << str2 << std::endl;

    return 0;
}