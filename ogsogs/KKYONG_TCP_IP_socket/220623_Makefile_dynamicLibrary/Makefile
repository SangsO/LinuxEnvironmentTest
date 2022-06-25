OBJS = main.o print.o input.o
TARGET = test
cc = gcc
CFLAGS = -g
LDFLAGS = -lhgy

$(TARGET) : $(OBJS) # target
	$(cc) -o $@ $^ $(CFLAGS) -L. $(LDFLAGS) # must have 'tap'
.c.o :
	$(cc) -c -o $@ $<
clean : # delete
	rm -f *.o $(TARGET)
