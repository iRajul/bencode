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
        unique_ptr<Citem> decodeFile(string);
        unique_ptr<Citem> decodeFile(istream &);

    private:
        bool decodeString(istream&);
        bool decodeInterger(istream&);
        bool decodeDict(istream&);
        bool decodeList(istream&);

        unique_ptr<CItem> decodeString(istream &inStream) const;
        string::size_type GetStringLength(istream &inStream) const;

};
}
#endif /* DECODE_HXX */
