#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
   char s[5002];
   int i,l;
   while(gets(s)!=EOF)
   {
       l=strlen(s);
       for(i=0;i<l;i++)
       {
           if(s[i]=='5')
       }
   }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,j,k,l;
	int a[5010];
	char s[5010];
	while(~scanf("%s",s))
	{
		l=strlen(s);
		i=0;l--;
		while(s[i]=='5')
			i++;
		while(s[l]=='5')
			l--;
		for(j=k=0;i<=l;i++)
		{
			if(s[i]=='5')
			{
				if(s[i-1]=='5')
					continue;
				a[j++]=k;
				k=0;
			}
			else
				k=k*10+s[i]-'0';
		}
		a[j++]=k;
		sort(a,a+j);
		for(i=0;i<j;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}
