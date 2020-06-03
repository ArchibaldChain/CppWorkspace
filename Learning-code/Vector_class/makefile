CC = g++
TARGET = vect_test
OBJ = vect.o randWalk.o
INCLUDE = vect.h

CFLAGS = -c -wall
# -c   says to generate the object file.
# -g  adds debugging information to the executable file
# -Wall turns on most, but not all, compiler warnings

# ^means everything behind :
# < menas the first terms behind :
$(TARGET):$(OBJ)
	$(CC) $^ -o $@

%.o:%.cpp %(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)