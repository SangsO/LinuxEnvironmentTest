OBJS = main.o print.o input.o
TARGET = test
cc = gcc
CFLAGS = -g

$(TARGET) : $(OBJS)
	$(cc) -o $(TARGET) $(OBJS) $(CFLAGS)
main.o : main.c
	gcc -c main.c $(CFLAGS)
print.o : print.c
	gcc -c print.c $(CFLAGS)
input.o : input.c
	gcc  -c $(CFLAGS) input.c
clean :
	rm -f *.o test $
