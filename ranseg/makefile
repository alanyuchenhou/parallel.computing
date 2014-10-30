CXX = mpic++
GLOBAL_FLAGS = -g -W -Wall -Wextra -pedantic
CFLAGS += $(GLOBAL_FLAGS) -std=c99
CXXFLAGS += $(GLOBAL_FLAGS) --std=c++0x

OBJECTS = main.o
main.app: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)
main.o: main.cc
.PHONY: clean
clean:
	rm *.o *.app
