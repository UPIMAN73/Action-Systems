#include "actionqueue.hpp"

/**
 * @brief Construct a new Action Queue:: Action Queue object
 * 
 */
ActionQueue::ActionQueue() {
    queue = nullptr;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * @brief Destroy the Action Queue:: Action Queue object
 * 
 */
ActionQueue::~ActionQueue() {
    // Conditional deallocation 
    // Just to make sure that we are deallocating things that exist.
    if (queue) {
        delete queue;
    }
    if (head) {
        delete head;
    }
    if (tail) {
        delete tail;
    }
    if (size) {
        size = 0;
    }
}

/**
 * @brief 
 * 
 * @param action 
 */
void ActionQueue::init(Action * action) {
    if (queue == nullptr) {
        queue = new ActionNode{action, nullptr};
        ++size;
    }
    if (head == nullptr) {
        head = action;
    }
    if (tail == nullptr) {
        tail = action;
    }
}

/**
 * @brief 
 * 
 * @param action 
 */
void ActionQueue::push(Action * action) {
    if (size < MAX_ACTION_QUEUE_SIZE) {
        ActionNode * current = getQueueTail(queue);
        current->next = new ActionNode{action, nullptr};
        tail = action;
        ++size;

        // Garbage collection //
        current = nullptr;
    }
    return;
}

/**
 * @brief 
 * 
 * @param action 
 */
void ActionQueue::del(Action * action) {
    size_t index = getIndex(action);
    if (index > 0) {
        ActionNode * current = queue;
        for (; index > 1; index--) {
            if (current) {
                current = queue->next;
            }
            else {
                return;
            }
        }

        // If the next action is actually the action then delete it
        if (current->next->action == action) {
            // For garbage collection purposes
            ActionNode * temp = current->next;

            // Set the next node to the one after (essentially deleting/removing it from queue)
            current->next = current->next->next;
            --size;

            // Equvalent of deleting the pointer
            temp->action = nullptr;
            temp->next = nullptr;
            temp = nullptr;
        }

        // Garbage Collection
        index = 0;
        current = nullptr;
    }
    return;
}

/**
 * @brief Recursive method for getting tail of queue.
 * 
 * @param current 
 * @return ActionNode* 
 */
ActionNode * ActionQueue::getQueueTail(ActionNode * current) {
    if (current) {
        if (current->next) {
            return getQueueTail(current->next);
        } else {
            return current;
        }
    }
    else {
        return nullptr;
    }
}

/**
 * @brief 
 * 
 * @param current 
 * @param dest 
 * @return ActionNode* 
 */
ActionNode * ActionQueue::getActionNode(ActionNode * current, Action * dest) {
    if (current) {
        if (current->action == dest) {
            return current;
        } else {
            return getActionNode(current->next, dest);
        }
    } else {
        return nullptr;
    }
}