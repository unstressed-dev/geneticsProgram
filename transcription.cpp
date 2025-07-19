#include<iostream>
#include<string>

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