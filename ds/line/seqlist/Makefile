CC =gcc
CFLAGS = -O -g -Wall

test: test.c seqlist.c
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:clean
clean:
	rm -rf test
