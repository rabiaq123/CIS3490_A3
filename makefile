# FULL NAME: Rabia Qureshi
# STUDENT ID: 1046427
# DATE: Monday March 9, 2020
# ASSIGNMENT 3

CC = gcc
CFLAGS = -Wall -g -std=c99

a3: P11.o P12.o P21.o P22.o P23.o main.o
	$(CC) $(CFLAGS) P11.o P12.o P21.o P22.o P23.o main.o -o $@

P11.o: P11.c
	$(CC) $(CFLAGS) -c $< -o $@

P12.o: P12.c
	$(CC) $(CFLAGS) -c $< -o $@

P21.o: P21.c
	$(CC) $(CFLAGS) -c $< -o $@

P22.o: P22.c
	$(CC) $(CFLAGS) -c $< -o $@

P23.o: P23.c 
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o
