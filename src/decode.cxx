#include "decode.hxx"

using namespace std;


namespace nBencode
{
    decode::decode()
    {

    }

    unique_ptr<CItem> decode::decodeFile(istream &inStream) const
    {
        int i = inStream.peek();
        switch(i)
        {
            case 'd': 
                return decodeDict(inStream);
                break;
            case 'i':
                return decodeInteger(inStream);
                break;
            case 'l':
                return decodeList(inStream);
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                return decodeString(inStream);
            default:
                cout<<"Item = "<<i<<endl;
                throw runtime_error("Invalid Item!");
        }
    }


    unique_ptr<CString> decode::decodeString(istream &inStream) const
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

    string::size_type decode::GetStringLength(istream &inStream) const
    {
        std::string sNum;
        while(inStream.peek() != std::char_traits<char>::eof()  and
                inStream.peek()!= ':')
        {
            sNum+= inStream.get(); 
        }

        string::size_type length = stoi(sNum, NULL);
        if(inStream.get() != ':')
        {
            throw std::runtime_error("string length is invalid");
        }
        return length;
    }

    unique_ptr<CInteger> decode::decodeInteger(istream& inStream) const
    {
        //! Read 'i'
        inStream.get();
        std::string sValue;
        while(inStream.peek() != 'e')
        {
            sValue+= inStream.get();
        }
        if((inStream.peek() == std::char_traits<char>::eof()))
        {
            cout<<sValue<<endl;
            throw std::runtime_error("invalid integer");
        }
        //! Read 'e'
        inStream.get();
        CInteger::ValueType iVal = std::stoi(sValue, nullptr);
        return unique_ptr<CInteger>(new CInteger(iVal));
    }


    unique_ptr<CList> decode::decodeList(istream& inStream) const
    {
        //! Read 'l'
        inStream.get();
        unique_ptr<CList> uItemList(new CList());
        while(inStream.peek() != 'e')
        {
            auto sItem = decodeFile(inStream);
            uItemList->push_back(move(sItem));
        }
        if((inStream.peek() == std::char_traits<char>::eof()))
        {
            throw std::runtime_error("invalid list");
        }
        //! Read 'e'
        inStream.get();
        return uItemList;
    }

    unique_ptr<CDict> decode::decodeDict(istream& inStream) const
    {
        //! Read 'd'
        inStream.get();
        unique_ptr<CDict> dict(new CDict());
        while(inStream and inStream.peek() != 'e')
        {
               shared_ptr<CItem> key = decodeFile(inStream); 
               shared_ptr<CString> sKey = dynamic_pointer_cast<CString>(key);
               if(!sKey)
               {
                    throw std::runtime_error("Invalid key in map!");
               }
               shared_ptr<CItem> value =  decodeFile(inStream);
               (*dict)[sKey] = value;
        }
        //! Read 'e'
        inStream.get();
        return dict;
    }
}
