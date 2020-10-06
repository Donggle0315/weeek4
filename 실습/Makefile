CC=g++
target=result
objects=main.o

$(target):$(objects)
	$(CC) -o $(target) $(objects)

$(objects):LinkedList.h Stack.h

.PHONY:clean
clean:
	rm $(target) $(objects)
