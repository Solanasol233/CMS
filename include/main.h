#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFSIZE 1024
#define PHONENUMLEN 11
#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"

typedef struct
{
	int totalContacts;
}INFO;

typedef struct
{
	int ID;
	char fn[MAXBUFFSIZE];
	char ln[MAXBUFFSIZE];
	char email[MAXBUFFSIZE];
	char phonenum[PHONENUMLEN];
}Contact;

void displayContacts();