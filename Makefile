CC = g++
CFLAGS = -Wall -g -c
LFLAGS =
SRC = main.cpp Cat.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = Reader

all: $(TARGET) $(SRC)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *~ *.o $(TARGET)
