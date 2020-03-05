#ifndef TESTACTION_H_
#define TESTACTION_H_

#include "action.h"
#include <stdlib.h>

#define NTIMES 3

class TestAction : public Action
{
    //
    public:
        //
        TestAction(string name, uint8_t id)
        {
            // DO NOTHING
            if (!ini)
            {
                m_name = name;
                m_id = id;
                ini = true;
                curState = IDLE;
            }
            else
            {
                curState = IDLE;
                m_name = name;
                m_id = id;
            }
        }

        void init()
        {
            printf("INIT\n");
            curState = RUNNING;
        }

        void run() 
        {
            printf("%d \t RUNNING\n", times);
            if (times == NTIMES)
            {
                curState = FINISHED;
            }
            else
            {
                printf("%d \t %s\n", m_id, m_name.c_str());    
                times = times + 1;
            }
        }

        void stop()
        {
            printf("STOPPING\n");
            ini = false;
        }

    private:
        char times = 0;

};

#endif