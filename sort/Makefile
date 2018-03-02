SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.out, $(wildcard *.c))
all: $(TARGETS)
CFLAGS = -g -O2
clean:
	@rm -f *.out
$(TARGETS):%.out:%.c
	@$(CC) $(CFLAGS) $*.c -o $@
