#include "RibonucleicAcid.h"
#include <iostream>
#include <string>

Biology::RibonucleicAcid::RibonucleicAcid(Biology::DeoxyribonucleicAcid &dna)
{
    std::string dna_strand = dna.dna_strand();
    rna_strand_ = transcription(dna_strand);
}

std::string Biology::RibonucleicAcid::transcription(std::string &dna_strand) {
    std::string new_strand;

    for(unsigned int i = 0; i < dna_strand.length(); ++i) {
        if(dna_strand.at(i) == 'A') {
            new_strand += 'U';
        }
        else if(dna_strand.at(i) == 'T') {
            new_strand += 'A';
        }
        else if(dna_strand.at(i) == 'G') {
            new_strand += 'C';
        }
        else if(dna_strand.at(i) == 'C') {
            new_strand += 'G';
        }
        else {
            throw std::invalid_argument("Unknown error");
        }
    }
    return new_strand;
}

float Biology::RibonucleicAcid::length() const {
    return length_;
}

std::string Biology::RibonucleicAcid::rna_strand() const {
    return rna_strand_;
}


