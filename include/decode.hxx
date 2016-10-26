#ifndef DECODE_HXX
#define DECODE_HXX

#include<iostream>
#include <memory>

#include "items.hxx"
using namespace std;

namespace nBencode
{
class decode
{
    public:
        decode();
        //std::unique_ptr<CItem> decodeFile(string);
        unique_ptr<CItem> decodeFile(istream &);

    private:
        unique_ptr<CString> decodeString(istream&) const;
        unique_ptr<CDict> decodeDict(istream&);
        unique_ptr<CList> decodeList(istream&);
        unique_ptr<CInteger> decodeInteger(istream& inStream);
        string::size_type GetStringLength(istream &inStream) const;

};
}
#endif /* DECODE_HXX */
