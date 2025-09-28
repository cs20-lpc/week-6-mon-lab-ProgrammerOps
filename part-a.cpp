#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/
// idea: we stand at mailbox i, and ask:
// "What's the biggest letter from the NEXT mailboxes?"
// Then we compare that with our current mailbox.
// Base case: when i is at the last mailbox, that's the biggest





template <typename T>    //“This is a recipe that works for ANY type T.”
T findMaxRecTail(const T arr[], const int SIZE, int i) {     //Inside the () are ingredients (parameters): const T arr[] = the row of mailboxes filled with letters (read-only, because of const). const int SIZE = how many mailboxes. int i = the position we’re standing at right now (default was 0 in your prototype).
    
    // If theres are no mailboxes at all, our code doesnt know what to do.
    // We'll assume SIZE >= 1 as used in main.

    // Base case: if we're at the last mailbox, return its letter.
    if (i == SIZE - 1) {  //f i'm standng at the last mailbox (i == SIZE - 1), just grab that letter.
        return arr[i];
    }

    // Recursive case: ask the smaller you to find the max in the rest.
    T maxInRest = findMaxRecTail(arr, SIZE, i + 1);     //We don’t know the biggest yet, so we ask a smaller clone of ourselves to check the rest of the mailboxes starting at i + 1.
    // Compare our current letter with the best from the rest.
    // Return the bigger one.
    return (arr[i] > maxInRest) ? arr[i] : maxInRest;  //We use the ternary operator:(condition) ? A : B means: If condition is true, return A. Otherwise, return B.

}


int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE, 0) << endl
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2, 0) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}