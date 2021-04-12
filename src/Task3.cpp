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
	for (int i = 2; nodeptr; nodeptr = nodeptr->next, i++) {
		if (i % 5 == 0 && nodeptr->next) {
			LList* removed = nodeptr->next;
			nodeptr->next = nodeptr->next->next;
			delete removed;
			i++;
		}
	}
}