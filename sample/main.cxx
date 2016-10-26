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
   nBecode::decode(iFile);
   return 0; 
}
