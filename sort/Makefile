SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.out, $(wildcard *.c))
all: $(TARGETS)
CFLAGS = -g -O2 -Wno-unused-result
clean:
	@rm -f *.out
$(TARGETS):%.out:%.c
	@$(CC) $(CFLAGS) $*.c -o $@
