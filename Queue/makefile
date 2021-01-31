queue_test: queue.o queue_test.o
	gcc -o queue_test queue.o queue_test.o

queue.o: queue.c queue.h
	gcc -c queue.c

queue_test.o: queue_test.c queue.c queue.h
	gcc -c queue_test.c

clean:
	rm *.o queue_test