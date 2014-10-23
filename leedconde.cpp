#include <iostream>
#include <stdio.h>
using namespace std;
void Fail(int *next, char *P);
int KMP(char *T, char *P)
{
        int lenT = strlen(T);
        int lenP = strlen(P);
        int i = 0, j = 0;
        int *next = new int[lenP + 1];  //最后一个元素用不到
        Fail(next, P);                  //计算失败函数
        while(i < lenT && j < lenP)
        {
                if(j == -1 || T[i] == P[j])
                {
                        i++; j++;
                }
                else
                        j = next[j];   //P的下一个比较位置
        }
        delete [] next;
        if(j < lenP || j == 0)
                return -1;
        else
                return i - lenP;
}

//仍是一个模式匹配的过程，只不过目标串和模式串是同一串P，所以两个代码的程序很相似
void Fail(int *next, char *P)
{
        int lenP = strlen(P);
        int i = -1,j = 0;
        next[0] = -1;
        while(j < lenP)
        {
                if(i == -1 || P[i] == P[j])
                {
                        i++; j++;
                        next[j] = i;
                }
                else
                        i = next[i];
        }
}

int main(){
        char *str1 = "aacaaa";
        char *str2 = "aaab";
        cout << KMP(str1, str2) <<endl;
}
