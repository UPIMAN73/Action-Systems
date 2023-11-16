/**
 * @file action.hpp
 * @author Joshua Calzadillas (jcalzadillas.job@gmail.com)
 * @brief Action based system that 
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ACTION_HPP_
#define ACTION_HPP_

// Defined Maximums
#define MAX_char *_SIZE 32

/**
 * @brief 
 * 
 */
typedef enum state_t {
    NULL = 0,
    INIT,
    IDLE,
    FIN
} State;

/**
 * @brief Action Class
 * Action defines the parameters necessary to
 * opearate a action-based system with ease.
 */
class Action {
    private:
        State state;    // Action State
        char * name;    // Action Name
    
    public:
        // Constructors & Destructors
        Action();
        Action(const char * Name);
        ~Action();

        // Getters //
        State getState();
        const char * getName();

        // Setters //
        void setName(const char * Name);
        // TODO Recursive Secure Set //

        // Methods //
        void clearName();

        // Action Methods/Functions //
        void init();    // Init Processing (Initilizes the Action)
        void run();     // Active Processing (high load runner)
        void idle();    // Idle Processing (only used when you want idle runners)
        void stop();    // Stop Processing
};

#endif