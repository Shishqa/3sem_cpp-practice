CXX      := g++
CXXFLAGS := -std=c++20 -pedantic-errors -Wall -Wextra -Werror -O3 -fPIC
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lGL -lglut -lGLU -lGLEW
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/

TARGET   := libshishgl.a

INCLUDE  := -Iinclude/
SRC      :=                           	 \
   	$(wildcard src/*.cpp) 				 \
   	$(wildcard src/engines/*.cpp)        \
   	$(wildcard src/engines/GLUT/*.cpp)   \
   	$(wildcard test/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)


.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)


debug: CXXFLAGS += -DLOG -DDEBUG -Wshadow -Wformat=2 -Wfloat-equal  \
	 			   -Wconversion -Wlogical-op -Wshift-overflow=2     \
	   			  -Wduplicated-cond -Wcast-qual -Wcast-align       \
				  -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC       \
				  -D_FORTIFY_SOURCE=2 -fsanitize=address 		   \
			      -fsanitize=undefined -fno-sanitize-recover 	   \
				  -fstack-protector -Wno-format-nonliteral
debug: all

release: CXXFLAGS += -Wno-unused-parameters
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
