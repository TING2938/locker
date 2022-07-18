#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

// regex_match判断内容是否匹配正则表达式
void test_match()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    regex reg("<(.*)>(.*)</(\\1)>");
    string content = "<xml>value</xml>";
    cout << "match? : " << regex_match(content, reg) << endl;
    cout << "match? : " << regex_match("123<xml>value</xml>456", reg) << endl;

    // 获取匹配的内容
    smatch m;  // string用`smatch`，C字符串用`cmatch`
    bool ret = regex_match(content, m, reg);
    cout << "match? " << ret << '\n'
         << m.str(0) << '\n'   // 匹配的内容
         << m.str(1) << '\n'   // 第1分组
         << m.str(2) << '\n';  // 第2分组
}

// regex_search 搜索一个匹配表达式
void test_search1()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    regex reg("<(.*)>(.*)</(\\1)>");
    cmatch m;
    auto ret = regex_search("123<xml>value</xml>456", m, reg);
    if (ret) {
        for (auto& elem : m) {
            cout << elem << endl;
        }
    }

    // 前缀和后缀，std::pair派生类，保存开始和姐结束迭代器
    cout << "prefix:" << m.prefix() << endl;
    cout << "suffix:" << m.suffix() << endl;
}

// regex_search 搜索所有匹配项，最好用`test_search3`版本
void test_search2()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    regex reg("<(.*)>(.*)</(\\1)>");
    string content("123<xml>value</xml>456<widget>center</widget>hahaha<vertical>window</vertical>the end");
    smatch m;
    auto pos = content.cbegin();
    auto end = content.cend();
    for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
        cout << "----------------" << endl;
        cout << m.str() << endl;
        cout << m.str(1) << endl;
        cout << m.str(2) << endl;
        cout << m.str(3) << endl;
    }
}

// regex_iterator迭代搜索所有匹配项
void test_search3()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    regex reg("<(.*)>(.*)</(\\1)>");
    string content("123<xml>value</xml>456<widget>center</widget>hahaha<vertical>window</vertical>the end");

    sregex_iterator pos(content.begin(), content.end(), reg);
    sregex_iterator end;
    for (; pos != end; ++pos) {
        cout << "----------------" << endl;
        cout << pos->str() << endl;
        cout << pos->str(1) << endl;
        cout << pos->str(2) << endl;
        cout << pos->str(3) << endl;
    }
}

// regex_token_iterator 分词迭代器，
// -1: 匹配之前的项，可以用来按分隔符划分子串
// 0：匹配分隔符
// 大于0的数：匹配分隔符的分组
void test_token_iterator()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;
    string data =
        "<person>\n"
        " <first>Nico</first>\n"
        " <last>Josuttis</last>\n"
        "</person>\n";

    regex reg("<(.*)>(.*)</(\\1)>");

    // iterate over all matches (using a regex_token_iterator):
    sregex_token_iterator pos(data.cbegin(), data.cend(),  // sequence
                              reg,                         // token separator
                              {0, 2});                     // 0: full match, 2: second substring
    sregex_token_iterator end;
    for (; pos != end; ++pos) {
        cout << "match:  " << pos->str() << endl;
    }
    cout << endl;

    string names = "nico, jim, helmut, paul, tim, john paul, rita";
    regex sep("[ \t\n]*[,;.][ \t\n]*");                    // separated by , ; or . and spaces
    sregex_token_iterator p(names.cbegin(), names.cend(),  // sequence
                            sep,                           // separator
                            -1);                           // -1: values between separators
    sregex_token_iterator e;
    for (; p != e; ++p) {
        cout << "name:  " << *p << endl;
    }
}

// regex_iterator迭代器，迭代搜索所有匹配项
void test_iterator()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    string names = "nico, jim, helmut, paul, tim, john paul, rita";
    regex reg("[a-zA-Z]+");                            // matchs
    sregex_iterator pos(names.cbegin(), names.cend(),  // sequence
                        reg);                          // reg
    sregex_iterator end;
    for (; pos != end; ++pos) {
        cout << "name:  " << pos->str() << endl;
    }
}

// regex_replace，替换操作
void test_replace()
{
    cout << "\n----------- Test for " << __FUNCTION__ << endl;

    cout << regex_replace("he...ll..o, worl..d!", regex("\\."), "") << endl;

    // 分组功能，通过$N得到分组内容
    cout << regex_replace("001-one, 002-two, 003-three", regex("(\\d+)-(\\w+)"), "$1 mean $2") << endl;
}


int main()
{
    test_match();
    test_search1();
    test_search2();
    test_search3();
    test_token_iterator();
    test_iterator();
    test_replace();
}
