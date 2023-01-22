CC=g++
CFLAGS=-c -Wall
SOURSE=main.cpp
OBJECTS=$(SOURSE:.cpp=.o)
EXECUTABLE=test


all:	$(SOURSE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.o $(EXECUTABLE).exe