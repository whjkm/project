#include <cstdio>
#include <cstring>
using namespace std;
char s[120],c[120];
int cmp(int x,int y)
{
    int len1,len2;
    len1=strlen(s);
    len2=strlen(c);
    if((y<len2)&&(x>=len1))  return 0;
    if(y==len2) return 1;
    if(c[y]=='*')
    {
        while(c[y+1]=='*') y++;
        int temp;
        for(int i=x;i<len1;i++)
        {
            if(s[i]==c[y+1])
            {
                temp=cmp(i+1,y+2);
                if(temp) return 1;
            }
        }
       return 0;
    }
    else
    {
        if(s[x]!=c[y]) return 0;
        else
            return cmp(x+1,y+1);
    }
}
int main()
{
    while(scanf("%s\n%s",s,c)!=EOF)
    {
        //c[0]='*';
        puts(cmp(0,0)?"yes":"no");
    }
}


/*#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

char s[120], t[120];
int la, lb;
int find( int x, int y ){
    if( (y<lb)&&(x>=la) ) return 0;
    if( y == lb ) return 1;
    if( t[y] == '*' ){
        while( t[y+1] == '*' ) ++y;
        int tmp;
        for(int i = x; i < la; i++){
            if( s[i] == t[y+1] ){
                tmp = find( i+1, y+2 );
                if(tmp) return 1;
            }
        }
        return 0;
    }
    else{
        if( s[x] != t[y] ) return 0;
        else return find( x+1, y+1 );
    }
}

int main(){
    while( scanf("%s %s", s, t) != EOF){
        la = strlen(s), lb = strlen(t);
        puts( find(0,0) ? "yes" : "no" );
    }
    return 0;
}
*/
