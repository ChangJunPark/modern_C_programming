app: main.o cdplayer.o
	gcc -o app main.o cdplayer.o

main.o: main.c cdplayer.o
	gcc -c main.c

cdplayer.o: cdplayer.c
	gcc -c cdplayer.c

clean:
	rm app main.o cdplayer.o
