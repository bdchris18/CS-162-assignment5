linked_list_run:
	g++ test_linked_list.cpp linked_list.cpp node.cpp -o linked_list_run

CC=g++
EXE_FILE=linked_list_run
all: $(EXE_FILE)
$(EXE_FILE): test_linked_list.cpp linked_list.o node.o
	$(CC) test_linked_list.cpp linked_list.o node.o -o $(EXE_FILE)
linked_list.o: linked_list.cpp linked_list.h
	$(CC) -c linked_list.cpp
node.o: node.cpp node.h
	$(CC) -c node.cpp

clean:
	rm -f *.o $(EXE_FILE)