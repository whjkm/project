#include "Worker.h"
#include "Farmer.h"

class MigrantWorker:public Worker,public Farmer
{
    public:
        MigrantWorker(string name,string code);
        virtual ~MigrantWorker();
};

