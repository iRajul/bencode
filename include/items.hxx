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
        using ValueType  = std::list;
        public:
        Clist();

        private:
        ValueType value_;

    };

    class CString : public CItems
    {
        using ValueType = std::string;
        public:
        CString();
        private:
        ValueType value_;

    };

    class CDict : public Citems
    {
        using ValueType = std::string;
        public:
        CString();
        private:
        ValueType value_;
    };

    class CInteger : public Citems
    {
        using ValueType = std::int64_t;
        public:
        CInteger();
        private:
        ValueType value_;
    };
}

#endif
