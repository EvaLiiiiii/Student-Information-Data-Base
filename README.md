# Student-Information-Gathering
The program STUDENT is consist of four major parts:
a Student class, 
a Courses class,
a Test class and a main function.
The program's executable file is called "STUDENT" and it takes zero argument.
The program must take four arguments: 
a csv file with the students'IDs and names,
a csv file with the courses'IDs, names and teachers,
a csv file with the tests'IDs, their corresponding courses and weights,
a csv file with the the test IDs that each students took and their grades,
The order of the input must follow the above instructions,

For example, if given the following command and input

```./STUDENT
students.csv
courses.csv
tests.csv
marks.csv ```

we would get

```Student Id: 1, name: A
Total Average:      72.03%

        Course: Biology, Teacher: Mr. D
        Final Grade:      90.10%

        Course: History, Teacher:  Mrs. P
        Final Grade:      51.80%

        Course: Math, Teacher:  Mrs. C
        Final Grade:      74.20%



Student Id: 2, name: B
Total Average:      62.15%

        Course: Biology, Teacher: Mr. D
        Final Grade:      50.10%

        Course: Math, Teacher:  Mrs. C
        Final Grade:      74.20%



Student Id: 3, name: C
Total Average:      72.03%

        Course: Biology, Teacher: Mr. D
        Final Grade:      90.10%

        Course: History, Teacher:  Mrs. P
        Final Grade:      51.80%

        Course: Math, Teacher:  Mrs. C
        Final Grade:      74.20%```



