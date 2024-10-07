CXX = g++
SOURCES = main.cpp push_and_pop.cpp ctor_and_dtor.cpp verifier_and_dump.cpp my_realloc.cpp hash.cpp
EXECUTABLE_FILE = stack
CFLAGS = -b
WARNINGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
		   -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
		   -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe \
		   -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body \
		   -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		   -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual \
		   -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
		   -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
		   -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: stack

stack: main.o push_and_pop.o ctor_and_dtor.o verifier_and_dump.o my_realloc.o hash.o
	$(CXX) $(SOURCES) -o $(EXECUTABLE_FILE) $(WARNINGS)

main.o: main.cpp
	$(CXX) main.cpp -c

push_and_pop.o: push_and_pop.cpp
	$(CXX) push_and_pop.cpp -c

ctor_and_dtor.o: ctor_and_dtor.cpp
	$(CXX) ctor_and_dtor.cpp -c

verifier_and_dump.o: verifier_and_dump.cpp
	$(CXX) verifier_and_dump.cpp -c

my_realloc.o: my_realloc.cpp
	$(CXX) my_realloc.cpp -c

hash.o: hash.cpp
	$(CXX) hash.cpp -c