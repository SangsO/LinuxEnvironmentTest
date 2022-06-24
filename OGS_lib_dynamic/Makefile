SOURCE = calculate.c error_handling.c

OBJT_S = calculate.o error_handling.o
server : $(OBJT_S)
	gcc -fPIC -g -c server_main.c $(SOURCE)
	gcc -shared -g -o libogsdyn.so $(OBJT_S)
#	export LD_LIBRARY PATH=.
	gcc -g -o server_dyn server_main.c -logsdyn -L./ -I./
	

#server_main.o : server_main.c
#	gcc -g -c server_main.c
#calculate.o : calculate.c
#	gcc -g -c calculate.c
#error_handling.o : error_handling.c
#	gcc -g -c error_handling.c

#dynamic : 
#	$(CC) -o $(TARGET)_ogsdyn $(MAIN) -l$(TARGET) -L./ -I./

#static :
#	$(CC) -o $(TARGET)_ogssta $(MAIN) -l$(TARGET) -L./ -I.
#path :
#	export LD_LIBRARY_PATH=.
	

clean : 
	rm -f *.o server server_dyn lib* 

