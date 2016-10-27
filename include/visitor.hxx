#ifndef VISITOR_HXX
#define VISITOR_HXX   
#include<string>
#include<memory>
#include "items.hxx"

namespace nBencode
{
    class CVisitorBase
    {
        public:
            virtual ~CVisitorBase() = 0;
            virtual void visit(CInteger* pInteger)=0;
            virtual void visit(CList* pList)=0;
            virtual void visit(CDict* pDict)=0;
            virtual void visit(CString* pString)=0;
        protected:
            CVisitorBase();
    };


    class CPrintPretty : public CVisitorBase
    {
        public:
            CPrintPretty();
        private:
            std::string sData;
            std::string sCurrIndent;
        public:
            void visit(CInteger* pInteger);
            void visit(CList* pList);
            void visit(CDict* pDict);
            void visit(CString* pString);

            void Print(shared_ptr<CItem> pData);
    };

}


#endif /* VISITOR_HXX */
