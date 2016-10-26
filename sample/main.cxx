#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
#include <fstream>
#include "decode.hxx"
using namespace std; 

int main( )
{ 
   ifstream iFile;
   iFile.open("sample1.torrent", std::ifstream::in);
   nBencode::decode decoder;
   decoder.decodeFile(iFile);

   return 0; 
}
