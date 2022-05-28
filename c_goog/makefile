.PHONY:clean
all: mxwgoog/main.o mxwgoog/test.o 
	gcc -I./ mxwgoog/main.o mxwgoog/test.o -o ./mxwgoog/xianshi.out
mxwgoog/main.o: mxwgoog/main.c mxwgoog/test.h
	gcc -I./ -c mxwgoog/main.c -o mxwgoog/main.o
mxwgoog/test.o: mxwgoog/test.c mxwgoog/test.h mxwgoog/linklist.h
	gcc -I./ -c mxwgoog/test.c -o mxwgoog/test.o
clean:
	rm -rf ./mxwgoog/xianshi.out mxwgoog/main.o mxwgoog/test.o
