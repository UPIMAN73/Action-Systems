#ifndef ACTION_H_
#define ACTION_H_
#include <unistd.h>

#include <string>

using namespace std;

// State setup
enum STATE
{
    IDLE = 0,
    RUNNING,
    FINISHED
};

class Action
{
    public:
        Action();                           // Default constructor
        Action(string name, uint8_t id);    // Action class (name and id to be assigned as)

        virtual void init() {}     // Init Function
        virtual void run() {}      // Run Function
        virtual void stop() {}     // Stop Function

        // Set the name and id
        void setName(string name);  // Set the name 
        void setID(uint8_t id);     // Set the id
        void setState(STATE s);     // Set the state

        // Get the name and ID
        string getName();       // get the name
        uint8_t getId();        // get the id
        STATE getState();       // Get the current state
        

    protected:
        // Variables that are used to define the action
        string m_name;
        uint8_t m_id;
        bool ini = false;

        // Current State
        STATE curState;

        

};

#endif