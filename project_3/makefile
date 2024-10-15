CC = g++

project02: listmain.o linked_list.o
	$(CC) listmain.o linked_list.o -o project02 -g
listmain.o: listmain.cpp linked_list.h
	$(CC) listmain.cpp -c -g
linked_list.o: linked_list.cpp linked_list.h
	$(CC) linked_list.cpp -c -g
	
clean:
	rm project03
