#ifndef INDEXEXCEPTION_H
#define INDEXEXCEPTION_H
#include "Exception.h"

class IndexException:public Exception
{
    public:
        //virtual ~IndexException();
        virtual void printException();
};

#endif // INDEXEXCEPTION_H
