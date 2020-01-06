#ifndef RIBONUCLEICACID_H
#define RIBONUCLEICACID_H

#include "DeoxyribonucleicAcid.h"

namespace Biology {
    class RibonucleicAcid
    {
        public:
            RibonucleicAcid(Biology::DeoxyribonucleicAcid &dna);

            float length() const;
            std::string rna_strand() const;
        private:
            std::string transcription(std::string &dna_strand);

            std::string rna_strand_;
            float length_;

    };
}

#endif // RIBONUCLEICACID_H
