#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct  // Stores data about one student
{
    string name;
    vector<string> courses;
} student;

int main()
{
    string inputstring;
    unsigned int studentnumber=0;
    unsigned int coursenumber=0;
    vector<student> students;
    student mystudent;

    cout << "Student name:";
    getline(cin,inputstring);
    while(inputstring.size()>0) // H�mta nytt s� l�nge namnet l�ngre �n 0
    {
        students.push_back(mystudent);
        students[studentnumber].name=inputstring;

        while(true); //inputstring.size()>0)  // H�mta nytt s� l�nge kursnamnet l�ngre �n 0
        {
            cout << "Course name:";
            getline(cin,inputstring);
            if (inputstring.empty())
                break;
            students[studentnumber].courses.push_back(inputstring);
//            cout << "Course name:";
//            getline(cin,inputstring);
        }
        studentnumber++;
        cout << "Student name:";
        getline(cin,inputstring);
    };

// SKriv ut info om alla studenter
    cout << endl;
    studentnumber=0;
    while(studentnumber<students.size())
    {
        cout << "Student number " << studentnumber << ":" << endl;
        cout << students[studentnumber].name << endl;
        coursenumber=0;
        while(coursenumber<students[studentnumber].courses.size())
        {
            cout << "Course number " << coursenumber << ": " << students[studentnumber].courses[coursenumber] << endl;
            coursenumber++;
        };
        studentnumber++;
        cout << "--------------------------------------" << endl;

    }
    return 0;
}
