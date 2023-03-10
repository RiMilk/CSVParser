CC=clang++
CFLAGS=-c
SOURSE=main.cpp parser.cpp
OBJECTS=$(SOURSE:.cpp=.o)
EXECUTABLE=csvreader


all:	$(SOURSE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)