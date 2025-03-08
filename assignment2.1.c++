#include <iostream>
using namespace std;

class Logger
{
public:
    void virtual log()
    {
        cout << "Log " << endl;
    }
};

// Derived logger classes
class DatabaseLogger : public Logger
{
public:
    void log() override
    {
        cout << "Log written to Database " << endl;
    }
};

class FileLogger : public Logger
{
public:
    void log() override
    {
        cout << "Log written to File " << endl;
    }
};

class CloudLogger : public Logger
{
public:
    void log() override
    {
        cout << "Log written to Cloud " << endl;
    }
};

int main()
{
    Logger *ptr1;               /*using pointers to store the objects in referense base classes,
                            A base class pointer (ILogger* ptr) is used to store a child class object dynamically*/
    DatabaseLogger obj1;
    ptr1 = &obj1;
    ptr1->log();

    Logger *ptr2;
    FileLogger obj2;
    ptr2 = &obj2;
    ptr2->log();

    Logger *ptr3;
    CloudLogger obj3;
    ptr3 = &obj3;
    ptr3->log();

    return 0;
}