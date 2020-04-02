#include <iostream>
#define MAX_LENGTH 50
using namespace std;

void Getnext(int (&next)[MAX_LENGTH], int pattern_length, string &pattern) //包含递归的思想
{
    next[0] = -1;
    int i = 0, j = -1;               //为了方便将两种情况统一起来
    while(i < pattern_length - 1)    //i指向此时求next的元素的前一位
    {
        if(j == -1 || pattern[i] == pattern[j]) //两种情况统一，即回到最开始和字符相同
        {
            next[++i] = ++j;                  //此时两个字符相等意味着next的值在前一位的基础上+1
        }
        else
            j = next[j];  //将j移动到j前字符串的前缀的后一个位置
    }
}

int KMP(string &text, string &pattern)
{
    int text_length = text.length();
    int pattern_length = pattern.length();

    int next[MAX_LENGTH];
    Getnext(next, pattern_length, pattern);

    int i = 0, j = 0;
    while(i < text_length && j < pattern_length) //在两个字符串跑完之前
    {
        if(j == -1 || pattern[j] == text[i])  //将前方没有相同前后缀和有字符相同统一起来
        {
            i++;
            j++;
        }

        else                          //否则就将指针指到当前元素的前字符串的前缀的后面（因为前缀刚好套在原来后缀的位置上）
            j = next[j];
    }
    if(j = pattern_length - 1)  //找到了返回开始的位置
        return i - pattern_length - 1;

    return -1;                   //没找到返回-1
}
int main()
{
    string text;
    string pattern;

    cout << "输入文本串\n";
    cin  >> text;
    cout << "输入匹配串\n";
    cin >> pattern;

    int i = KMP(text, pattern);

    if(i == -1)
    cout << "匹配失败";
    else
    cout << "匹配成功，目标串开始于string[" << i << "]";

    return 0;
}
