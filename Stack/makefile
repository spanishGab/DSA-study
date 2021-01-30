stack_test: stack.o stack_test.o
	gcc -o stack_test stack.o stack_test.o

stack.o: stack.c stack.h
	gcc -c stack.c

stack_test.o: stack.c stack.h
	gcc -c stack_test.c

clean: 
	rm *.o stack_test