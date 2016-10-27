#ifndef ITEMS_HXX
#define ITEMS_HXX
#include <memory>
#include <list>
#include <map>
#include <string>
using namespace std; 


namespace nBencode
{
    //! forward decleration 
    class CVisitorBase;
    class CItem
    {
        public:
            CItem(){}
            virtual ~CItem() =0;
            virtual void accept(CVisitorBase*) =0;
    };

    class CList : public CItem
    {
        using ValueType  = std::list<shared_ptr<CItem> >;
        public:
        CList();
        ~CList(){}
        void push_back(const shared_ptr<CItem> &item);	
        /// Iterator (@c BidirectionalIterator).
        using iterator = ValueType::iterator;
        /// Constant iterator (constant @c BidirectionalIterator).
        using const_iterator = ValueType::const_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        void accept(CVisitorBase*);

        private:

        private:
            ValueType itemList_;

    };

    class CString : public CItem
    {
        using ValueType = std::string;
        public:
        CString();
        ~CString(){}
        CString(ValueType&);
        void accept(CVisitorBase*);
        
        
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
              shared_ptr<CItem>, CompStringItem >;
        public:
        using iterator  = ValueType::iterator;
        using const_iterator = ValueType::const_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        void accept(CVisitorBase*);

        using key_type = ValueType::key_type;

        using mapped_type = ValueType::mapped_type;
            
            CDict();
            ~CDict(){}


        mapped_type & operator[](const key_type &key);
        
        private:
        ValueType value_;
    };

    class CInteger : public CItem
    {
        public:
        using ValueType = std::int64_t;
        void accept(CVisitorBase*);
        public:
        //CInteger();
        CInteger(ValueType&);
        ~CInteger(){}
        ValueType GetValue() const;
        private:
        ValueType value_;
    };
}

#endif
