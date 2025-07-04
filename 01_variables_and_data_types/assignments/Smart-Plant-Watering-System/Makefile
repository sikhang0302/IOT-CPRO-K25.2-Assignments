# Phony targets (make will not check these as actual file names)
.PHONY = all clean install quick

# Directory definitions
CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src

# Compiler and flags
# Using gcc compiler
CC = gcc
# Compiler flags: warnings, include path, pthread
CFLAGS  = -Wall -Wextra -I$(INC_DIR) -pthread
 # Linker flags: pthread library
LDFLAGS = -pthread

# Target executable and source files
# Output executable path
MAIN_TARGET = $(BIN_DIR)/spws
PANEL_TARGET = $(BIN_DIR)/panel
# Source files for server (main)
MAIN_SOURCES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/actuators.c \
	$(SRC_DIR)/display_server.c \
	$(SRC_DIR)/sensors.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/watering_logic.c
# Source file for client
PANEL_SOURCES = $(SRC_DIR)/panel_client.c

# Default - build both targets
all: $(MAIN_TARGET) $(PANEL_TARGET)

# Rule to build main target
$(MAIN_TARGET): $(MAIN_SOURCES)
# Create bin directory if it doesn't exist
	@mkdir -p $(BIN_DIR)
# Compile all sources into executable 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
# Rule to build client
$(PANEL_TARGET): $(PANEL_SOURCES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Copy binaries to project root
install: $(MAIN_TARGET) $(PANEL_TARGET)
	cp $(MAIN_TARGET) $(CUR_DIR)/spws
	cp $(PANEL_TARGET)  $(CUR_DIR)/panel

# Clean targets - removes generated files
clean:
# Remove bin directory and installed executable
	rm -rf $(BIN_DIR) $(CUR_DIR)/spws $(CUR_DIR)/panel