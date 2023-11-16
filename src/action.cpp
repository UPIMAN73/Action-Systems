#include "../inc/action.hpp"

/**
 * @brief Construct a new Action:: Action object
 * 
 */
Action::Action() {
    name = new char[MAX_STRING_SIZE];
    state = NULL;
}

/**
 * @brief Construct a new Action:: Action object
 * 
 * @param Name 
 */
Action::Action(const char * Name) {
    name = new char[MAX_STRING_SIZE];
    setName(Name);
    state = NULL;
}

/**
 * @brief Destroy the Action:: Action object
 * 
 */
Action::~Action() {
    name = "";
    state = NULL;
}

/////////////
// Getters //
/////////////

/**
 * @brief 
 * 
 * @return State 
 */
State Action::getState() {
    return state;
}

/**
 * @brief Get the name of the action in a pointer format.
 * Does not completly work with functions that do not support
 * pointer based prints.
 * 
 * @return const char* 
 */
const char * Action::getName() {
    return (const char *) name;
}

/////////////
// Setters //
/////////////

/**
 * @brief 
 * 
 * @param Name 
 */
void Action::setName(const char * Name) {
    // Index variable
    unsigned char index = 0;

    // Setting values
    while(index < MAX_STRING_SIZE) {
        name[index] = Name[index];
        if (Name[index] == '\0') {
            break;
        }
        index++;
    }

    // Garbage collection
    index = 0;
}

/////////////
// Methods //
/////////////

/**
 * @brief Clear the name
 * 
 */
void Action::clearName() {
    // Index variable
    unsigned char index = 0;

    // Setting name buffers to 0
    while (name[index] != '\0') {
        name[index] = '\0';
        if (index <= MAX_STRING_SIZE) {
            index++;
        } else {
            break;
        }
    }

    // Garbage collection
    index = 0;
}