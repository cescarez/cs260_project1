#Christabel Escarez
#CS260 - Spring 2019
#Project #1 Makefile

CC = g++
CPPFLAGS = -Wall -g -std-c++11

main: main.o inputTools.o song.o songList.o artist.o artistList.o

main.o: inputTools.h song.h artist.h recordLabel.h

inputTools.o: inputTools.h

song.o: song.h

songList.o: songList.h

artist.o: artist.h songList.h

artistList.o: artist.h artistList.h 


.PHONY: clean memcheck
clean:
	$(info --------- REMOVING OBJECT FILES AND EXECUTABLES -----------)
	rm *.o main

memcheck:
	valgrind --tool=memcheck --leak-check=full ./main
