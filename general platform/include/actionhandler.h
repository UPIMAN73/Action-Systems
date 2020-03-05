#ifndef ACTIONHANDLER_H_
#define ACTIONHANDLER_H_

#include "action.h"
#include <vector>

// Number of actions within the action table
#define NUM_OF_ACTIONS 10


class ActionHandler
{
    public:
        ActionHandler();             // Action Handler Constructor

        // Action functions
        void check();                // check the status of the actions within the groups
        void clearFinished();        // Clear all of the finished actions

        // Action Handling
        void delAction(Action * a);    // Delete Action
        void addAction(Action * a);    // Add an action to the group of actions

        // Clean up functions
        void clean();                // Clean up everything within this class.
        void stop();                 // Autostop everything

        uint8_t getActiveActions();  // Get the number of active actions within the table
        
    private:
        std::vector<Action*> actions;    // Action Table to have systems be called
        bool m_init = false;                // Initilization Boolean
};

#endif