#On my honor, I pledge that I have neither received nor provided improper assistance in the
#completion of this programming assignment. Signed: 정예찬

#Lab 6 : Makefile and build qsort.exe

qsort : quicksort.o print_list.o
	g++ quicksort.o print_list.o -o qsort

quicksort.o : quicksort.cpp
	g++ -c quicksort.cpp
print_list.o : print_list.cpp
	g++ -c print_list.cpp
clean :
	rm -f *.o qsort.exe qsort
