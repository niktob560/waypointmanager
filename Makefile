TARGET=waypointmanager
LIBS=
OPTIMIZE=-Og
LFLAGS=-Wall -Wextra -lm $(LIBS)
CPP=g++
LD=ld
BUILD_DIR=Build
SOURCE_DIR=Src
BIN_DIR=Bin
INCLUDE_DIR=Inc


CPP_INCLUDES = \
-I$(INCLUDE_DIR)

CPP_SOURCES = \
Src/main.cpp

CPP_DEFS =


OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))

TOBJECTS = $(filter-out $(BUILD_DIR)/main.o,$(OBJECTS))



CFLAGS=$(CPP_DEFS) $(CPP_INCLUDES) $(OPTIMIZE) -Wall -Wextra -std=gnu++11 -g


all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJECTS) Makefile
	$(CPP) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $@


$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	$(CPP) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@



directories: $(BUILD_DIR) $(BIN_DIR) $(SOURCE_DIR) $(INCLUDE_DIR)


$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

$(SOURCE_DIR):
	mkdir -p $@

$(INCLUDE_DIR):
	mkdir -p $@

$(TEST_DIR):
	mkdir -p $@


clean:
	rm -rf $(BUILD_DIR)/*
	rm -rf $(TEST_DIR)/*.cpp
	rm -rf $(TEST_DIR)/main
	rm -rf $(BIN_DIR)/*


run: main
	./run
