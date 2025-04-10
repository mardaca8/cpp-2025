CC = g++
CFLAGS = -Wall 

SRCS = main.cpp Vehicle.cpp
TARGET = vehicle

all: build

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp Vehicle.cpp

clean:
	rm -f $(OBJS) $(TARGET) vehicle_test_log.txt

rebuild: clean build
