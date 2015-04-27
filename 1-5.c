#include <stdio.h>
#include <string.h>

typedef struct count
{
	char c;
	int n;
}COUNTER;

int compress(const char *str)
{
	int len;
	int changed=0;
	int cur,next;
	int count=1;
	COUNTER counters[1000];
	int index=0;
	int i;
	len=strlen(str);
	if(str==NULL)
		return 0;
	if(len ==1)
	{
		printf("str\n");
		return 0;
	}
	cur=0;next=1;
	while(str[next] != '\0')
	{
		if(str[cur] == str[next])
		{
			count++;
			changed=1;
		}
		else
		{
			counters[index].c=str[cur];
			counters[index++].n=count;
			count=1;
		}
		cur++;next++;
	}
	counters[index].c=str[cur];
	counters[index++].n=count;//the last one
	if(changed)
	{
		for(i=0;i<index;i++)	
			printf("%c%d",counters[i].c,counters[i].n);
		printf("\n");
	}
	else
		printf("%s\n",str);
	
	return 0;
}

//test
int main()
{
	char str1[]="abcd";
	char str2[]="aaaabbcaaaaaad";

	compress(str1);
	compress(str2);

	return 0;
}
