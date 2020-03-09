FULL NAME: Rabia Qureshi
STUDENT ID: 1046427
ASSIGNMENT 3

to compile program and link object files:
TYPE make
to run program:
TYPE ./a3

Q2.4: analyzing performance of brute-force and Horspool algorithms:
                -------------------------------------------------------------------------------------------------
                |           BRUTE-FORCE         |           HORSPOOL            |       RELATION (H:BF)         |
-----------------------------------------------------------------------------------------------------------------
#   Pattern     |   Num Shifts  |   Runtime (s) |   Num Shifts  |   Runtime (s) |   Num Shifts  |   Runtime (s) |
-----------------------------------------------------------------------------------------------------------------
1.  to          |   3285197     |   0.026891    |   1709688     |   0.032949    |   0.520421    |   1.225279    |
2.  hey         |   3300017     |   0.024705    |   1173523     |   0.024736    |   0.355611    |   1.001255    |
3.  code        |   3300439     |   0.023296    |   874221      |   0.022524    |   0.264880    |   0.966861    |
4.  maybe       |   3300428     |   0.024102    |   693517      |   0.020626    |   0.210129    |   0.855779    |
5.  barber      |   3300445     |   0.024141    |   611321      |   0.009274    |   0.185224    |   0.384159    |
6.  account     |   3300405     |   0.026391    |   532162      |   0.016129    |   0.161241    |   0.611155    |
7.  academic    |   3298671     |   0.025194    |   494438      |   0.016880    |   0.149890    |   0.670001    |
8.  agreement   |   3300403     |   0.026238    |   438403      |   0.013060    |   0.132833    |   0.497751    |
9.  activities  |   3299759     |   0.026297    |   410023      |   0.016069    |   0.124258    |   0.611058    |
10. application |   3298857     |   0.026308    |   391026      |   0.014616    |   0.118533    |   0.555572    |
-----------------------------------------------------------------------------------------------------------------
                                                                        Total:  |   0.222302‬    |   0.737887    |
                                                                                ---------------------------------
Summary:
Given the following results, it is safe to conclude that the Horspool algorithm was a more efficient algorithm
for string search. The averge Horspool:Brute-Force performance ratio for the number of shifts is much less than 1, 
indicating that the Horspool algorithm had a more efficient method for shifting the pattern to be searched 
for in the file. The average Horspool:Brute-Force performance ratio for the program runtime is also less than 1,
suggesting that the Horspool algorithm generally ran faster than the Brute-force one.