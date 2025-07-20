#include<iostream>
#include<string>
#include<map>
#include<pybind/pybind11.h>

//Checks if inputted Nucleic Acid is correct
bool verifyNucleicAcid(std::string nucleicAcid, bool nucleicAcidType) {
   //true for DNA
   if(nucleicAcidType) {
      for(char nucleotide: nucleicAcid) {
         if (!(nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T'))
         return 0;
      }
   } else {
      for(char i: nucleicAcid) {
         if (!(nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'U'))
         return 0;
      }
   }
   return 1;
}
unordered_map<char, char> complementsChartDNA = {
   {'A','T'},
   {'T','A'},
   {'C','G'},
   {'G','C'}
}
unordered_map<char, char> complementsChartRNA = {
   {'A','U'},
   {'U','A'},
   {'C','G'},
   {'G','C'}
}
//Finds the complement of a given Nucleic Acid Strand
std::string findComplement(std::string nucleicAcid, bool nucleicAcidType) {
   if(verifyNucleicAcid(nucleicAcid, nucleicAcidType)){
      std::string complement;
      if(nucleicAcidType) {
         for(char nucleotide: nucleicAcid) {
            complement.push_back(complementDNA[nucleotide]);
         }
      } else {
         for(char nucleotide: nucleicAcid) {
            complement.push_back(complementRNA[nucleotide]);
         }
      }
      return complement;
   } else {
      return "\0";
   }
};
//Transcriibes a DNA Strand into an mRNA Strand
std::string transcribe(std::string DNA) {
   if(verifynNcleicAcid(DNA, 1)){
      DNA = findComplement(DNA);
      std::string mRNAstrand;
      for(char nucleotide: DNA) {
        if(nucleotide == 'T') {
            mRNAstrand.push_back('U');
        } else {
            mRNAstrand.push_back(nucleotide);
        }
      }
      return mRNAstrand;
   } else {
      return "\0";
   }
}

PYBIND11_MODULE(genetics, genetics) {
   genetics.def("transcibe", &transcribe, "A function that transcriibes a DNA Strand into an mRNA Strand.");
   genetics.def("verifyNucleicAcid", &verifyNucleicAcid, "A function that verifies if a Nucleic Acid Strand is inputted correctly.");
   genetics.def("findComplement", &findComplement, "A function that finds the complement of a given Nucleic Acid Strand")
}