#include<iostream>
#include<string>
#include<pybind/pybind11.h>

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
   genetics.def("transcibe", &transcribe, "A function that transcriibes a DNA Strand into an mRNA Strand");
}