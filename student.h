#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <vector>
#include <memory>
#include "test.h"
#include "courses.h"

class Student {
    public:
    int ID;
    std::string name;
    float finalgrade;
    std::vector <int> courseidv;
    std::vector <std::shared_ptr<Course>> courses;
    std::vector <std::shared_ptr<Test>> tests;
    Student(int id, std::string n);
};

#endif
