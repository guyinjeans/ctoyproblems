SOURCE_DIR ?= ./
BUILD_DIR ?= ../build
TARGET_DIR ?= ../bin
TARGET ?= gen 
CFLAGS ?= -Wall

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(TARGET_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ 
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P ?= mkdir -p
