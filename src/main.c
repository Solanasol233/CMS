#include <main.h>

Contact contacts[MAXBUFFSIZE];
INFO info;

void displayContacts()
{
	printf("|ID\t|first name\t|last name\t|email\t\t|phone number|\n");
	printf("|-------|---------------|---------------|---------------|------------|\n");
	for (int i = 0; i < info.totalContacts; i++)
	{
		printf("|%d\t|%s\t|%s\t|%s\t|%s\t|\n", i, contacts[i].fn, contacts[i].ln, contacts[i].email, contacts[i].phonenum);
		printf("|-------|---------------|---------------|---------------|------------|\n");
	}
}
void addContact(int argc, char* argv[])
{
	int index = info.totalContacts;
	contacts[index].ID = index +1;

	for (int i = 2; i < argc; i++)	/*i start at 2 because argv[2] is the first argument after -ac*/
	{
		if (strcmp(argv[i], "-fn") == 0 || strcmp(argv[i], "-firstname") == 0)
		{
			strcpy(contacts[index].fn, argv[i + 1]);
			printf("[%sDEBUG%s] fn: %s\n", KGRN, KNRM, contacts[index].fn);
		} else
		if (strcmp(argv[i], "-ln") == 0 || strcmp(argv[i], "-lastname") == 0)
		{
			strcpy(contacts[index].ln, argv[i + 1]);
			printf("[%sDEBUG%s] ln: %s\n", KGRN, KNRM, contacts[index].ln);
		} else
		if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-email") == 0)
		{
			strcpy(contacts[index].email, argv[i + 1]);
			printf("[%sDEBUG%s] email: %s\n", KGRN, KNRM, contacts[index].email);
		} else
		if (strcmp(argv[i], "-pn") == 0 || strcmp(argv[i], "-phonenumber") == 0)
		{
			strcpy(contacts[index].phonenum, argv[i + 1]);
			printf("[%sDEBUG%s] phone: %s\n", KGRN, KNRM, contacts[index].phonenum);
		}
	}
	info.totalContacts++;
}

int main(int argc, char *argv[])
{
	memset(contacts, 0, sizeof(contacts));
	info.totalContacts = 0;
	printf("[%sDEBUG%s] argc: %d\n", KGRN, KNRM, argc);

	for(int i = 0; i < argc; i++) printf("[%sDEBUG%s] %s\n", KGRN, KNRM, argv[i]);

	if (argc == 1) displayContacts();

	if (strcmp(argv[1], "-ac") == 0) addContact(argc, argv);
	
	return 0;
}