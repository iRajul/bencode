#include "items.hxx"

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
/*CList::Clist(ValueType value):itemList_(value)
{}
*/
CList::CList():CItem(){}
void CList::push_back(const auto &bItem)
{
   itemList_.push_back(bItem); 
}

/*CDict::CDict(ValueType value):value_(value)
{}
*/

CDict::CDict():CItem(){};
auto & CDict::operator[](const auto &key)
{
    return value_[key]; 
}

CInteger::CInteger(ValueType &value):CItem(),value_(value)
{}

}
