SOURCE = calculate.c error_handling.c

OBJT = calculate.o error_handling.o server_main.o
OBJT_S = calculate.o error_handling.o
server : $(OBJT)
	gcc -g -o server $(OBJT)
	
	ar rscv libogssta.a $(OBJT_S)
	gcc -g -o server_sta server_main.o -L./ -I./ -logssta

server_main.o : server_main.c
	gcc -g -c server_main.c
calculate.o : calculate.c
	gcc -g -c calculate.c
error_handling.o : error_handling.c
	gcc -g -c error_handling.c




#dynamic : 
#	$(CC) -o $(TARGET)_ogsdyn $(MAIN) -l$(TARGET) -L./ -I./

#static :
#	$(CC) -o $(TARGET)_ogssta $(MAIN) -l$(TARGET) -L./ -I.

clean : 
	rm -f *.o server server_sta lib* 

