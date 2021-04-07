.PHONY:all
all:mypipe forkpipe forkpipe1 homework
homework:homework.c
	gcc -o $@ $^
forkpipe1:forkpipe1.c
	gcc -o $@ $^
forkpipe:forkpipe.c
	gcc -o $@ $^
mypipe:mypipe.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm mypipe forkpipe forkpipe1 homework
