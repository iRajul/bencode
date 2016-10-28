#include "items.hxx"
#include "visitor.hxx"
using namespace std;

namespace nBencode
{

    CItem::~CItem()
    {}
    CString::CString(ValueType &value):CItem(), 
    value_(value)
    {}

    CString::CString():CItem(){}

    auto CString::GetValue()  const -> ValueType
    {
        return value_;
    }
    void CString::accept(CVisitorBase* pVisitor)
    {
        pVisitor->visit(this);
    }
    /*CList::Clist(ValueType value):itemList_(value)
      {}
      */
    CList::CList():CItem(){}
    void CList::push_back(const shared_ptr<CItem> &bItem)
    {
        itemList_.push_back(bItem); 
    }
    void CList::accept(CVisitorBase* pVisitor)
    {
        pVisitor->visit(this);
    }
    /**
     * @brief Returns an iterator to the beginning of the list.
     */
    CList::iterator CList::begin() {
        return itemList_.begin();
    }

    /**
     * @brief Returns an iterator to the end of the list.
     */
    CList::iterator CList::end() {
        return itemList_.end();
    }

    /**
     * @brief Returns a constant iterator to the beginning of the list.
     */
    CList::const_iterator CList::begin() const {
        return itemList_.begin();
    }

    /**
     * @brief Returns a constant iterator to the end of the list.
     */
    CList::const_iterator CList::end() const {
        return itemList_.end();
    }

    /**
     * @brief Returns a constant iterator to the beginning of the list.
     */
    CList::const_iterator CList::cbegin() const {
        return itemList_.cbegin();
    }

    /**
     * @brief Returns a constant iterator to the end of the list.
     */
    CList::const_iterator CList::cend() const {
        return itemList_.cend();
    }

    /*CDict::CDict(ValueType value):value_(value)
      {}
      */

    CDict::CDict():CItem(){}
    CDict::mapped_type & CDict::operator[](const key_type &key)
    {
        return value_[key]; 
    }
    void CDict::accept(CVisitorBase* pVisitor)
    {
        pVisitor->visit(this);
    }
    /**
     * @brief Returns an iterator to the beginning of the dictionary.
     */
    CDict::iterator CDict::begin() {
        return value_.begin();
    }

    /*
     * @brief Returns an iterator to the end of the dictionary.
     */
    CDict::iterator CDict::end() {
        return value_.end();
    }

    /**
     * @brief Returns a constant iterator to the beginning of the dictionary.
     */
    CDict::const_iterator CDict::begin() const {
        return value_.begin();
    }

    /**
     * @brief Returns a constant iterator to the end of the dictionary.
     */
    CDict::const_iterator CDict::end() const {
        return value_.end();
    }

    /**
     * @brief Returns a constant iterator to the beginning of the dictionary.
     */
    CDict::const_iterator CDict::cbegin() const {
        return value_.cbegin();
    }

    /**
     * @brief Returns a constant iterator to the end of the dictionary.
     */
    CDict::const_iterator CDict::cend() const {
        return value_.cend();
    }

    CInteger::CInteger(ValueType &value):CItem(),value_(value)
    {}

    void CInteger::accept(CVisitorBase* pVisitor)
    {
        pVisitor->visit(this);
    }
    auto CInteger::GetValue() const -> ValueType
    {
        return value_;
    }
}
