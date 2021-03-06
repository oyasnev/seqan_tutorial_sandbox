#include <iostream>
#include <seqan/align.h>
#include <seqan/graph_msa.h>

using namespace seqan;

int main()
{
    typedef String<AminoAcid> TSequence;
    StringSet<TSequence> seq;
    appendValue(seq,"DPKKPRGKMSSYAFFVQTSREEHKKKHPDASVNFSEFSKKCSERWKTMSAKEKGKFEDMAKADKARYEREMKTYIPPKGE");
    appendValue(seq,"RVKRPMNAFIVWSRDQRRKMALENPRMRNSEISKQLGYQWKMLTEAEKWPFFQEAQKLQAMHREKYPNYKYRPRRKAKMLPK");
    appendValue(seq,"FPKKPLTPYFRFFMEKRAKYAKLHPEMSNLDLTKILSKKYKELPEKKKMKYIQDFQREKQEFERNLARFREDHPDLIQNAKK");
    appendValue(seq,"HIKKPLNAFMLYMKEMRANVVAESTLKESAAINQILGRRWHALSREEQAKYYELARKERQLHMQLYPGWSARDNYGKKKKRKREK");

    Align<TSequence> align(seq);
    globalMsaAlignment(align, Blosum80(-1, -11));
    std::cout << align << std::endl;

    return 0;
}