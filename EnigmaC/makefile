all:
	gcc -Wall -c *.c
	gcc -Wall *.o -o enigma

debug:
	gcc -g -Wall -c *.c
	gcc -Wall *.o -o enigma
	gdb enigma

clean:
	rm *.o enigma
