#include "actionman.hpp"

ActionManager::ActionManager()
{
    actions = new ActionQueue();
}

ActionManager::~ActionManager()
{
    delete actions;
}

// add action
void ActionManager::addAction(Action * action) {
    actions->push(action);
}

bool ActionManager::actionInQueue(Action * action) {
    // 
    return false;
}

Action * ActionManager::search(Action * action) {
    // 
    return nullptr;
}