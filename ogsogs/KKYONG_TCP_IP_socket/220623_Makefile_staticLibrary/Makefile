OBJS = main.o print.o input.o
TARGET = test
cc = gcc
CFLAGS = -g
LDFLAGS = -lpthread

$(TARGET) : $(OBJS) # target
	$(cc) -o $@ $^ $(CFLAGS) # must have 'tap'
.c.o :
	$(cc) -c -o $@ $<
clean : # delete
	rm -f *.o $(TARGET)
