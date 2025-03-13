#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;




class ILogger
{
public:
    virtual void LogError(const string &message) = 0;
    virtual ~ILogger() = default;
};


class ConsoleLogger : public ILogger
{
public:
    void LogError(const string &message) override
    {
        cout << "Log Error: " << message << endl;
    }
};




class IOrderProcessor
{
public:
    virtual void ProcessOrder() = 0;
    virtual ~IOrderProcessor() = default;
};




class Customer
{
protected:
    string firstName, lastName, email;
    int customerId;

public:
    Customer(int id, string fName, string lName, string mail)
        : customerId(id), firstName(fName), lastName(lName), email(mail) {}

    virtual int GetDiscountPercentage() = 0;
    virtual bool SaveCustomer() = 0;

    void Register(ILogger *logger)
    {
        try
        {
            SaveCustomer();
        }
        catch (const exception &ex)
        {
            logger->LogError(ex.what());
        }
    }

    virtual ~Customer() = default;
};



class BronzeCustomer : public Customer
{
public:
    BronzeCustomer(int id, string fName, string lName, string mail)
        : Customer(id, fName, lName, mail) {}

    int GetDiscountPercentage() override { return 15; }
    bool SaveCustomer() override
    {
     

        return true;
    }
};

class SilverCustomer : public Customer
{
public:
    SilverCustomer(int id, string fName, string lName, string mail)
        : Customer(id, fName, lName, mail) {}

    int GetDiscountPercentage() override { return 20; }
    bool SaveCustomer() override
    {
       
        return true;
    }
};

class GoldCustomer : public Customer
{
public:
    GoldCustomer(int id, string fName, string lName, string mail)
        : Customer(id, fName, lName, mail) {}

    int GetDiscountPercentage() override { return 25; }
    bool SaveCustomer() override
    {
        // Save logic
        return true;
    }
};

class PlatinumCustomer : public Customer
{
public:
    PlatinumCustomer(int id, string fName, string lName, string mail)
        : Customer(id, fName, lName, mail) {}

    int GetDiscountPercentage() override { return 27; }
    bool SaveCustomer() override
    {
        
        return true;
    }
};



class Lead : public IOrderProcessor
{
public:
    int GetDiscountPercentage() { return 12; }

    void ProcessOrder() override
    {
    

        cout << "Processing order for lead customer..." << endl;
    }
};



class OrderProcessor
{
private:
    IOrderProcessor *orderProcessor;

public:
    OrderProcessor(IOrderProcessor *processor) : orderProcessor(processor) {}

    void Process()
    {
        orderProcessor->ProcessOrder();
    }
};

// Program Entry
int main()
{
    unique_ptr<ILogger> logger = make_unique<ConsoleLogger>();
    unique_ptr<Customer> customer = make_unique<GoldCustomer>(1, "John", "Doe", "john@example.com");

    customer->Register(logger.get());

    Lead lead;
    OrderProcessor orderProcessor(&lead);
    orderProcessor.Process();

    return 0;
}