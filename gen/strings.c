#include "strings.h"

char* MAKESTR =    "SOURCE_DIR ?= ./\n"
                   "BUILD_DIR ?= ../build\n"
                   "TARGET_DIR ?= ../bin\n"
                   "TARGET ?= gen\n"
                   "CFLAGS ?= -Wall\n"
                   "\n"
                   "SRCS := $(shell find . -name \"*.c\")\n"
                   "OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)\n"
                   "\n"
                   "$(TARGET_DIR)/$(TARGET): $(OBJS)\n"
                   "  $(CC) $(OBJS) -o $@\n"
                   "$(BUILD_DIR)/%.c.o: %.c\n"
                   "  $(MKDIR_P) $(BUILD_DIR)\n"
                   "  $(CC) $(CFLAGS) -c $< -o $@\n"
                   "\n"
                   ".PHONY: clean\n"
                   "\n"
                   "clean:\n"
                   "  $(RM) -r $(BUILD_DIR)\n"
                   "\n"
                   "MKDIR_P ?= mkdir -p\n";

char* MAINCSTR =   "int main(int argc, char* argv[]) {\n"
                   "  return 0;\n"
                   "}\n";

char* READMESTR =  "###What am I?\n";
