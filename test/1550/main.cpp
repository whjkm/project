#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int A[26], B[26], C[26];
bool flag[26];
char str[300002];
int main(void)
{
    int i, lenth;
    while (cin >> str)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));

        lenth = strlen(str);
        for (i=0; i<lenth; i++)
        {
            A[str[i]-'A']++;
        }

        cin >> str;
        for (i=0; i<lenth; i++)
        {
            B[str[i]-'A']++;
        }

        cin >> str;
        for (i=0; i<lenth; i++)
        {
            C[str[i]-'A']++;
        }

        memset(flag, true, sizeof(flag));
        for (i=0; i<26; i++)
        {
            if (A[i] > lenth/2)
            {
                A[i] = lenth/2;
            }
            if (B[i] > lenth/2)
            {
                B[i] = lenth/2;
            }

            if (C[i] <= A[i] + B[i])
            {
                flag[i] = false;
            }

        }
        for (i=0; i<26; i++)
        {
            if (flag[i] == true)
            {
                break;
            }
        }
        if (i<26)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
