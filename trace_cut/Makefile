CC = g++
CFLAGS = -O3 -g
LIBS = -lz -pthread

TARGET = main

all: $(TARGET)

$(TARGET): main.cc
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
