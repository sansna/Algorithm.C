SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.out, $(wildcard *.c))

TIME ?= /usr/bin/time

all: $(TARGETS)

test: all FORCE
	@$(foreach f, $(TARGETS), echo -e "Running \033[0;31mTIME ./$(f)\033[0m:";$(TIME) ./$(f);echo "";)

CPPFLAGS ?= -D__NO_PRINT
CFLAGS ?= -g -O2 -Wno-unused-result

clean:
	@rm -f *.out

$(TARGETS):%.out:%.c ../random_set1.h ../random_set2.h
	@$(CC) $(CPPFLAGS) $(CFLAGS) $*.c -o $@

../random_set1.h ../random_set2.h:
	$(MAKE) -C ..

.PHONY: FORCE
