#ifndef ITEMS_HXX
#define ITEMS_HXX
#include <memory>
#include <list>
#include <map>
#include<string>
using namespace std; 


namespace nBencode
{
    class CItem
    {
        public:
            virtual ~CItem();
    };

    class CList : public CItem
    {
        using ValueType  = std::list<shared_ptr<CItem> >;
        public:
        CList();
        void push_back(const auto &item);

        private:

        private:
            ValueType itemList_;

    };

    class CString : public CItem
    {
        using ValueType = std::string;
        public:
        CString();
        CString(ValueType&);
        
        ValueType GetValue() const;

        private:
        ValueType value_;

    };

    class CDict : public CItem
    {
        struct CompStringItem
        {
            bool operator()(const shared_ptr<CString>& lhs, 
                    const shared_ptr<CString> &rhs) const
            {
                return lhs->GetValue() < rhs->GetValue();
            }
        };
        using ValueType = std::map<shared_ptr<CString> , 
              shared_ptr<CItem>, CompStringItem>;
        public:

        auto & operator[](const auto &key);
        
        private:
        ValueType value_;
    };

    class CInteger : public CItem
    {
        public:
        using ValueType = std::int64_t;
        public:
        CInteger();
        CInteger(ValueType&);
        private:
        ValueType value_;
    };
}

#endif
