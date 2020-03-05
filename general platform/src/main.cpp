#include "../include/actionhandler.h"
#include "../include/testaction.h"

#include <iostream>

using namespace std;

// Arduino Functions
void setup();
void loop();
void cleanup();
void println(string a);

// Control Loop Function
bool m_loop = true;

// Action Group
ActionHandler ah;

// main code
int main()
{
    setup();

    while (m_loop)
    {
        loop();
    }

    cleanup();

    // default for some compilers
    return 0;
}

// Main setup code
void setup()
{
    // Action Handler
    ah = ActionHandler();
    println("Action Handler is Setup.");
    
    // Test Action Added to the Action Handler
    ah.addAction(new TestAction("John", 1));
    ah.addAction(new TestAction("Doe", 2));
    ah.addAction(new TestAction("Sam", 3)); 
    ah.addAction(new TestAction("Smith", 4));

    // Starting the action handler
    println("Action Handler Start...");
}

// Loop function that goes into the main loop
void loop()
{
    try{
        // if there are any live actions then do action handler check
        if (ah.getActiveActions() > 0)
        {
            printf("Number of Active Actions: %d\n", ah.getActiveActions());

            // Action handler check call
            ah.check();
        }

        // Else end the loop for the entire program
        else
        {
            //DONOTHING
            m_loop = false;
        }
    }

    // if there are any issues then call the issue and end loop
    catch (std::bad_alloc &ba)
    {
        cerr << "Bad Alloc Cought: " << ba.what() << endl;
        m_loop = false;
    }   
}


// Clean up function
void cleanup()
{
    ah.clean(); // clean the Action handler
}

// Simple println function
void println(string a)
{
    printf("%s\n", a.c_str());
}