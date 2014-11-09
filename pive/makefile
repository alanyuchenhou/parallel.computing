GLOBAL_FLAGS= -g -W -Wall -Wextra -Werror -pedantic -fopenmp -lgomp # -pthread
CFLAGS += $(GLOBAL_FLAGS) -std=c99
CXXFLAGS += $(GLOBAL_FLAGS) --std=c++0x
LDFLAGS:= -lm -lprofiler -fopenmp
OBJECTS = main.o

main.out: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)
main.o: main.cc
.PHONY: clean
clean:
