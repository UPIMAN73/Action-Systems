#include "../include/action.h"

// Action declaration (improper or default)
Action::Action()
{
    if (!ini)
    {
        m_name = "";
        m_id = 0;
        ini = true;
        curState = IDLE;
    }
}

// Action declaration (proper)
Action::Action(string name, uint8_t id)
{
    if (!ini)
    {
        m_name = name;
        m_id = id;
        ini = true;
        curState = IDLE;
    }
}


/*
 * Setters and Getters for the Action class
 */

void Action::setName(string name)
{
    m_name = name;
}

void Action::setID(uint8_t id)
{
    m_id = id;
}

// getters
uint8_t Action::getId()
{
    return m_id;
}

string Action::getName()
{
    return m_name;
}

STATE Action::getState()
{
    return curState;
}