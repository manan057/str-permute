all: task1 task2

task1: task1.c
	gcc -o task1 task1.c

task2: task2.c
	gcc -o task2 task2.c
