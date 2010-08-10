# Makefile for conway-text

all: conway

conway: main.o controller.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cc controller.h
controller.o: controller.cc controller.h

