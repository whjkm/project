#include <stdio.h>
#include <string.h>
int main()
{
    int n,l,i;
    char s[102];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        l=strlen(s);
        if(l==1)
          {printf("%d\n",l);}
        for(i=0;i<l/2;i++)
        {
            if(s[i]==s[l/2-i])
               {
                   printf("%d\n",l/4);
                   break;
               }
        }
    }
    return 0;
}



#include<stdio.h>
#include<string.h>
main()
{
	int z,x,q,i;
	char a[101],t[51];
	scanf("%d",&z);
	getchar();
	while(z--)
	{
		gets(a);
		do
		{
			x=strlen(a);
			if(x%2) break;
			for(i=0;i<x/2;i++)
				t[i]=a[x-1-i];
			t[i]='\0';
			a[x/2]='\0';
			q=strcmp(a,t);
		}while(q==0);
		printf("%d\n",x);
	}
}
