#include <stdio.h>
#include <string.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}address;
static address list[100];
int input()
{
	FILE *fp = fopen("phonebook.dat","rb");
	if (fp==NULL)
		return 0;
	fread(list,sizeof(address),1,fp);
	fclose(fp);
	return 1;
}
void quicksort(int first, int last)
{
	int privot=last-1;
	address tmp;
	int i;
	if (last<=first)
		return;
	for (i=0;i<(last-first);i++)
		if (strcmp(list[i].name,list[last].name)>0)
		{
			tmp=list[i];
			list[i]=list[privot];
			list[privot--]=tmp;
		}
	tmp=list[last];
	list[last]=list[privot];
	list[privot]=tmp;
	quicksort(first,privot-1);
	quicksort(privot+1,last);
}
void out()
{
	FILE *fp=fopen("phonebook_sorted.dat","a+b");
	fwrite(list,sizeof(address),10,fp);
	fclose(fp);
}
int main()
{
	int found;
	char search[31];
	if (input()==0)
	{
		printf("Cannot open the address folder.\n");
		return 1;
	}
	quicksort(0,9);
	for (int i=0; i<10; i++)
	{
		printf("%d \n\n",i);
		printf("%s\n",list[i].name);
		printf("%s\n",list[i].tel);
		printf("%s\n",list[i].mail);
	}
	out();
	printf("Sorted!\n");
	return 0;
}
