/**
 * @file testaction.hpp
 * @author Joshua Calzadillas (jcalzadillas.job@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef TESTACTION_HPP_
#define TESTACTION_HPP_

#include <stdio.h>

using namespace std;

#include "action.hpp"

/**
 * @brief Test Action Class
 * Demonstrates the use for action state classes.
 * Since they are important for multiple function job runners.
 * Parallel processing and other funcitonal systems.
 */
class TestAction : public Action
{
public:
    // Constructors & Destructors //
    TestAction();
    ~TestAction();

    // Action Methods/Functions //
    void init(); // Init Processing (Initilizes the Action)
    void run();  // Active Processing (high load runner)
    void idle(); // Idle Processing (only used when you want idle runners)
    void stop(); // Stop Processing
};

#endif