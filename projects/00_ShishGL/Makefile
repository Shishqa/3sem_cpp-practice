#==============================================================================#

CXX       := g++
CXXFLAGS  := -std=c++20 -pedantic-errors -Wall -Wextra -Werror -O3 -fPIC \
		   	 -Wno-unused-parameter -Wno-unused-variable
LDFLAGS   := -L/usr/lib -lstdc++ -lm -lGL -lglut -lGLU -lGLEW

#==============================================================================#

BUILD_DIR := ./build
OBJ_DIR   := $(BUILD)/objects

LIB_DIR   := $(BUILD)/lib
LIBRARY   := ShishGL

TEST_DIR  := $(BUILD)/test

#==============================================================================#

INCLUDE   := -Iinclude/
SRC       :=
OBJECTS   :=

#==============================================================================#

.PHONY: all build lib test clean debug release

all: debug

#------------------------------------------------------------------------------#

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(TEST_DIR)

#------------------------------------------------------------------------------#

release: lib

#-----

debug: CXXFLAGS += -DLOG -DDEBUG -Wshadow -Wformat=2 -Wfloat-equal  \
	 			   -Wconversion -Wlogical-op -Wshift-overflow=2     \
	   			   -Wduplicated-cond -Wcast-qual -Wcast-align       \
				   -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC       \
				   -D_FORTIFY_SOURCE=2 -fsanitize=address 		    \
			       -fsanitize=undefined -fno-sanitize-recover 	    \
				   -fstack-protector -Wno-format-nonliteral
debug: lib

#------------------------------------------------------------------------------#

lib: SRC     += $(wildcard src/ShishGL/**/*.cpp)
lib: OBJECTS += $(SRC:%.cpp=$(OBJ_DIR)/%.o)
lib: $(OBJECTS)
	@mkdir -p $(@D)
	ar ru $(LIB_DIR)/$(LIBRARY) $^

#------------------------------------------------------------------------------#

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

#------------------------------------------------------------------------------#

#clean:
#	-@rm -rvf $(OBJ_DIR)/*
#	-@rm -rvf $(LIB_DIR)/*
#	-@rm -rvf $()

#==============================================================================#
