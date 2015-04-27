#include <stdio.h>
#include <string.h>

#define MAXC 150//assume chars set is not bigger than 150

typedef struct count
{
	int counta;
	int countb;
}COUNTER;

int cmp(char *stra, char *strb)
{	
	if(stra==NULL &&strb == NULL)
		return 1;
	int lena,lenb,i;
	lena = strlen(stra);
	lenb = strlen(strb);
	if(lena != lenb)
		return 0;
	COUNTER counters[MAXC];
	memset(counters,0,sizeof(struct count)*150);
	
	while(*stra!='\0')
	{
		counters[*stra++ - '0'].counta++;
		counters[*strb++ - '0'].countb++;
	}
	printf("here%d\n",counters[149].counta);

	for(i=0;i<150;i++)
	{
		if(counters[i].counta != counters[i].countb)
			return 0;
	}

	return 1;
}

int cmp2(char *stra, char *strb)//more better
{
	if(stra==NULL &&strb == NULL)
		return 1;
	int lena,lenb,i;
	lena = strlen(stra);
	lenb = strlen(strb);
	if(lena != lenb)
		return 0;

	int count[MAXC];
	memset(count,0,sizeof(int)*MAXC);
	while(*stra != '\0')
	{
		count[*stra++ - '0']++;
	}
	while(*strb!='\0')
	{
		if(--count[*strb++ - '0'] < 0)//<0! for those appears more than once
			return 0;
	}

	return 1;
}


int main()
{
	char a[]="llovve";
	char b[]="evollv";
	if(cmp(a,b))
		printf("true\n");
	else
		printf("false\n");

	if(cmp2(a,b))
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
