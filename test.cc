#include "test.h"

using namespace std;

Test::Test(int id, int w) {
    ID = id;
    weight = w;
}

Test::Test(int id, int w, int cID, int m) {
    ID = id;
    weight = w;
    courseID = cID;
    mark = m;
}
