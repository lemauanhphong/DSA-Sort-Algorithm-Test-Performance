rm result.txt
g++ quicksort/quicksort.cpp -o quicksort/quicksort && ./quicksort/quicksort >> result.txt
g++ heapsort/heapsort.cpp -o heapsort/heapsort && ./heapsort/heapsort >> result.txt
g++ mergesort/mergesort.cpp -o mergesort/mergesort && ./mergesort/mergesort >> result.txt
g++ stdsort/stdsort.cpp -o stdsort/stdsort && ./stdsort/stdsort >> result.txt