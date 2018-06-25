TARGETS=$(patsubst %.c, %.out, $(wildcard *.c))
CFLAGS=-O2 -g -Wno-unused-result
.c.out:
	@$(CC) $(CFLAGS) $< -o $@

all: $(TARGETS)

clean:
	@rm *.out

test: all
	$(foreach f, $(TARGETS), \time ./$(f);)
	$(foreach f, $(TARGETS), perf stat -e branches,branch-misses,bus-cycles,cache-misses,cache-references,cycles,instructions ./$(f);)
