#Christabel Escarez
#CS260 - Spring 2019
#Project #1 Makefile

CC = g++
CPPFLAGS = -Wall -g -std-c++11

main: main.o inputTools.o song.o songList.o artist.o artistList.o linkedList.o

main.o: inputTools.h song.h artist.h recordLabel.h linkedList.h

inputTools.o: inputTools.h

song.o: song.h linkedList.h

songList.o: songList.h linkedList.h

artist.o: artist.h linkedList.h

artistList.o: song.h artist.h artistList.h linkedList.h

linkedList.o: linkedList.h

.PHONY: clean memcheck
clean:
	$(info --------- REMOVING OBJECT FILES AND EXECUTABLES -----------)
	rm *.o main

memcheck:
	valgrind --tool=memcheck --leak-check=full ./main
