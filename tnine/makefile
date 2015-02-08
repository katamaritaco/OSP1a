CC = gcc
CFLAGS = -g -Wall
TARGET = tnine.c p1a2.h printwrapper.o
TARGET_OBJECT = tnine

all: $(TARGET_OBJECT)

$(TARGET_OBJECT): $(TARGET)
	$(CC) $(CFLAGS) -o $(TARGET_OBJECT) $(TARGET)

clean:
	rm -f $(TARGET_OBJECT)

