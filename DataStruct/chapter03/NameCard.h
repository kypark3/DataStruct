#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard * MakeNameCard(char *name, char *phone);
void ShowNameCard(NameCard *card);
int NameCompare(NameCard *card, char *name);
void ChangePhoneNum(NameCard *card, char *phone);

#endif // !__NAMECARD_H__
