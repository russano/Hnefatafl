CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= src/Board.cpp src/main.cpp src/Viking.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Hnefatafl

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
