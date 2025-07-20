#include<iostream>
#include<string>
#include<pybind/pybind11.h>
//Checks if inputted Nucleic Acid is correct
bool verifynucleicAcid(std::string nucleicAcid, bool nucleicAcidType) {
   //true for DNA
   if(nucleicAcidType) {
      for(char i: nucleicAcid) {
         if (!(i == 'A' || i == 'C' || i== 'G' || i == 'T'))
         return 0;
      }
   } else {
      for(char i: nucleicAcid) {
         if (!(i == 'A' || i == 'C' || i== 'G' || i == 'U'))
         return 0;
      }
   }
   return 1;
}
//Transcriibes a DNA Strand into an mRNA Strand
std::string transcribe(std::string DNA) {
   std::string mRNAstrand;
   for(char nucleotide: DNA) {
      switch(nucleotide) {
         case 'T':
            mRNAstrand.push_back('A');
            break;
         case 'C':
            mRNAstrand.push_back('G');
            break;
         case 'G':
            mRNAstrand.push_back('C');
            break;
         case 'A':
            mRNAstrand.push_back('T');
            break;
      }
   }
   return mRNAstrand;
}
PYBIND11_MODULE(genetics, genetics) {
   genetics.def("transcibe", &transcribe, "A function that transcriibes a DNA Strand into an mRNA Strand.");
   genetics.def("verifyNucleicAcid", &verifyNucleicAcid, "A function that verifies if a Nucleic Acid Strand is inputted correctly.")
}