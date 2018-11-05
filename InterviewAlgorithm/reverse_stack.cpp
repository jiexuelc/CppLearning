/*************************************************************************
 * > File Name: reverse_stack.cpp                                                     *
 * > Author: jiexue
 * > Mail: jiexuelc@163.com
 * > Created Time: Mon 08 Oct 2018 08:26:52 PM CST
 * > Description: ��һ��ջ����ѹ��1��2��3��4��5����ջ�׵�ջ������Ϊ5��4��3��2��1
                  �õݹ麯��ʵ�ֽ����ջת�ã��������������ݽṹ������ջ����ջ��Ϊ1��2��3��4��5
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

/*
 * ��ȡջ��Ԫ�ز�ɾ�����ҳ�ջ��֮����������ݱ��ֲ���
 * ���磺ԭʼ����:ջ��--->ջ��: 3 2 1
 *      ������:1.ջ��--->ջ��: 2 1
 *              2.���ش�����3
 */
int getAndRemoveLastElement(stack<int>& s)
{
    int result = s.top();   //����ջ����Ԫ�أ�����ɾ����Ԫ��
    s.pop();    //ɾ��ջ��Ԫ�ص���������ֵ
    if(s.empty()) {
        return result;
    } else {
        int last = getAndRemoveLastElement(s);
        s.push(result);
        return last;
    }
}

/*
 * ��ջԪ�ط�ת
 * ���磺ԭʼ����:ջ��--->ջ��: 3 2 1
 *      ������:ջ��--->ջ��: 1 2 3
 */
void reverse(stack<int>& s)
{
    if(s.empty())
    {
        return;
    }
    int temp = getAndRemoveLastElement(s);
    reverse(s);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    reverse(s);
    
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}