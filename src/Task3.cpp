/**
 * There is a List:
 *
 * struct List {
 *     struct List* next;
 *     SomeDataType payload;
 * }
 *
 * Write a function that removes every fifth (5) element from this LList.
 */

#include "LList.hpp"

void removeEveryFifth(LList* nodeptr) {
	for (int i = 1; nodeptr; i++) {
		if (i % 5 == 4) {
			nodeptr->next = nodeptr->next ? nodeptr->next->next : nullptr;
			i++;
		}
        nodeptr = nodeptr->next;
	}
}