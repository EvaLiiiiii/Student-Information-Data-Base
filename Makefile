CXX = g++-5
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla

#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = STUDENT
OBJECTS = main.o student.o course.o test.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

