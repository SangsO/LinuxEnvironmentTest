test : server_main.o calculate.o error_handling.o
	gcc -g -o test server_main.c -lservernew -L./ -I./ -lpthread

server_main.o : server_main.c
	gcc -c server_main.c -lpthread
calculate.o : calculate.c
	gcc -c calculate.c
error_handling.o : error_handling.c
	gcc -c error_handling.c
clean :
	rm -f *.o test
