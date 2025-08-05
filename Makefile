# ---- configuration ---------------------------------------------------------
BIN       := freq-counter
PREFIX    ?= /usr/local

SRC_DIR   := src
INC_DIR   := include
TEST_DIR  := tests

SRCS      := $(wildcard $(SRC_DIR)/*.c)
OBJS      := $(SRCS:.c=.o)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
CC        ?= cc
CFLAGS    := -std=c11 -Wall -Wextra -I$(INC_DIR) -O2
LDLIBS    :=

# ---- build targets ---------------------------------------------------------
$(BIN): $(OBJS)
	$(CC) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: test test-bin install uninstall clean

test-bin: $(TEST_OBJS) $(OBJS)
	$(CC) $(TEST_OBJS) $(filter-out $(SRC_DIR)/main.o,$(OBJS)) -o $(TEST_DIR)/test_runner

test: test-bin
	$(TEST_DIR)/run.sh

install: $(BIN)
	install -Dm755 $(BIN) $(DESTDIR)$(PREFIX)/bin/$(BIN)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(BIN) $(TEST_DIR)/test_runner
