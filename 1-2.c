#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
	if(str == NULL) return;
	int len,i,j;
	char tmp;
	len = strlen(str);
	if(len == 1) return;
	for(i=0,j=len-1;i<len/2;i++,j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

int main()
{
	char str[]="revol";//if char *str="";str cannot be changed!!!!
	reverse(str);
	printf("result:%s\n",str);

	return 0;
}
