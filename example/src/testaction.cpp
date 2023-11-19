/**
 * @file testaction.cpp
 * @author Joshua Calzadillas (jcalzadillas.job@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "testaction.hpp"

TestAction::TestAction() : Action() {
    // 
    puts("Initiated a test action!");
}

TestAction::~TestAction() {
    printf("Deleting a test action!\r\n\t%s\r\n", getName());
    
}

void TestAction::init() {
    setState(INIT);
    puts("Initilizing the action!");
}

void TestAction::run() {
    setState(RUN);
    puts("Running the action!");
}

void TestAction::idle() {
    setState(IDLE);
    puts("Idling the action!");
}

void TestAction::stop() {
    setState(FIN);
    puts("Finishing the action!");
}