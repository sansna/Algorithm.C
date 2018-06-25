# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.
TARGETS = euc-mod.out\
		  fibo.out\
		  random_gen.out\
		  median.out
TARGETS_WITH_LIBS = prime.out

CPPFLAGS = -D__NO_PRINT
CFLAGS = -g -O2 -Wno-unused-result
LIBS = -lm

TIME ?= /usr/bin/time
export LIBS TIME CFLAGS CPPFLAGS

all: $(TARGETS) $(TARGETS_WITH_LIBS) rand_sets
	@$(MAKE) -C sort
	@$(MAKE) -C search

clean:
	@rm -f *.out *.h
	@$(MAKE) -C sort clean
	@$(MAKE) -C search clean

$(TARGETS):%.out:%.c
	@$(CC) $(CFLAGS) $*.c -o $*.out

$(TARGETS_WITH_LIBS):%.out:%.c
	@$(CC) $(CFLAGS) $*.c -o $*.out $(LIBS)

rand_sets: random_gen.out
	@./random_gen.out

median.out: random_set1.h

random_set1.h random_set2.h: rand_sets

.PHONY:clean all
