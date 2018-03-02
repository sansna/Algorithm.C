TARGETS = sort_bubble.out\
		  sort_quick.out\
		  sort_heap.out\
		  sort_insert.out\
		  sort_merge.out\
		  sort_radix.out\
		  sort_radix_arr.out
all: $(TARGETS)
CFLAGS = -g -O2
clean:
	rm -f *.out
$(TARGETS):
	$(CC) $(CFLAGS) $*.c -o $@
