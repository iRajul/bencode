#ifndef DECODE_HXX
#define DECODE_HXX

#include<iostream>
using namespace std;

namespace nBencode
{
class decode
{
    public:
        decode();
        decodeFile(string);
        decodeFile(istream &);

        
    private:
    	bool decodeString(istream&);
    	bool decodeInterger(istream&);
    	bool decodeDict(istream&);
    	bool decodeList(istream&);

};
}
#endif /* DECODE_HXX */
