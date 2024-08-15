#include "NameCard.h"
#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>


int main( ) {
	List list;
	ListInit(&list);

	NameCard *card;
	card = MakeNameCard("pky1", "01011112222");
	LInsert(&list, card);

	card = MakeNameCard("pky2", "01022223333");
	LInsert(&list, card);

	card = MakeNameCard("pky3", "01044445555");
	LInsert(&list, card);

	
	if (LFirst(&list, &card)) {
		if (!NameCompare(card, "pky1")) {
			ShowNameCard(card);
		}
		while (LNext(&list, &card)) {
			if (!NameCompare(card, "pky1")) {
				ShowNameCard(card);
			}
		}
	}

	if (LFirst(&list, &card)) {
		if (!NameCompare(card, "pky2")) {
			ChangePhoneNum(card, "01012345678");
		}
		while (LNext(&list, &card)) {
			if (!NameCompare(card, "pky2")) {
				ChangePhoneNum(card, "01012345678");
			}
		}
	}

	if (LFirst(&list, &card)) {
		if (!NameCompare(card, "pky3")) {
			card = LRemove(&list);
			free(card);
		}
		while (LNext(&list, &card)) {
			if (!NameCompare(card, "pky3")) {
				card = LRemove(&list);
				free(card);
			}
		}
	}


	printf("현재 데이터 수 : %d\n", LCount(&list));
	if (LFirst(&list,&card)) {
		ShowNameCard(card);

		while (LNext(&list, &card)) {
			ShowNameCard(card);
		}
	}


	return 0;
}
