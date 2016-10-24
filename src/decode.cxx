#include "decode.hxx"

using namespace std;


namespace nBencode
{
	decode::decode()
	{
		
	}

	shared_ptr<item> decode::decodeFile(istream &inStream)
	{
		shared_ptr<item> pItem;
		int i = inStream.peek();
		switch(i)
		{
			case 'd': 
				decodeDect(inStream);
			break;
			case 'i':
				decodeInteger(inStream);
			break;
			case 'l':
				decodeList(inStream);
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


	shared
}