C++ STL里提供了很多字符串操作的函数，下面的字符串查找方面的部分函数用法简介。

1、find()

查找第一次出现的目标字符串：

/*
* Author:  mybestwishes
* Created Time:  2011/4/9 15:56:44
* File Name: find.cpp
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
     string s1 = "abcdef" ; 
     string s2 = "de" ;
     int ans = s1.find(s2) ; //在s1中查找子串s2
     cout<<ans<<endl;
     system("pause");
}

说明：如果查找成功则输出查找到的第一个位置，否则返回-1 ；

查找从指定位置开始的第一次出现的目标字符串：

/*
* Author:  mybestwishes
* Created Time:  2011/4/9 15:56:44
* File Name: find.cpp
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
     string s1 = "adedef" ; 
     string s2 = "de" ;
     int ans = s1.find(s2,2) ; //从s1的第二个字符开始查找子串s2
     cout<<ans<<endl;
     system("pause");
}

2、find_first_of()

查找子串中的某个字符最先出现的位置。find_first_of()不是全匹配，而find()是全匹配

/*
* Author:  mybestwishes
* Created Time:  2011/4/9 15:56:44
* File Name: find.cpp
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
     string s1 = "adedef" ; 
     string s2 = "dek" ;
     int ans = s1.find_first_of(s2) ; //从s1的第二个字符开始查找子串s2
     cout<<ans<<endl;
     system("pause");
}

其中find_first_of()也可以约定初始查找的位置：  s1.find_first_of(s2 , 2) ;

3、find_last_of()

这个函数与find_first_of()功能差不多，只不过find_first_of()是从字符串的前面往后面搜索，而find_last_of()是从字符串的后面往前面搜索。可以自行测试一下。

4、rfind()

反向查找字符串，即找到最后一个与子串匹配的位置。

5、find_first_not_of()

找到第一个不与子串的位置。



C++ STL库里还有很多与字符串操作相关的函数，熟练应用STL，字符串的处理将变得轻松、自在。