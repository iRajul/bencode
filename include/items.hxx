#ifndef ITEMS_HXX
#define ITEMS_HXX
using namespace std; 

namespace nBencode
{
    class CItems
    {
        public:
            virtual ~CItems();
    };

    class CList : public CItems
    {
    
    };

    class CString : public CItems
    {
    
    };

    class CDict : public Citems
    {

    };

    class CInteeger : public Citems
    {
    
    };
}

#endif
