
#include "NameCard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996);

NameCard * MakeNameCard(char *name, char *phone) {

	if (strlen(name) >= NAME_LEN || strlen(phone) >= PHONE_LEN) {
		printf("wrong size\n");
		return NULL;
	}
	NameCard* newcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newcard->name, name);
	strcpy(newcard->phone, phone);

	return newcard;
}

void ShowNameCard(NameCard *card) {
	printf("이름 : %s\n", card->name);
	printf("전화번호 : %s\n", card->phone);
}

int NameCompare(NameCard *card, char *name) {
	return strcmp(card->name, name);
}

void ChangePhoneNum(NameCard *card, char *phone) {
	if (strlen(phone) >= PHONE_LEN) {
		printf("wrong size");
		return;
	}
	strcpy(card->phone, phone);
}