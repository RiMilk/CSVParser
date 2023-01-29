CC=g++
CFLAGS=-c -Wall
SOURSE=main.cpp main.h parser.cpp parser.h
OBJECTS=$(SOURSE:.cpp=.o)
EXECUTABLE=csvreader


all:	$(SOURSE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.o $(EXECUTABLE).exe