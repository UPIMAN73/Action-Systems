

#include <vector>
#include <stdio.h>

using namespace std;


class A
{
    public:
    A()
    {
        x = 10;
    }

    virtual void update() {}
    virtual void print() {}

    int x = 0;
    int y = 0;
};

class B : public A
{
    public:
    B()
    {
        y = 20;
        z = y/x;
    }

    void update()
    {
        x += 1;
        y -= 1;
        z = 2 * x - 1;
    }

    void print()
    {
        printf("%d\t%d\t%d\n", x, y, z);
    }

    int z = 0;
};

class ABH
{
    //
    public:
    ABH()
    {
        //
    }

    void run()
    {
        //
        B ab = B();
        avect.push_back(&ab);

        for (int i = 0; i < 19; i++)
        {
            avect[0]->update();
            avect[0]->print();
        }
    }

    vector<A*> avect;
};

int main()
{
    

    ABH abh = ABH();
    abh.run();
    return 0;
}