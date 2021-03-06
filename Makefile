# Makefile for conway-text

CFLAGS += -Wall -Werror -Wextra -pedantic
CXXFLAGS += $(CFLAGS)

all: conway

conway: main.o controller.o cell.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cc controller.h cell.h
controller.o: controller.cc controller.h
cell.o: cell.cc cell.h

.PHONY: clean
clean:
	-rm *.o conway


