CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -I./include

TEST_FILES := $(wildcard test/test_*.cpp)
TESTS      := $(patsubst test/%.cpp,%,$(TEST_FILES))
all: $(TESTS)

test_%: test/test_%.cpp
	@$(CXX) $(CXXFLAGS) $< -o $@
	@./$@
	@rm -f $@

clean:
	@rm -f $(TESTS)

.PHONY: all clean