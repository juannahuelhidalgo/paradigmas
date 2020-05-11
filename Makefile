# information on dependencies (recompiles source files if the local headers have been modified): https://stackoverflow.com/a/52036564


CXX = g++

EXEC          := tateti-funcional
FLAGS         := -g #-Werror -Wextra -Wall # -g is for debugging
CXXFLAGS      := $(FLAGS)
INC           := -I include
SRC           := $(wildcard src/*.cpp)
OBJ           := $(patsubst src/%.cpp, build/%.o, $(SRC))
DEPENDS       := $(patsubst src/%.cpp, build/%.d, $(SRC))

EXEC_TEST     := test
FLAGS_TEST    := $(FLAGS)
CXXFLAGS_TEST := $(CXXFLAGS)
INC_TEST      := $(INC) -I include
SRC_TEST      := $(wildcard tests/*.cpp)
OBJ_TEST      := $(filter-out build/main.o, $(OBJ)) $(patsubst tests/%.cpp, build/%.o, $(SRC_TEST))
DEPENDS_TEST  := $(filter-out build/main.d, $(DEPENDS)) $(patsubst tests/%.cpp, build/%.d, $(SRC_TEST))

# --------------------------------------------------------------

.PHONY: all
all: build/$(EXEC)

build/$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "[OK]  $@"

-include $(DEPENDS)

# '$@' - The file name of the target of the rule. In a pattern rule that 
# has multiple targets, ‘$@’ is the name of whichever target caused the 
# rule’s recipe to be run.

# '$^' - The names of all the prerequisites, with spaces between them. 

# --------------------------------------------------------------

.PHONY: test
test: build/$(EXEC_TEST)

build/$(EXEC_TEST): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS_TEST) $^ -o $@
	@echo "[OK]  $@"

-include $(DEPENDS_TEST)

# --------------------------------------------------------------

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< $(INC) -o $@
	@echo "[OK]  $@"

build/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS_TEST) -MMD -MP -c $< $(INC_TEST) -o $@
	@echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: clean, clear
clean clear:
	rm -f build/*
	@echo "[CL]  build/"
