#include <cstdio>
int main()
{
   int x1,y1,x2,y2,x3,y3;
   int flag;
   while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
   {
       if(!x1&&!y1&&!x2&&!y2&&!x3&&!y3)
        break;
      flag=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
      if(flag<0) printf("1\n");
      else printf("0\n");
   }
    return 0;
}
 /*if((y1>=y2&&y1>=y3&&x3<=x2)
           ||(y2>=y1&&y2>=y3&&x3>=x1)
           ||(y3>=y2&&y3>=y1&&x1<=x2))
            printf("1\n");
       else if((y1>=y2&&y1>=y3&&x2<=x3)
          ||(y2>=y1&&y2>=y3&&x3<=x1)
          ||(y3>=y2&&y3>=y1&&x2<=x1))
          printf("0\n");
          */
