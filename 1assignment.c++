#include <iostream>
using namespace std;

class Student
{
public:
    string Name;
    int Age;
    int Rollnumber;
    string Course;

    void details(string name, int age, int rollnumber, string course)
    {
        Name = name;
        Age = age;
        Rollnumber = rollnumber;
        Course = course;

        cout << "name" << "=" << Name << endl;
        cout << "age" << "=" << Age << endl;
        cout << "rollnumber" << "=" << Rollnumber << endl;
        cout << "course" << "=" << Course << endl;
    };
};

int main()
{
    Student student1;
    student1.details("shahil", 21, 31, "Btech.");
    cout << endl;
    Student student2;
    student2.details("janvii", 20, 16, "pharmecy");
    cout << endl;
    Student student3;
    student3.details("akhil pandey", 21, 8, "btech");
    return 0;
};
