#ifndef _COURSES_H_
#define _COURSES_H_
#include <string>

class Course {
    public:
    int ID;
    std::string name;
    std::string teacher;
    float grade;
    Course(int id, std::string n, std::string t);
};

#endif
