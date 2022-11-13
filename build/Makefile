all: debug

print-%: ; @echo $*=$($*)

# List headers here
HEADERS = \
	generic_defs/vector.h

# Don't need object files for these. HORRIBLE HACK for now.
ABS_H_FILES = \

# Builds list of sources
SOURCES = $(HEADERS:%.h=%.cpp)

# Defines location of the object files
OBJ_LOC = ../obj

# Defines the objects for the debug build
OBJ_DEBUG_SUFFIX = debug.o
OBJS_DEBUG = $(SOURCES:%.cpp=$(OBJ_LOC)/%.$(OBJ_DEBUG_SUFFIX))

# Defines the objects for the release build
OBJ_RELEASE_SUFFIX = release.o
OBJS_RELEASE = $(SOURCES:%.cpp=$(OBJ_LOC)/%.$(OBJ_RELEASE_SUFFIX)) 

# Libraries
LIBS =

# Excecutable names for testers
TEST_TARGET = ../bin/test

EMPTY_MAP_TARGET = ../bin/empty_map

STARCRAFT_MAP_TARGET = ../bin/starcraft_map

# Defines the compiler and the compiler flags
CC = g++
CXXFLAGS = -Wall -pedantic -ansi -Werror -Wno-unused-function -std=c++11
CXXRELEASEFLAGS = -O3 $(CXXFLAGS)
CXXDEBUGFLAGS = -g $(CXXFLAGS)

# Builds object files
$(OBJS_DEBUG): $(OBJ_LOC)/%.$(OBJ_DEBUG_SUFFIX) : ../src/%.cpp ../src/%.h $(ABS_H_FILES)
	@mkdir -p $(@D)
	$(CC) $(CXXDEBUGFLAGS) -c $< -o $@
	
$(TEST_TARGET): $(OBJS_DEBUG) ../src/experiments/vector_test.cpp
	$(CC) $(CXXDEBUGFLAGS) -o $(TEST_TARGET) ../src/experiments/vector_test.cpp $(OBJS_DEBUG) $(LIBS)
	
#$(EMPTY_MAP_TARGET): $(OBJS_DEBUG) ../src/experiments/empty_grid_experiments.cpp
#	$(CC) $(CXXDEBUGFLAGS) -o $(EMPTY_MAP_TARGET) ../src/experiments/empty_grid_experiments.cpp $(OBJS_DEBUG) $(LIBS)
	
#$(STARCRAFT_MAP_TARGET): $(OBJS_DEBUG) ../src/experiments/starcraft_map_experiments.cpp
#	$(CC) $(CXXDEBUGFLAGS) -o $(STARCRAFT_MAP_TARGET) ../src/experiments/starcraft_map_experiments.cpp $(OBJS_DEBUG) $(LIBS)

# debug: $(TILE_TARGET) $(EMPTY_MAP_TARGET) $(STARCRAFT_MAP_TARGET)
debug: $(TEST_TARGET)

clean:
	rm -f $(OBJS_DEBUG) $(OBJS_RELEASE) 
# $(TILE_TARGET) $(EMPTY_MAP_TARGET) $(STARCRAFT_MAP_TARGET)