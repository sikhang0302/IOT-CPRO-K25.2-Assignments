# Phony targets (make will not check these as actual file names)
.PHONY = all clean

# Directory definitions
CUR_DIR := .
DHT22_DIR := $(CUR_DIR)/DHT22
TEST_DIR := $(CUR_DIR)/Test
APP_DIR := $(CUR_DIR)/App

# Compiler and flags
# Using gcc compiler
CC = gcc
# Compiler flags: warnings, include path
INCLUDES = -I$(DHT22_DIR) -I$(TEST_DIR)
CFLAGS  = -Wall -Wextra $(INCLUDES)
 # Linker flags: math library
LDFLAGS = -lm

# Target executable and source files
# Output executable path
MAIN_TARGET = $(CUR_DIR)/app
# Source files
MAIN_SOURCES = \
	$(APP_DIR)/main.c \
	$(DHT22_DIR)/DHT22.c \
	$(TEST_DIR)/Test_Service.c

# Default - build target
all: $(MAIN_TARGET)

# Rule to build main target
$(MAIN_TARGET): $(MAIN_SOURCES)
# Compile all sources into executable 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean targets - removes generated files
clean:
# Remove installed executable and generated data files
# find . -maxdepth 1 -type f means find all regular files (-type f) in the current directory (excluding subfolders)
# ! -name "Makefile" means exclude Makefile
# ! -name ".gitignore" means exclude .gitignore (if any)
# -exec rm -f {} + means remove all found files
	@find $(CUR_DIR) -maxdepth 1 -type f ! -name "Makefile" ! -name ".gitignore" -exec rm -f {} +	