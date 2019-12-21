#include "DeoxyribonucleicAcid.h"
#include <iostream>
#include <array>
#include <stdexcept>
#include <algorithm>

Biology::DeoxyribonucleicAcid::DeoxyribonucleicAcid(std::string &dna_strand)
: dna_strand_(verify(dna_strand))
{
    length_ = calculate_length(dna_strand);
}

std::string Biology::DeoxyribonucleicAcid::verify(std::string &dna_strand) {
    if(dna_strand.length() % 2 != 0) {
        throw std::invalid_argument("Invalid DNA stand");
    }
    std::transform(dna_strand.begin(), dna_strand.end(), dna_strand.begin(), &::toupper);
    for(unsigned int i = 0; i < dna_strand.length()-1; i += 2) {
            if(dna_strand.at(i) == 'A') {
                if(dna_strand.at(i+1) != 'T') { throw std::invalid_argument("Invalid DNA strand"); }
            }
            else if(dna_strand.at(i) == 'T') {
                if(dna_strand.at(i+1) != 'A') { throw std::invalid_argument("Invalid DNA strand"); }
            }
            else if(dna_strand.at(i) == 'C') {
                if(dna_strand.at(i+1) != 'G') { throw std::invalid_argument("Invalid DNA strand"); }
            }
            else if(dna_strand.at(i) == 'G') {
                if(dna_strand.at(i+1) != 'C') { throw std::invalid_argument("Invalid DNA strand"); }
            }
            else {
               throw std::invalid_argument("Invalid DNA strand");
            }
    }
    return dna_strand;
}

Biology::DeoxyribonucleicAcid Biology::DeoxyribonucleicAcid::replicate() {
    return DeoxyribonucleicAcid(dna_strand_);
}

float Biology::DeoxyribonucleicAcid::calculate_length(std::string &dna_strand) const {
    return (dna_strand.size()/2)*0.34;
}

float Biology::DeoxyribonucleicAcid::length() const {
    return length_;
}

std::string Biology::DeoxyribonucleicAcid::dna_strand() const {
    return dna_strand_;
}

bool Biology::DeoxyribonucleicAcid::compare_strands(const DeoxyribonucleicAcid &dna1, const DeoxyribonucleicAcid &dna2) {
    return dna1.dna_strand() == dna2.dna_strand();
}

namespace Biology {
    std::ostream &operator<<(std::ostream& os, const DeoxyribonucleicAcid &dna) {
        os << "[DNA Strand: " << dna.dna_strand_ << ", "
           << "Length: " << dna.length_ << "]";
        return os;
    }
}
