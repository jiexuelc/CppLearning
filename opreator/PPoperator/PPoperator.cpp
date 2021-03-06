/*************************************************************************
	> File Name: PPoperator.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 16 Sep 2018 05:48:17 PM CST
	> Description: ++操作符int型在c++中的重载实现
        知识点:
            1. "()"优先级大于"++"运算符
            2. "()"运算结合方向从左往右
            3. "++"运算结合方向从右往左
            4. (i++)不能做左值，而(++i)可以
            // 前缀形式：
            int& int::operator++() //这里返回的是一个引用形式，就是说函数返回值也可以作为一个左值使用
            {//函数本身无参，意味着是在自身空间内增加1的
                *this += 1;  // 增加
                return *this;  // 取回值
            }
            
            // 后缀形式:
            const int int::operator++(int) //函数返回值是一个非左值型的，与前缀形式的差别所在
            {//函数带参，有另外的空间开辟
                int oldValue = *this;  // 取回值
                ++(*this);  // 增加
                return oldValue;  // 返回被取回的值
            }
            参考：https://www.cnblogs.com/duguochao/p/4665830.html
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    /*
     * 先计算a++,a=5;然后计算 a=a+4;
     * 注意:这里后一个加操作数取的是a++以前的值 
     */
    int a = 4;
    a += a++;
    cout << "    a += a++;  Value of a:  " << a << endl;    //9

    /*
     * 先计算++b,b=5;然后计算 b=b+5;
     * 注意:这里后一个加操作数取的是++b后的值 
     */
    int b = 4;
    b += ++b;
    cout << "    b += ++b;  Value of b:  " << b << endl;    //10

    /*
     * 先计算++c,c=5;然后计算 c=c+5;
     * 注意:这里后一个加操作数取的是++c后的值 
     */
    int c = 4;
    (++c) += c;
    cout << "(++c) += c;    Value of c:  " << c << endl;    //10

    /*
     * 不加()的情况和上一种情况一样
     * 先计算++c1,c1=5;然后计算 c1=c1+5;
     * 注意:这里后一个加操作数取的是++c1后的值 
     */
    int c1 = 4;
    ++c1 += c1;
    cout << " ++c1 += c1;   Value of c1: " << c1 << endl;   //10

    //int c2 = 4;
    //(c2++) += c2; //没有这种表达，编译出错; c2++不可用来作为左值

    /*
     * 这种情况不同的编译器有不同的实现方式
     * GNU里面的实现方式：
     *   1.先做++d, d=5;
     *   2.然后做d++;d=6;
     *   3.GNU编译器前一个加操作数取5,后一个加操作数取6;即d = 5 + 6
     * VS2010里面的实现方式：
     *   1.先做++d, d=5;
     *   2.然后做d = d+d = 5+5 = 10;
     *   3.最后d = d+1 = 11;
     * 两种实现方式读起来都比较奇怪
     */
    int d = 4;
    (++d) += d++;
    cout << "(++d) += d++;  Value of d:  " << d << endl;    //11

    /*
     * 和上一种加括号的类似
     */
    int d1 = 4;
    ++d1 += d1++;
    cout << "++d1  += d1++; Value of d1: " << d1 << endl;   //11

    return 0;
}
