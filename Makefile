# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.
TARGETS = euc-mod.out\
		  fibo.out\
		  random_gen.out
TARGETS_WITH_LIBS = prime.out
CFLAGS = -g -O2
LIBS = -lm
all:$(TARGETS) $(TARGETS_WITH_LIBS)
clean:
	rm -f *.out
$(TARGETS):
	$(CC) $(CFLAGS) $*.c -o $*.out
$(TARGETS_WITH_LIBS):
	$(CC) $(CFLAGS) $(LIBS) $*.c -o $*.out
