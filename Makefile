

CXX=clang++
CXXFLAGS=-g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS=-g3


unit_test: unit_test_driver.o CharArrayList.o
	${CXX} unit_test_driver.o CharArrayList.o

CharArrayList.o: CharArrayList.cpp CharArrayList.h
	${CXX} ${CXXFLAGS} -c CharArrayList.cpp

clean: 
	rm *.o a.out *~ *#
