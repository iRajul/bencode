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
void CList::push_back(const shared_ptr<CItem> &bItem)
{
   itemList_.push_back(bItem); 
}

/*CDict::CDict(ValueType value):value_(value)
{}
*/

CDict::CDict():CItem(){};
CDict::mapped_type & CDict::operator[](const key_type &key)
{
    return value_[key]; 
}

CInteger::CInteger(ValueType &value):CItem(),value_(value)
{}

}
