# Phony targets (make will not check these as actual file names)
.PHONY = all clean install quick

# Directory definitions
CUR_DIR := .
LOGGER_DIR := $(CUR_DIR)/Logger
APP_DIR := $(CUR_DIR)/App

# Compiler and flags
# Using gcc compiler
CC = gcc
# Compiler flags: warnings, include path, pthread
CFLAGS  = -Wall -Wextra -I$(LOGGER_DIR) -pthread
 # Linker flags: pthread library
LDFLAGS = -pthread

# Target executable and source files
# Output executable path
MAIN_TARGET = $(CUR_DIR)/logger
# Source files
MAIN_SOURCES = \
	$(APP_DIR)/main.c \
	$(LOGGER_DIR)/logger.c

# Default - build target
all: $(MAIN_TARGET)

# Rule to build main target
$(MAIN_TARGET): $(MAIN_SOURCES)
# Compile all sources into executable 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean targets - removes generated files
clean:
# Remove bin directory and installed executable
	rm -rf $(CUR_DIR)/logger $(CUR_DIR)/*.txt