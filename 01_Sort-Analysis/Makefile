CC := g++
# CC := clang

SRC := src
BUILD := build
TARGET := bin/app # specify this name 

SRCEXT := cpp
SOURCES := $(shell find $(SRC) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRC)/%,$(BUILD)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -g -std=c++17 -O3 -Werror -Wall -Wextra -fPIE -pie

LIB :=
INC := -I include

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	@printf "  >>>>>>>>>> Linking <<<<<<<<<<  \n";
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILD)/%.o: $(SRC)/%.$(SRCEXT)
	@printf "  >>>>>>>>>> Building <<<<<<<<<<< \n";
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@printf "  >>>>>>>>>> Cleaning <<<<<<<<<< \n";
	$(RM) -r $(BUILD) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
