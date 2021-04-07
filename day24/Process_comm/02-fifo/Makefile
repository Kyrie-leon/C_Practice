.PHONY:all
all:server client homework
homework:homework.c
	gcc -o $@ $^
client:client.c
	gcc -o $@ $^
server:server.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm client server fifo homework
