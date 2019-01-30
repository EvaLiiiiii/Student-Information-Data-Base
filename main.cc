#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>
#include "student.h"
#include "courses.h"
#include "test.h"

using namespace std;
int main () {
    string sfilename;
    string cfilename;
    string tfilename;
    string mfilename;
    cin >> sfilename;
    cin >> cfilename;
    cin >> tfilename;
    cin >> mfilename;
    vector <shared_ptr<Student>> report;
    string line;
    ifstream stufile(sfilename);
    // first go through the students file
    int posn = 0;
    while (getline(stufile, line)) {
        if (posn == 0) {
             posn++;
            // skip the header
            continue;
        } else {
            stringstream ss;
            ss.str(line);
            string tempid;
            string name;
            getline(ss,tempid,',');
            int id = stoi(tempid);
            getline(ss, name);
            auto s = make_shared<Student>(id, name);
            report.emplace_back(s);
        }
        }
    posn = 0;

    ifstream coufile(cfilename);
    vector <shared_ptr<Course>> coursev;
    //then the courses file 
    while (getline(coufile, line)) {
        if (posn == 0) {
            posn ++;
            // skip the header
            continue;
        } else {
            stringstream ss;
            ss.str(line);
            string tempid;
            string name;
            string teacher;
            getline(ss,tempid,',');
            int id = stoi(tempid);
            getline(ss, name, ',');
            getline(ss, teacher);
            auto s = make_shared<Course>(id, name, teacher);
            coursev.emplace_back(s);
        }
        }

    ifstream tstfile(tfilename);
    //tests file 
    map<int, shared_ptr<Course>> TtoC;
    vector <shared_ptr<Test>> testv;
    posn = 0;
    while (getline(tstfile, line)) {
        if (posn == 0) {
            posn++;
            continue;
        } else {
            stringstream ss;
            ss.str(line);
            string tempid;
            string tempid2;
            string weight;
            getline(ss,tempid,',');
            int id = stoi(tempid);
            getline(ss, tempid2, ',');
            int courseid = stoi(tempid2);
            getline(ss, weight);
            int w = stoi(weight);
            auto s = make_shared<Test>(id,w);
            testv.emplace_back(s);
            for (auto &n:coursev) {
                if (courseid == n->ID) {
                    TtoC[id] = n;
                }// map each test to its corresponding course
            }
        }
    }

    ifstream markfile(mfilename);
    //marks file 
    posn = 0;
    while (getline(markfile, line)) {
        if (posn == 0) {
            posn++;
            continue;
        } else {
            stringstream ss;
            ss.str(line);
            string tempid;
            string tempid2;
            string tempmark;
            getline(ss,tempid,',');
            int testid = stoi(tempid);
            int w = 0;
            for (auto &n:testv) {
                if (n->ID == testid) {
                    w = n->weight;
                }
            }
            auto search = TtoC.find(testid);
            int courseid = search->second->ID;
            getline(ss, tempid2, ',');
            int studentid = stoi(tempid2);
            getline(ss, tempmark);
            int mark = stoi(tempmark);
            auto s = make_shared<Test>(testid, w,courseid, mark);
            for (auto &n:report) {
                if (n->ID == studentid) {
                    n->tests.emplace_back(s);
                }
            }// add a vector of tests into each student's file
        }
    }

    for (auto &n:report) {
        for (auto &m:n->tests) {
                    n->courseidv.emplace_back(m->courseID);
                }
        sort(n->courseidv.begin(), n->courseidv.end());
        n->courseidv.erase( unique(n->courseidv.begin(), n->courseidv.end()), n->courseidv.end());
    }
        // make a list of all the course IDs with no duplicates for all students 
        for (auto &n:report) {
            for (auto &c:n->courseidv) {
                float g = 0;
                   for (auto &m:n->tests) {
                       if (m->courseID == c) {
                           g += m->weight*0.01*m->mark;
                       }
                   }
                   for (auto &i:coursev) {
                       if (i->ID == c) {
                           auto dup = make_shared<Course>(*i);
                           dup->grade = g;
                           n->courses.emplace_back(dup);
                       }
                   }
            }
            float f = 0;;
            for (auto &h:n->courses) {
                f += h->grade;
            }
            n->finalgrade = f/n->courses.size();
        }// calculating grades


      for (auto &n:report) {
          cout << "Student Id: " << n->ID<<", name: "<<n->name<<endl;
          cout << "Total Average:      "<<setprecision(2)<<fixed <<  n->finalgrade<<"%"<<endl<<endl;
            for (auto &m:n->courses) {
                cout <<"        Course: "<<m->name<<", Teacher: "<<m->teacher<<endl;
                cout <<"        Final Grade:      "<<setprecision(2)<<fixed<< m->grade<<"%"<<endl<<endl;
                }
            cout <<endl<<endl;
            }
}

