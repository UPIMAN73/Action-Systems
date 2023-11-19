#ifndef ACTIONQUEUE_HPP_
#define ACTIONQUEUE_HPP_

#include "action.hpp"

#define MAX_ACTION_QUEUE_SIZE 48

/**
 * @brief 
 * 
 */
typedef struct actionnode_t {
    Action * action;
    actionnode_t * next;
} ActionNode;

/**
 * @brief 
 * 
 */
class ActionQueue
{
private:
    size_t size;
    Action * head;
    Action * tail;
    ActionNode * queue;

    // Methods //
    ActionNode * getQueueTail(ActionNode * current);
    ActionNode * getActionNode(ActionNode * current, Action * dest);
public:
    // Constructors & Destructors //
    ActionQueue();
    ~ActionQueue();

    // Getters //
    size_t getSize();
    Action * getHead();
    Action * getTail();
    Action * search(size_t index);
    size_t getIndex(Action * action);
    Action * searchAction(Action * action);
    
    // Stuff //
    // TODO search based off of states of the action in the queue //

    // Methods //
    void run(); // Allows all actions in the queue to be running desired functions
    void del(Action * action);
    void init(Action * action); // initilize the queue so that way it is more efficent for us to operate on it.
    void push(Action * action);
};

#endif