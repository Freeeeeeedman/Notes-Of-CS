####  C++输入输出
1. cin >>
   - 以空格、tab或换行（回车也是换行）作为分隔符
        cin>>a>>b>>c;
   - 也可以接受一个字符串，遇 tab/space/enter 结束
   - int a; cin >> a; 输入字符'1'，a结果也为int类型1
2. cin.get()
   - 读取一个字符，返回值是int类型，是输入的字符的ASCII码值
   - **不会忽略分隔符**，若用的回车当分隔符，则会在输出的时候把回车也打印出来，造成了不用endl也换行的情况；
   - 将字符转成数字而不是ASCII码
     - 单字符：a = cin.get(); b = a - '0';
     - 字符串：atoi(a)
   - a = cin.get();
   - cin.get(b); 
   - cin.get(arr,3); 输入两个字符，数组内以空结尾
   - cin.get(arr,3,'\n);输入两个字符，数组内以\n结尾

3. getline()
   - 用于按照特定间隔符分割字符串
   - 需包含“#include<string>”
   - getline(istream is, string str, 结束符)， 默认结束符为'\n'
   - 可以读入 SPACE/TAB，遇到ENTER停止读取；且读取完成后会丢弃末尾的换行符
   - cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数
   - 当同时使用cin>>,getline()时，需要注意的是，在cin>>读入数据完成之后，如果接下来的字符是换行符，那么在使用 getline()之前需要用getchar()把换行符吞掉，然后再使用getline()读入下一行数据。否则，getline()会首先读入换行符，然后停止读取。由于getline()函数会丢弃数据末尾的换行符，因此最终读入的数据为空
   - 举例，如果用cin输入abc再enter，那么enter将保留再缓冲区被getline读取，但getline读取时会丢弃最后一个换行符，所以无任何输出


#### 循环输入输出处理常见问题
1. 为什么需要循环输入输出：通常来说OJ对于每道题里面有.in和.out文件，分别表示测试数据的输入和输出。如果某些编程题的所有数据都只做在一个.in和一个.out中，这样就会变成多组测试了，所以需要提交的代码中循环处理。

2. 处理方法：其实这个问题可以避免，就是编程题后台每个样例做一组对应的.in和.out文件，这样就变成单组测试，代码就不需要循环处理，但是平时练习的题目质量不一，这个问题都会出现。(有人在阿里笔试中遇到)

3. 代码里面循环处理了即使是单组测试也会完全没问题，所以为了偷懒，可以全写成循环处理。

4. 还有一个坑：如果测试数据是多组的，但是恰巧你代码里面需要些标记数组，map，set等，在循环内一定记得清空，不然可能会产生前面的测试样例影响了后续数据的答案。


#### 做题时要点总结
1. ACM模式中对应各类格式的输入数据的处理要熟稔
   https://ac.nowcoder.com/acm/contest/5657/G
2. 定义输入变量时一定要先初始化，否则会有随机值
3. 对于一些单次输入，要求输出的结果在循环外初始化，但必须要记得在循环内每次都要清空。
4. 每次循环内要清空数组，map，set， vector， string，cin，stringstream
      - cin.sync();
      - str.clear();
      - ss.clear();
5. 看清楚结果的输出格式，例如循环输出了cout << str << ' ';，但要记得最后还要补加一个**cout << endl**;来区分不同的结果
6. 在处理单组多个字符串时，如果是以空格为分割，用cin结合getchar()就可以了，但如果以其他符号分割，就必须用getline()结合stringstream
7. 审题时一定要注意数据范围，否则结果溢出即使思路对答案也是错误的！
      int                        [-2^31,2^31-1] ~ 2 * 10 ^ 9
      unsigned                   [0,2^32-1]
      long long                  [-2^63,2^63-1]
      unsigned long long         [0,2^64-1]
      char                       [-128,127]

      double        [-2^1024,2^1023] 即 [-1.7E+308,1.7E+308] 精度为16位左右
      long double   [-1.2e4932,1.2e4932] 精度不低于 double


8. 一些头文件
   - #include<bits/stdc++.h>：所有c++标准库的头文件
   - #include <iostream>：cin，cout
   - #include <sstream>：stringstream输入输出流
   - #include <algorithm>：一些算法，如sort()
   - #include <string>:字符串string
9.  cin()
   cin >> 以空格，换行，tab为结束符。但是会保留最后一个换行在缓冲区中。同时也不会读取最后一个空格。
11. getline()
   - 用来处理字符串的，输入的必须是字符串
   - 注意getline()默认在处理单行数据时是不以空格为分割的，会全部输入！
   - 在标准输入中连续使用cin>>, getline()时要用getchar()清除前一个cin>>留下的换行。注意如果缓冲区中还要空格也会被读取出来(但是如果用了stringstream流就不需要写getchar())
   - getline使用cin流，以'#'分割，但只会输出#前的字符
   - getline使用stringstream流，就可以正常输出所有以#分割的字符，包括最后一段
11. getchar()
   - 用来读取换行符

#### 针对特定输入数据的处理模板
1. 输入数据有多组, 每行表示一组输入数据，没有指明每行有几个数据
   如: 0 1 2 3 4 
       5 6 7 
   ```
   #include <iostream>
   using namespace std;

   int main() {
      int ele = 0;
      while(cin >> ele) {
         cin.sync();
         int sum = ele;
         while(getchar() != '\n') {
               cin >> ele;
               sum += ele;
         }
         cout << sum << endl;
      }
   }
   ```
2. 输入数据有多组，第一行表述数据组数，接下来每行第一个整数表示数据数目，其余表示数据
   ```
   #include <iostream>
   using namespace std;

   int main() {
      int t = 0;
      cin >> t;
      int n = 0;
      while(cin >> n) {
         cin.sync();
         int sum = 0, tmp = 0;
         for(int i = 0; i < n; i++) {
               cin >> tmp;
               sum += tmp;
         }
         cout << sum << endl;
      }
   }
   ```

3. 输入数据有多组， 输入的为字符串，以空格为分隔，每行为一组数据
   ```
   #include <iostream>
   #include <algorithm>
   #include <vector>
   #include <string>
   using namespace std;

   int main() {
      vector<string> strs;
      string str;
      while(cin >> str) {
         cin.sync();
         strs.clear();
         strs.push_back(str);
         while(getchar() != '\n') {
               cin >> str;
               strs.push_back(str);
         }
         sort(strs.begin(), strs.end());
         for(auto& str : strs) {
               cout << str << ' ';
         }
         cout << endl;
      }
   }
   ```

4. 输入数据有多组， 输入的为字符串，以','为分隔，每行为一组数据
   ```
   #include <iostream>
   #include <sstream>
   #include <algorithm>
   #include <vector>
   #include <string>
   using namespace std;

   int main() {
      vector<string> strs;
      string str;
      while(getline(cin, str)) {
         strs.clear();
         stringstream ss(str);
         while(getline(ss, str, ',')) {
               strs.push_back(str);
         }
         sort(strs.begin(), strs.end());
         for(int i = 0; i < strs.size() - 1; i++) {
               cout << strs[i] << ',';
         }
         cout << strs[strs.size() - 1] << endl;
      }
      
   }
   ```
5. 数据范围： 0 < a,b < 2 x 10 ^ 10
   ```
   #include <iostream>
   using namespace std;

   int main() {
      long long a = 0, b = 0;
      while(cin >> a >> b) {
         cout << a + b << endl;
      }
   }
   ```

