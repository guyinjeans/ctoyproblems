SOURCE_DIR ?= ./
BUILD_DIR ?= ../build
TARGET_DIR ?= ../bin
TARGET ?= csort
CFLAGS ?= -Wall
CXX ?= gcc

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(TARGET_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ 
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P ?= mkdir -p
