# Phony targets (make will not check these as actual file names)
.PHONY = all clean

# Directory definitions
CUR_DIR := .
IMAGE_DIR := $(CUR_DIR)/Image
APP_DIR := $(CUR_DIR)/App

# Compiler and flags
# Using gcc compiler
CC = g++
# Compiler flags: warnings, include path
CFLAGS  = -Wall -Wextra -I$(IMAGE_DIR)

# Target executable and source files
# Output executable path
MAIN_TARGET = $(CUR_DIR)/image_processing
# Source files
MAIN_SOURCES = \
	$(APP_DIR)/main.cpp \
	$(IMAGE_DIR)/Image.cpp

# Default - build target
all: $(MAIN_TARGET)

# Rule to build main target
$(MAIN_TARGET): $(MAIN_SOURCES)
# Compile all sources into executable 
	$(CC) $(CFLAGS) $^ -o $@

# Clean targets - removes generated files
clean:
# Remove installed executable
	rm -rf $(CUR_DIR)/image_processing