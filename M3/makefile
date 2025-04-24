CC = g++
CFLAGS = -Wall 

SRCS = main.cpp Vehicle.cpp
TARGET1 = vehicle.o
TARGET2 = vehicle.exe

all: build

build: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET1) main.cpp Vehicle.cpp

$(TARGET2): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET2) main.cpp Vehicle.cpp

clean:
	rm -f $(OBJS) $(TARGET1) $(TARGET2) vehicle_test_log.txt

rebuild: clean build
