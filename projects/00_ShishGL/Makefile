CXX      := g++
CXXFLAGS := -std=c++20 -pedantic-errors -Wall -Wextra -Werror -O3
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lsfml-graphics -lsfml-window -lsfml-system
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/
TARGET   := yasa
INCLUDE  := -Iinclude/
SRC      :=                           						\
   	$(wildcard src/*.cpp)									\
   	$(wildcard src/ShishGL/core/*.cpp)      				\
   	$(wildcard src/ShishGL/core/engines/sfml/*.cpp)      	\
   	$(wildcard src/ShishGL/*.cpp)							\
   	$(wildcard src/ShishGL/ui/scrollbar/*.cpp)

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

run: $(APP_DIR)/$(TARGET)
	./$(APP_DIR)/$(TARGET)

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

debug: CXXFLAGS += -DDEBUG -Wshadow -Wformat=2 -Wfloat-equal \
				   -Wconversion -Wlogical-op -Wshift-overflow=2     \
				   -Wduplicated-cond -Wcast-qual -Wcast-align       \
				   -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC       \
				   -D_FORTIFY_SOURCE=2 -fsanitize=address 		    \
				   -fsanitize=undefined -fno-sanitize-recover 	    \
				   -fstack-protector -Wno-format-nonliteral    \
				   -Wno-shadow
debug: all

release: CXXFLAGS += -Wno-unused-parameter
release: all

clean:
	-@rm -rvi $(OBJ_DIR)/*
	-@rm -rvi $(APP_DIR)/*
