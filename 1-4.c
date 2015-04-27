#include <stdio.h>
#include <string.h>


int transact(char *str)//str must have enough space for new chars
{
	if(str == NULL)
		return 0;
	int space_count=0;
	int old_len,new_len;
	int i;
	char *old=str;
	char *new;
	while(*old != '\0')
	{
		if(*old == ' ')	
			++space_count;
		old++;
	}

	old_len = strlen(str); 
	new_len = old_len + space_count*2;
	new = str + new_len;

	for(i=old_len;i>=0;i--)
	{
		if(*old == ' ')
		{
			*new--='0';
			*new--='2';
			*new-- ='%';
			old--;
		}
		else
			*new-- = *old--;
	}

	return 1;
}

int main()
{
	char str[]="a b";
	transact(str);
	printf("result:%s\n",str);

	return 0;
}
