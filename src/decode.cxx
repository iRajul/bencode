#include "decode.hxx"

using namespace std;


namespace nBencode
{
    decode::decode()
    {

    }

    unique_ptr<item> decode::decodeFile(istream &inStream)
    {
        shared_ptr<item> pItem;
        int i = inStream.peek();
        switch(i)
        {
            case 'd': 
                return decodeDect(inStream);
                break;
            case 'i':
                return decodeInteger(inStream);
                break;
            case 'l':
                return decodeList(inStream);
                break;
            case 1:

            case 2:

            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                case 0;
                return decodeString(inStream);
        }
    }


    unique_ptr<CItem> decodeString(istream &inStream) const
    {
        string::size_type length = GetStringLength(inStream);
        string sRet(length, char());
        inStream.read(&sRet[0], length);
        string::size_type readLength = inStream.gcount();
        if(length != readLength)
        {
            throw std::runtime_error("String length mismatch");
        }
        return unique_ptr<CString>(new CString(sRet));
    }

    string::size_type GetStringLength(istream &inStream) const
    {
        std::string sNum;
        while(inStream.peek() != std::char_traits<char>::eof()  and
                inStream.peek()!= ':')
        {
            sNum+= inStream.get(); 
        }

        string::size_type length = stoi(sNum, NULL);
        if(! inStream.get() != ':')
        {
            throw std::runtime_error("string length is invalid");
        }
        return length;
    }
    unique_ptr<CItem> decodeList(istream &inStream) const
    {
        
    }
}
