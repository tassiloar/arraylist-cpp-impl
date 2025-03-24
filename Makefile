# Makefile for HW1: ArrayList
# Matt Russell
# 
# This Makefile will build unit_test for the unit_testing 
# framework.

CXX=clang++
CXXFLAGS=-g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS=-g3


timer: timer_main.o CharArrayList.o
	${CXX} ${LDFLAGS} -o timer timer_main.o CharArrayList.o

unit_test: unit_test_driver.o CharArrayList.o
	${CXX} unit_test_driver.o CharArrayList.o

CharArrayList.o: CharArrayList.cpp CharArrayList.h
	${CXX} ${CXXFLAGS} -c CharArrayList.cpp

timer_main.o: timer_main.cpp CharArrayList.h
	${CXX} ${CXXFLAGS} -c timer_main.cpp

clean: 
	rm *.o a.out *~ *#
