# Makefile for conway-text

CFLAGS += -Wall -Werror

all: conway

conway: main.o controller.o cell.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cc controller.h cell.h
controller.o: controller.cc controller.h
cell.o: cell.cc cell.h

.PHONY: clean
clean: 
	-rm main.o cell.o controller.o conway


