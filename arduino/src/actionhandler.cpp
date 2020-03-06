#include "../include/actionhandler.h"

// Action Handler Constructor
ActionHandler::ActionHandler()
{
    if (!m_init)
    {
        m_init = true;
        *actions = new Action[NUM_OF_ACTIONS];
        for (int i = 0; i < NUM_OF_ACTIONS; i++)
        {
            actions[i] = new Action();
        }
    }
}

// get Active Actions
uint8_t ActionHandler::getActiveActions()
{
    int i = 0;

    for (; i < NUM_OF_ACTIONS; i++)
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
    uint8_t id = getActiveActions();
    // if the action list is too much then do not add the action.
    if (id == 0 || id < NUM_OF_ACTIONS)
    {
        actions[id] = a;
    }

    // Add Action
    else
    {
        //DONOTHING
    } 
}

// Delete action by action datatype
void ActionHandler::delAction(Action * a)
{
    uint8_t id = getActiveActions();
    // if the action list is too much then do not add the action.
    for (; id > -1; id--)
    {
        if ((a->getName() == actions[id]->getName()) && (a->getId() == actions[id]->getId()))
        {
            actions[id]->setName("");
            actions[id]->setID(0);
        }

        // Add Action
        else
        {
            //DONOTHING
            if (id == 0)
            {
                break;
            }

            else
            {
                continue;
            }
            
        } 
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
    for (int i = 0; i < getActiveActions(); i++)
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
    for (int i = 0; i < NUM_OF_ACTIONS; i++)
    {
        delete actions[i];
    }
    m_init = false;
}