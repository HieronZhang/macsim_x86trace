CC = g++
CFLAGS = -O3 -g
LIBS = -lz

TARGET = main

all: $(TARGET)

$(TARGET): main.cc
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
