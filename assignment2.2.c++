# include <iostream>
using namespace std;
#include <iostream>
using namespace std;


class ILogger {
public:
    virtual void Log() = 0; // Pure virtual function
};


class DatabaseLogger : public ILogger {
public:
    void Log() override {
        cout << "Log Written to Database " << endl;
    }
};

class FileLogger : public ILogger {
public:
    void Log() override {
        cout << "Log Written to File " << endl;
    }
};

class CloudLogger : public ILogger {
public:
    void Log() override {
        cout << "Log Written to Cloud " << endl;
    }
};


int main() {
    string userLog;
    cout << "Enter the Log type : ";
    cin >> userLog;

    ILogger* log = nullptr;

    
    if (userLog == "Database") {
        log = new DatabaseLogger();
    } else if (userLog == "File") {
        log = new FileLogger();
    } else if (userLog == "Cloud") {
        log = new CloudLogger();
    }

   
    if (log != nullptr) {
        log->Log();
        delete log; 
    } else {
        cout << "Invalid Log Type" << endl;
    }


}
