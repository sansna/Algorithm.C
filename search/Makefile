SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.out, $(SRCS))
TIME ?= /usr/bin/time
CFLAGS ?= -O2 -g -Wno-unused-result

all: $(TARGETS)

test: all FORCE
	@$(foreach f, $(TARGETS), echo "Running \033[0;31mTIME ./$(f)\033[0m:";$(TIME) ./$(f);echo "";)

$(TARGETS):%.out:%.c ../random_set1.h
	@$(CC) $(CPPFLAGS) $(CFLAGS) $*.c -o $@

../random_set1.h:
	@$(MAKE) -C ..

clean: 
	@rm -f *.out
.PHONY: FORCE
