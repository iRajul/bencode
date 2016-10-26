#ifndef ITEMS_HXX
#define ITEMS_HXX
using namespace std; 

namespace nBencode
{
    class Citem
    {
        public:
            virtual ~Citem();
    };

    class CList : public Citem
    {
        using ValueType  = std::list<shared_ptr<CItem> >;
        public:
        Clist();

        private:
        void push_back();

        private:
            ValueType itemList_;

    };

    class CString : public Citem
    {
        using ValueType = std::string;
        public:
        CString();
        
        ValueType GetValue() const;

        private:
        ValueType value_;

    };

    class CDict : public Citem
    {
        struct CompStringItem
        {
            bool operator()(const shared_ptr<CString>& lhs, 
                    const shared_ptr<CString> &rhs) const
            {
                return lhs->GetValue() < rhs->GetValue();
            }
        }
        using ValueType = std::map<shared_ptr<CString> , 
              shread_ptr<CItem>, CompStringItem>;
        public:
        CString();

        auto & operator[](const auto &key);
        
        private:
        ValueType value_;
    };

    class CInteger : public Citem
    {
        using ValueType = std::int64_t;
        public:
        CInteger();
        private:
        ValueType value_;
    };
}

#endif
