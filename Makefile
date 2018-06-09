appname := social_score

CXX := clang++
CXXFLAGS := -std=c++17
TEST_CXXFLAGS := -std=c++17 -fprofile-instr-generate -fcoverage-mapping
LDFLAGS=

srcfiles := $(shell find . ! -name "tests.cpp" -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))


test_srcfiles := $(shell find . ! -name "main.cpp" -name "*.cpp")
test_objects  := $(patsubst %.cpp, %.o, $(test_srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS) $(LDFLAGS)

tests: $(test_objects)
	$(CXX) $(TEST_CXXFLAGS) $(LDFLAGS) -o tests $(test_objects) $(LDLIBS) $(LDFLAGS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
