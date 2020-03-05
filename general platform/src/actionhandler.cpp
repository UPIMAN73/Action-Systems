#include "../include/actionhandler.h"

// Action Handler Constructor
ActionHandler::ActionHandler()
{
    if (!m_init)
    {
        m_init = true;
    }
}

// get Active Actions
uint8_t ActionHandler::getActiveActions()
{
    int i = 0;

    for (; (i < NUM_OF_ACTIONS) && i < actions.size(); i++)
    {   
        // if a null action shows up then break loop
        if ((actions[i]->getName() == "") && (actions[i]->getId() == 0))
        {
            return i;
        }

        // Continue through the action table
        else
        {
            continue;
        }
    }

    return i;
}


// Add action to the action list
void ActionHandler::addAction(Action * a)
{
    // if the action list is too much then do not add the action.
    if (getActiveActions() == 0 || getActiveActions() < NUM_OF_ACTIONS)
    {
        actions.push_back(a);
    }

    // Add Action
    else
    {
        //DONOTHING
    }
    
}


// IMPORTANT FUNCTION
/*
 * Check allows the 
 */
void ActionHandler::check()
{
    // Go through each state in active state actions and run their proper functions
    STATE cur_state = IDLE;

    // Enter the action check and state function loop
    for (int i = 0; i < actions.size(); i++)
    {
        cur_state = actions[i]->getState(); // Get current status of the action

        switch(cur_state)
        {
            // Idle Case
            case IDLE:
                actions[i]->init();
                break;
        
            // Running Case
            case RUNNING:
                actions[i]->run();
                break;
            
            // Finished Case
            case FINISHED:
                actions[i]->stop();
                actions[i]->setName("");
                actions[i]->setID(0);
        }
    }
    cur_state = IDLE;   // To clean up the values
}


void ActionHandler::clean()
{
    // Clear all of the actions
    actions.clear();
    m_init = false;
}