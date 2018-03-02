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
