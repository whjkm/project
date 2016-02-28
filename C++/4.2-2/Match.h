#ifndef MATCH_H
#define MATCH_H
#include "Time.h"

class Match
{
    public:
        Match(int hour,int min,int sec);
        void testTime();
    protected:
    private:
        Time m_tTimer;
};

#endif // MATCH_H
