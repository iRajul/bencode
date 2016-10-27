#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
#include <fstream>
#include "decode.hxx"
#include "visitor.hxx"
using namespace std; 

int main( )
{ 
   ifstream iFile;
   iFile.open("sample1.torrent", std::ifstream::in);
   nBencode::decode decoder;
   shared_ptr<nBencode::CItem> pItem = decoder.decodeFile(iFile);

   shared_ptr<nBencode::CPrintPretty> print(new nBencode::CPrintPretty());
   print->Print(pItem);

   return 0; 
}
