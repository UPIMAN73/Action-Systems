#ifndef ACTIONMAN_HPP_
#define ACTIONMAN_HPP_

#include "actionqueue.hpp"

using namespace std;

/**
 * @brief 
 * 
 */
class ActionManager
{
private:
    ActionQueue * actions;
public:
    ActionManager();
    ~ActionManager();

    // Getters //
    Action * getAction();

    // Methods //
    void addAction(Action * action);
    void delAction(Action * action);
    Action * search(Action * action);
    bool actionInQueue(Action * action);
};

#endif