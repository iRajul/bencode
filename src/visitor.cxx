#include "visitor.hxx"
#include<string>
#include <iostream>
namespace nBencode
{
    CVisitorBase::~CVisitorBase(){}
    CVisitorBase::CVisitorBase(){}

    CPrintPretty::CPrintPretty() : CVisitorBase()
    {
    }
    void CPrintPretty::visit(CString* pString)
    {
        sData += '"' + pString->GetValue() + '"'; 
    }

    void CPrintPretty::visit(CList* pList)
    {
        sData += "[\n";
        bool bComma = false;
        for(auto bItem : *pList)
        {
            if(bComma)
            {
                sData += ", ";
            }
            bItem->accept(this);
        }
        sData += "]\n";
    }

    void CPrintPretty::visit(CDict* pDict)
    {
        sData += "{\n";
        sCurrIndent += "    ";
        bool bComma = false;
        for(auto bItem : *pDict)
        {
            if(bComma)
            {
                sData += ", ";
                sData += "\n";
            }
            sData += sCurrIndent;
            bItem.first->accept(this);
            sData += " : ";
            bItem.second->accept(this);
            bComma = true;
        }
        sCurrIndent = sCurrIndent.substr(0, sCurrIndent.length()-4);
        sData  = sData +  "\n" + sCurrIndent + "}";
    }

    void CPrintPretty::visit(CInteger* pInterger)
    {
        sData += std::to_string(pInterger->GetValue());
    }
    
    void CPrintPretty::Print(shared_ptr<CItem> pData)
    {
        pData->accept(this);
        cout<<sData<<endl;
    }
}
