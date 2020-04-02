#include <iostream>
#define MAX_LENGTH 50
using namespace std;

void Getnext(int (&next)[MAX_LENGTH], int pattern_length, string &pattern) //�����ݹ��˼��
{
    next[0] = -1;
    int i = 0, j = -1;               //Ϊ�˷��㽫�������ͳһ����
    while(i < pattern_length - 1)    //iָ���ʱ��next��Ԫ�ص�ǰһλ
    {
        if(j == -1 || pattern[i] == pattern[j]) //�������ͳһ�����ص��ʼ���ַ���ͬ
        {
            next[++i] = ++j;                  //��ʱ�����ַ������ζ��next��ֵ��ǰһλ�Ļ�����+1
        }
        else
            j = next[j];  //��j�ƶ���jǰ�ַ�����ǰ׺�ĺ�һ��λ��
    }
}

int KMP(string &text, string &pattern)
{
    int text_length = text.length();
    int pattern_length = pattern.length();

    int next[MAX_LENGTH];
    Getnext(next, pattern_length, pattern);

    int i = 0, j = 0;
    while(i < text_length && j < pattern_length) //�������ַ�������֮ǰ
    {
        if(j == -1 || pattern[j] == text[i])  //��ǰ��û����ͬǰ��׺�����ַ���ͬͳһ����
        {
            i++;
            j++;
        }

        else                          //����ͽ�ָ��ָ����ǰԪ�ص�ǰ�ַ�����ǰ׺�ĺ��棨��Ϊǰ׺�պ�����ԭ����׺��λ���ϣ�
            j = next[j];
    }
    if(j = pattern_length - 1)  //�ҵ��˷��ؿ�ʼ��λ��
        return i - pattern_length - 1;

    return -1;                   //û�ҵ�����-1
}
int main()
{
    string text;
    string pattern;

    cout << "�����ı���\n";
    cin  >> text;
    cout << "����ƥ�䴮\n";
    cin >> pattern;

    int i = KMP(text, pattern);

    if(i == -1)
    cout << "ƥ��ʧ��";
    else
    cout << "ƥ��ɹ���Ŀ�괮��ʼ��string[" << i << "]";

    return 0;
}
