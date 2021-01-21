Name: Brandon Christensen
ONID: 933819447
Section: CS 162 Section 20
Assignment 5 due 6/7/2020

Description:
This program deals with the manipulation of linked lists similar to that of a vector.
In this assignment the functions we are creating are a print function, delete function,
push front function that will add an item to the beginning of the list, a push back
function that will add an item to the end of the list, an insert function that puts an
item in at a desired location, a sort function that will sort by ascending using merge
sort, a sort by descending that will also use merge sort, and a count primes function
that will return the amount of primes in the list.

compile with Makefile
1) run make
2) run with a.out

Limitations:
none unless the user decides to change the code up, since there are no user inputs
there shoudl be no problems when the program is run.

Complexity analysis:
sort_ascending: I used merge sort which is O(nlogn) being the faster of the sorting
algorithms it makes for good runtime
sort_descending: Again used merge sort
count_prime: This one used O(n) because you run through two different for loops
meaning it is a bit slower