//copyright: www.acmerblog.com

#include <stdio.h>
#include <iostream>
using namespace std;
#define  MAX    26

typedef struct TrieNode
{
	int nCount;  // �ýڵ�ǰ׺ ���ֵĴ���
	struct TrieNode *next[MAX]; //�ýڵ�ĺ����ڵ�
} TrieNode;

TrieNode Memory[1000000]; //�ȷ�����ڴ档 malloc ��Ϊ��ʱ
int allocp = 0;

//��ʼ��һ���ڵ㡣nCount����Ϊ1�� next��Ϊnull
TrieNode * createTrieNode()
{
	TrieNode * tmp = &Memory[allocp++];
	tmp->nCount = 1;
	for (int i = 0; i < MAX; i++)
		tmp->next[i] = NULL;
	return tmp;
}

void insertTrie(TrieNode * * pRoot, char * str)
{
	TrieNode * tmp = *pRoot;
	int i = 0, k;
	//һ��һ���Ĳ����ַ�
	while (str[i])
	{
		k = str[i] - 'a'; //��ǰ�ַ� Ӧ�ò����λ��
		if (tmp->next[k])
		{
			tmp->next[k]->nCount++;
		}
		else
		{
			tmp->next[k] = createTrieNode();
		}

		tmp = tmp->next[k];
		i++; //�Ƶ���һ���ַ�
	}

}

int searchTrie(TrieNode * root, char * str)
{
	if (root == NULL)
		return 0;
	TrieNode * tmp = root;
	int i = 0, k;
	while (str[i])
	{
		k = str[i] - 'a';
		if (tmp->next[k])
		{
			tmp = tmp->next[k];
		}
		else
			return 0;
		i++;
	}
	return tmp->nCount; //���������Ǹ��ַ�  ���ڽڵ�� nCount
}

int main(void)
{
	char s[11];
	TrieNode *Root = createTrieNode();
	while (gets(s) && s[0] != '0') //����0 ����
	{
		insertTrie(&Root, s);
	}

	while (gets(s)) //��ѯ������ַ���
	{
		printf("%d\n", searchTrie(Root, s));
	}
	return 0;
}
