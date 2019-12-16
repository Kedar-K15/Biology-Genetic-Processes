#ifndef DEOXYRIBONUCLEICACID_H
#define DEOXYRIBONUCLEICACID_H


#include <string>
namespace Biology {
    class DeoxyribonucleicAcid
    {
        public:
            DeoxyribonucleicAcid(std::string &dna_strand);

            DeoxyribonucleicAcid replicate();

            float length() const;
            std::string dna_strand() const;
            static bool compare_strands(const DeoxyribonucleicAcid &dna1, const DeoxyribonucleicAcid &dna2);
            friend std::ostream &operator<<(std::ostream& os, const DeoxyribonucleicAcid &dna);
        private:
            static std::string verify(std::string &dna_strand);
            std::string dna_strand_;
            float calculate_length(std::string &dna_strand) const;
            float length_;

    };
}

#endif // DEOXYRIBONUCLEICACID_H
