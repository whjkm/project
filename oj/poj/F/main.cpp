#include <iostream>
using namespace std;
int main()
{
    char a[1000];
    int i, times;
    int kind = 0;
    cin >> times;
    while (times--)
    {
        kind = 0;
        cin >> a;
        for (i=0; a[i]!= '\0'; i++)
        {
            if ( (i==0) && ((a[i] =='/') || (a[i] == '\\')) )
            {
                //Unix类型
                kind = 1;
                break;
            }
            if ((a[i] == ':')
                &&((a[i+1] == '/') || (a[i+1] == '\\'))
                &&((a[i+2] == '/') || (a[i+2] == '\\')))
            {
                //URL类型
                kind = 2;
                break;
            }
            if ((a[i] == ':')
                &&((a[i+1] == '/') || (a[i+1] == '\\'))
                &&((a[i+2] != '/') || (a[i+2] != '\\')))
            {
                //Windows类型
                kind = 3;
            }
        }
        switch(kind)
        {
        case 1:
            cout << "It's a path in Unix-like systems!" << endl;
            for (i=0; a[i]!='\0'; i++)
            {
                if (a[i] == '\\')
                    a[i] = '/';
                cout << a[i];
            }
            cout << endl;
            break;
        case 2:
            cout << "It's a URL!" << endl;
            for (i=0; a[i]!='\0'; i++)
            {
                if (a[i] == '\\')
                    a[i] = '/';
                cout << a[i];
            }
            cout << endl;
            break;
        case 3:
            cout << "It's a path in Windows system!" << endl;
            for (i=0; a[i]!='\0'; i++)
            {
                if (a[i] == '/')
                    a[i] = '\\';
                cout << a[i];
            }
            cout << endl;
            break;
        }
    }
    return 0;
}
