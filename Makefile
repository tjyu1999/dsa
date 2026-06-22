CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -I./include -I./src

TEST_FILE := $(wildcard test/test_*.cpp)
TEST      := $(patsubst test/%.cpp,%,$(TEST_FILE))
all       : $(TEST)

test_%: test/test_%.cpp
	@$(CXX) $(CXXFLAGS) $< -o $@
	@./$@
	@rm -f $@

clean:
	@rm -f $(TEST)

.PHONY: all clean