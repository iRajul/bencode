#include "items.h"

using namespace std;

CString::CString(ValueType value):value_(value)
{}

CString::CString(){}

ValueType CString::GetValue() const
{
    return value_;
}
CList()::Clist(ValueType value):itemList_(value)
{}

Clist::push_back(const auto &bItem)
{
   itemList_.push_back(bItem); 
}

CDict()::CDict(ValueType value):value_(value)
{}

auto & CDict::operator[](const auto &key)
{
    return value_[key]; 
}

CInteger()::CInteger(ValueType value):value_(value)
{}
