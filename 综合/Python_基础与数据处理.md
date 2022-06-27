[toc]
#Python基础
####一些要点
1. array和asarray的区别
   - 面对列表数据结构，array和asarray没有区别，都对元数据进行了复制并转化为ndarray。
   - 当数据源是ndarray时，array会copy出一个副本，占用新的内存，但asarray不会。
2. r,b,u,f
   - r去除转义r'input\n'
   - b表示后面字符串是bytes类型，网络编程中，服务器和浏览器只认bytes 类型数据
   - u后面字符串以 Unicode 格式 进行编码，一般用在中文字符串前面，防止因为源码储存格式问题，导致再次使用时出现乱码。
   - f表示再字符串内支持大括号内的python表达式`print(f'{name}')`
3. if __name__ == '__main__':
   - 在if __name__ == 'main': 下的代码只有在文件作为脚本直接执行时才会被执行，而import 到其他脚本中是不会被执行的
   - 内置的变量 __name__，当该模块被直接执行的时候，__name__ 等于文件名（包含后缀.py）；如果该模块 import 到其他模块中，则该模块的 __name__ 等于模块名称（不包含后缀.py）。


####规范
1. 定义以冒号结尾
2. 非空字符串解读为**True**
3. 函数
    - 函数指定描述性名称，且只在其中使用小写字母和下划线
    - 应包含简要地阐述其功能的注释，紧跟在函数定义后面，并采用文档字符串格式
    - 形参多时可在函数定义中输入左括号后按回车键，并在下一行按两次Tab键，从而将形参和只缩进一层的函数体区分开来
    - 形参默认值指定与调用关键词实参时等号两边不要有空格
    - 函数与方法的区别(对象内对象外)
4. 类
    - 首字母大写如**AssertName**，小写的名词如**my_name**为类的实例
5. 模块
    - 单行分隔方法、类中函数，双行分隔类、函数
7. windows使用反斜杠(\)表示路径
8. Python读取文本文件时，将文本文件解读为字符串，需转为数值。同时写入也只能以字符串写入
9. 特性
    - 解释性语言:解释器
    - 强类型化语言:变量是在特殊命名空间中的对象的名字， 类型信息保存在对象自身中
    - 面向对象:python中万物皆为对象
####函数
1. 传递参数   
    - 位置实参
    - 关键词实参
    - 默认值
    - 任意数目实参:* **
    - 优先级:(其他,默认值，* **)
2. 列表
    - 修改是永久性的
    - 传递副本来禁止修改：`function_name(list_name[:])`
3. 模块
    - 导入整个模块`import module_name` `module_name.function_name()`
    - 导入特定函数`from module_name import function_name` `function_name()`
    - 指定别名`from module_name import function_name as mp` `import module_name as mp`
    - 导入所有函数`from module_name import *`
4. 作用域
    - 全局作用域中的代码不能使用任何局部变量
    - 局部作用域可以访问全局变量
    - 在一个函数中， 一个变量要么总是全局变量， 要么总是局部变量
    - 如果需要在一个函数内修改全局变量， 就使用global 语句
5. 引用
    - **数据是何时、 如何、 为何复制**
    - 将对象作为参数传递给函数时， 新的局域变量创建了对原始对象的引用， 而不是复制
####类
1. 名词
    - 面向对象，实例化，类，方法，属性
2. \__init\__():
    - **self**指向实例本身的引用，让实例能够访问类中的属性和方法
3. 属性
    - 通过实例访问的变量
    - 可设置默认值
4. 继承
    - 定义:一个类继承另一个类时，它将自动获得另一个类的所有属性和方法
    - 子类的__init__():
    - 
                ```
                class ElectricCar(Car):
                """电动汽车的独特之处"""
                    def __init__(self, make, model, year):
                """初始化父类的属性"""
                super().__init__(make, model, year)
                ```
    - 重写方法：重写后只关注在子类中定义的相应方法
    - 大型类拆分成多个协同工作的小类
5. 导入类
    - 导入多个类:`from car import Car, ElectricCar`
    - 导入整个模块
    - 导入模块中所有类:易导致名称冲突
    - 从模块中导入另一个模块:调用函数都需要写
6. 工作流程
    - 先完成后分隔
    - 先分隔后完成
  
####异常
1. 定义
    - Python使用被称为异常的特殊对象来管理程序执行期间发生的错误
    - 元组处理多个异常(TypeError, ValueError),也只可以处理特定异常
2. try-except-else:
     -           ```
                while True:
                    first_number = input("\nFirst number: ")
                    if first_number == 'q':
                    break
                    second_number = input("Second number: ")
                    try:
                        answer = int(first_number) / int(second_number)
                    except ZeroDivisionError:
                        print("You can't divide by 0!")
                    else:
                        print(answer)
                ```
3. pass
     -           ```
                while True:
                    first_number = input("\nFirst number: ")
                    if first_number == 'q':
                    break
                    second_number = input("Second number: ")
                    try:
                        answer = int(first_number) / int(second_number)
                    except ZeroDivisionError:
                        pass
                    else:
                        print(answer)
                ```
4. finally
     -          ```
                try:
                    ...
                finally:
                    ... 
5. 出现异常
    - 只要程序依赖于外部因素，如用户输入、存在指定的文件、有网络链接，就有可能出现异常
6. 意义
    - 避免程序崩溃
    - 掩盖traceback
  
####测试
1. 定义
    - 通过测试，可确定代码面对各种输入都能够按要求的那样工作
    - 单元测试，测试用例，全覆盖式测试，断言
2. 测试函数
    -           ```
                import unittest
                from name_function import get_formatted_name
                class NamesTestCase(unittest.TestCase):
                """测试name_function.py"""
                    def test_first_last_name(self):
                        """能够正确地处理像Janis Joplin这样的姓名吗？ """
                        formatted_name = get_formatted_name('janis', 'joplin')
                        self.assertEqual(formatted_name, 'Janis Joplin')
                unittest.main()
                ```
    - 方法名必须以test_打头，这样它才会在我们运行test_name_function.py时自动运行
3. 测试类
    -           ```
                import unittest
                from survey import AnonymousSurvey
                  
                class TestAnonmyousSurvey(unittest.TestCase):
                """针对AnonymousSurvey类的测试"""
                    def test_store_single_response(self):
                        """测试单个答案会被妥善地存储"""
                        question = "What language did you first learn to speak?"
                        my_survey = AnonymousSurvey(question)
                        my_survey.store_response('English')
                        self.assertIn('English', my_survey.responses)
                unittest.main()
                ```
4. setUp()
    - Python将先运行setUp()
    - 可在setUp()方法中创建一系列实例并设置它们的属性，再在测试方法中直接使用这些实例
5. 意义
    - 确认开发模块时没有破坏既有行为
  

#利用Python进行数据分析
  
####概述
1. 结构化数据
     - 有某种特征的数据集
     - 矩阵、表格数据
     - 数据规整、伪码
2. Python作为胶水语言
     - 轻松集成C、 C++以及Fortran代码
     - 大部分执行时间的代码， 以及大量不经常执行的“胶水代码”。主要专注优化计算瓶颈
3. Python不适用于
     - 运行时间慢:延迟要求非常小或高资源利用率的应用
     - 全局解释器锁:高并发、 多线程(C&C++插件)
4. Python库
     - Numpy:快速的数组处理能力;作为在算法和库之间传递数据的容器(低级语言直接调用)
     - Pandas:提供快速便捷处理结构化数据的大量数据结构和函数
     - matplotlib:绘制图表和其它二维数据可视化的Python库
     - IPython&Jupyter:强化shell，提高交互式计算和软件开发的生产率
     - Scipy:解决科学计算中各种标准问题域的包的集合
     - Scikit-learn:通用机器学习工具包
     - Statsmodels:统计分析包
5. IPython&Jupter
     - jupyter notebook,ipython
     - 自省:?,??
     - 魔术命令:%run,&cpaste,%quickref,%magic
  
####语法基础
1. isinstance
      ` isinstance(a, int)`
2. iter
    ```
        def isiterable(obj):
            try:
                iter(obj)
                return True
            except TypeError: # not iterable
                return False
    ```
3. is
     - 注意与==的区别
4. None
     - None唯一实例为None
     - 作为函数的默认参数
5. 可变与不可变
     - 可变:列表,字典,NumPy数组,类
     - 不可变:字符串,元组
     - 副作用:标明副作用，推荐采用不可变的方式
6. 标量
     - 单值类型
         - 字符串，数值数据，布尔值，日期时间
     - 字符串
         - `s.count('\n')`
         - `s = r'this\has\no\special\characters'`
         - 格式化:`format()`
         - Unicode:`val.encode('utf-8') # val.decode('utf-8')`
     - 布尔值
         - and,or
     - 类型转换
         -`str(),bool(),int(),float() `
7. 控制流
     - if，elif，else
     - for
         - continue,break
         - 如果集合或迭代器中的元素序列（元组或列表） ， 可以用for循环将其方便地拆分成变量`for a, b, c in iterator:...`
     - while
     - pass
     - range
         - `list(range(0, 20, 2))`
         - 用于序号迭代序列
         - ```
            seq = [1, 2, 3, 4]
            for i in range(len(seq)):
                val = seq[i]
           ```
     - 三元表达式
         -value = true-expr if condition else false-expr
         -只有true的分支会被执行
  
####数据结构与序列
1. 元组
     - tuple()
     - 元组不可变，其中某个对象可变
     - +串联，*复制
         - 对象本身没有被复制，只是引用
     - 变量拆分
         - `a, b, (c, d) = tup = 4, 5, (6, 7)`
         - 常用来迭代元组或列表序列
         - a,b,*_ = values
2. 列表
      - list()
      - append()
      - insert(1,'red')
         - 计算量大
      - pop(1)
      - remove('red')
      - in:if `dwarf` in list 
      - `+`
         - 复制对象,新建列表 
      - extend()  
          - 比串联方法计算量小
           ```
            everything = []
            for chunk in list_of_lists:
                everything.extend(chunk)
           ``` 
      - sort()
          - sort(key=len)
          - 不创建新的对象
      - 二分搜索与插序
          - `bisect.bisect(c, 2)`
          - `bisect.insort(c, 6)`
      - 切片
          - 包含起始元素，不包含结束元素
          - 元素个数stop-start
          - 负数表明从后向前切片
          - 颠倒数组seq[::-1]
      - 序列函数
          - enumerate()
            - `for i, value in enumerate(collection):`
            - 字典映射
          - sorted()
          - zip()
            - 将多个序列成对组合成一个元组列表
            - 元素的个数取决于最短的序列
            - 解压序列 `first_names, last_names = zip(*pitchers)`
          - reversed()
            - reversed是生成器,需要实体化后才能创建翻转的序列
            - `list()reversed()`
3. 字典
      - 哈希映射,关联数组
      - 二元元组的集合,键和值都是Python对象
      - 像访问列表或元组中的元素一样,访问、插入或设定字典中的元素
      - 检查字典中是否包含某个键:`'b' in d1`
      - `del d1[5]`
      - `ret = d1.pop('dummy')`
      - keys(),values()
        - 输出顺序相同
      - update()
      - 序列创建字典
           - zip()创建
                ``` 
                mapping = {}
                for key, value in zip(key_list, value_list):
                mapping[key] = value
                ```
      - 默认值
          - get()
             `value = some_dict.get(key, default_value)`
          - setdefault()
             ```
             for word in words:
             letter = word[0]
             by_letter.setdefault(letter, []).append(word)
             ```
          - defaultdict
             ```
             from collections import defaultdict
             by_letter = defaultdict(list)
             for word in words:
                by_letter[word[0]].append(word)
             ```
      - 有效的键类型
          - 可哈希性:键为标量或元组(元组内对象必须不可变)
          - hash
4. 集合
      - 集合是无序的不可重复的元素的集合
      - 元素不可变
      - 常用方法
        - set(),{}
        - union(),|
        - intersection(),&
        - issubset()
        - issuperset()
        - ==
        - 都有另外的原地实现方法，对于大集合效率更高
5. 列表、集合和字典推导式
      - 允许用户方便的从一个集合过滤元素,形成列表,在传递参数的过程中还可以修改元素
      - `[expr for val in collection if condition]`
      - `dict_comp = {key-expr : value-expr for value in collection if condition}`
      - `set_comp = {expr for value in collection if condition}`
      - 例:`loc_mapping = {val : index for index, val in enumerate(strings)}`
6. 嵌套列表推导式
      -  for表达式的顺序是与嵌套for循环的顺序一样
      -  ```
         some_tuples = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
         flattened = [x for tup in some_tuples for x in tup]
         ```
  
####函数
1. 返回多个值
      - 返回元组，字典
2. 函数也是对象
      - 可以将函数作为列表的元素使用
      - 可以将函数作为函数的参数使用
      - map用于在一组数据上应用一个函数
        `map(function,data)`
3. 匿名(lambda)函数
      - 数据转换函数都以函数作为参数
      - 直接传入lambda函数更清晰
4. 柯里化(curried)
      - 通过部分参数应用派生新函数
        `add_five = lambda y: add_numbers(5, y)`
5. 生成器
      - 迭代器
        - 在循环的上下文中向解释器输送对象
        - 能接受列表之类的对象的方法也可以接受任何迭代器
        - `dict_iterator = iter(some_dict)`
      - 生成器
        - 造新的可迭代对象的一种简单方式
        - 要创建一个生成器,需将函数中的return替换为yeild
      - 生成器表达式
        - 把列表推导式两端的方括号改成圆括号
        - 可作为函数参数
      - itertools模块
  
####文件和操作系统
1. 文本文件
      - `f = open(path)``f.close()`
      - `with open(path) as f`
      - r,w,a,r+,b
      - read(),write(),tell(),seek()
      - readlines(),writelines()
2. 如果经常要对非ASCII字符文本进行数据分析， 通晓Python的Unicode功能是非常重要的
    
####Numpy基础
1. 用于数值计算的优点
      - NumPy数组使用的内存更少
      - NumPy可以在整个数组上执行复杂的计算， 而不需要Python的for循环
2. ndarray
      - 定义
          - 一种多维数组对象
          - 所有元素必须为相同类型,基本为float64
          - **精通面向数组的编程和思维方式**
      - 创建
          - list直接转换:`arr1 = np.array(data1)`
          - zeros():返回0
          - empty():返回为未初始化的垃圾值
          - arange()
          - shape,dtype
      - 数据类型
          - 当需要控制数据在内存和磁盘中的存储方式时(尤其是对大数据集),那就得了解如何控制存储类型
          - astype(),也可将字符串数字转换为数值np.string_
      - 运算
          - 矢量化:即用数组表达式代替循环的做法,大小相等的数组之间的任何算术运算都会将运算应用到元素级
          - 广播:不同大小的数组之间的运算,将标量值赋值给一个切片时，该值会自动传播
      - 基本的索引与切片
          - 数组切片是原始数组的视图，对于视图的任何修改会直接反映到源数组上
          - 复制:`arr[5:8].copy()`
          - 索引:arr3d[0][2],arr3d[0, 2],由外向内0,1,2...轴
          - `arr[:]=0`
      - 切片索引
          - 可一次传入多个切片:`arr[:1,2:]`
          - 混合索引与切片:`arr2d[1, :2]`
          - “只有冒号”表示选取整个轴`arr2d[:1, :]`
          - 通过切片索引可以选取数组任意区域数据
      - 布尔型索引
          - 布尔型索引选取数据创建的是数据的副本         
          - 布尔型数组的长度必须跟被索引的轴长度一致:`data[names == 'Bob']`
          - 反转操作符:`cond = names == 'Bob'`,`data[~cond]`
          - 布尔条件:&,|而非and,or
          - 布尔型数组设置值:data[data < 0] = 0
          
      - 花式索引
          - 创建的是数据的副本        
          - 利用整数数组进行索引:`arr[[1, 5, 7, 2], [0, 3, 1, 2]]`
      - 数组转置和轴对换
          - 返回原数据的视图
          - arr.T
          - arr.transpose((1, 0, 2))
          - arr.swapaxes(1, 2)
3. 通用函数:快速的元素级数组函数
      - 一元(unary) ufunc: np.sqrt(arr)...
      - 二元(binary) ufunc: np.maximum(x, y)...
      - 返回多个数组:remainder, whole_part = np.modf(arr)...
4. 利用数组进行数据处理
      - 将条件逻辑表述为数组运算
          - ``` 
            result = [x if c else y]
                for x,y,c in zip[(xarr,yarr,cond)]
            ```
            处理数据慢且无法用于多维数组
          - `result = np.where(cond, xarr, yarr)`
          - 将标量与数组结合:`np.where(arr > 0, 2, arr)`
      - 数学与统计方法
          - 对整个数组或某轴向的数据进行聚合计算(约简)
          - 既是数组的实例方法也是顶级的np函数
          - `arr.mean(axis=1)`行
          - `np.sum(arr,axis=0)`列
      - 用于布尔型数组的方法
          - 非0为true
          -  (arr > 0).sum()
          -  arr.any()
          -  arr.all()
      - 排序
          - `arr.sort()`:修改数组本身
          - `np.sort(arr)`:返回副本
          - 计算分位数
      - 唯一化等集合逻辑
          - np.unique()
          - 集合运算
5. 用于数组的文件输入输出
      - .npy:`np.save('some_array', arr)`
      - .npz:`np.savez('array_archive.npz', a=arr, b=arr)`
      - 压缩:`np.savez_compressed('arrays_compressed.npz', a=arr, b=arr)`
6. 线性代数
      - 元素级运算:+-*/
      - 矩阵乘法:np.dot(x,y),x.dot(y),x@y
      - 常用的线性代数函数:numpy.linalg
7. 伪随机数生成
      - Python内置的random模块则只能一次生成一个样本值
      - np.random.normal()...
8. 随机漫步过程

####Pandas基础
1. 区别
      - panda:数据清洗和分析,numpy:数值计算
      - Pandas:处理表格和混杂数据设计的,NumPy:处理统一的数值数组数据
2. Series
      - 由一组数据及其相关的索引组成，类似定长的有序字典
      - 创建
         - Series([],index=[])
         - 字典创建  
      - 方法
         - obj.values,obj.index
         - pd.isnull(obj),pd.notnull(obj),obj.isnull()
         - obj.map(func)
      - 修改
          - 排序:传入排好序的字典的键来改变顺序,缺省NaN
          - 运算自动对齐
          - 赋值直接修改索引obj.index=[]
3. DataFrame
      - 表格型数据结构，列有序
      - 通过索引返回的列是视图,copy()可指定赋值列
      - 创建
          - DataFrame(,columns=[],index=[])
          - 直接直接传入一个由等长列表或NumPy数组组成的字典
          - 嵌套字典,外层为列,内层为行
      - 修改
          - 列直接赋值:frame['a']=1
          - 列列表,数组，series赋值
          - 列删除 del frame['a']
      - 方法
          - frame.head()
          - frame.columns()
          - 获取列为series:frame['a'],frame.a
          - 获取行:frame.loc[3]
          - 转置:frame.T
          - 设置name:frame.index.name,frame.columns.name
          - frame.values
4. 索引对象
      - 管理轴标签和其他元数据(比如轴名称等) 
      - index=obj.index,为不可变对象
      - 类似集合,有方法与属性，可以设置逻辑提供信息,但可包含重复的标签
5. 基本功能
      - 重新索引
          - reindex(),返回新的对象而不是视图
          - 新索引:`series2=series1.reindex['a','b','c']`
          - 插值:`series2=series1.reindex(range(6), method='ffill')`
          - 修改行,列索引:`frame.reindex(columns=states)`
      - 丢弃指定轴上的项
          - 返回新对象,就地修改`...inplace=True`
          - 删除行:`new_obj=obj.drop(['d', 'c'])`
          - 删除列:`data.drop(['two', 'four'], axis='columns')``...axis=1`
      - 索引,选取,过滤
          - Series
              - 索引:名称,序号,布尔值`data[data<5]=0`
              - 切片:` obj['b':'c']`标签切片包含末端
          - DataFrame
              - 索引:获取的为**列**
              - 切片:选取的为**行**:`data[:2]`
      - loc和iloc索引
          - loc:`data.loc[:'Utah', 'two']`
          - iloc:`data.iloc[:, :3][data.three > 5]`
      - 整数索引
          - 非整数索引没有歧义
          - 整数索引歧义:`标签:ser.loc[:1],整数:ser.loc[:1],ser.iloc[:1]` 
      - 算术运算
          - 不同索引的对象算数运算相当于集合运算
          - 缺失值会在算术运算过程中传播
          - NaN时填充值:`df1.add(df2, fill_value=0)`
          - DataFrame和Series之间的运算
              - 匹配列且在行上广播
              - 匹配行且在列上广播`frame.sub(series3, axis='index')`
      - 函数应用
          - NumPy的ufuncs(元素级数组方法)也可用于pandas对象:`np.abs(frame)`
          - Python的元素级函数也可使用
              ```
              format = lambda x: '%.2f' % x
              frame.applymap(format)
              ```
          - 将函数应用到由列或行所形成的一维数组:`frame.apply(f,axis='columns')`
          - 函数可以返回多个值组成的Series
              ```
              def f(x):
                return pd.Series([x.min(), x.max()], index=['min', 'max'])
              ```
      - 排序与排名
          - sort_index()
              - `frame.sort_index(axis=1, ascending=False)`
              - `frame.sort_values(by=['a', 'b'])`
          - rank()
              -  `obj.rank()`
              -  `obj.rank(ascending=False, method='max')`
      - 标签重复时
          - obj.index.is_unique
          - 索引对应多个值返回一个Series(DataFrame),对应单个值返回一个标量值(DataFrame)
      - 汇总和计算描述统计
          - 基于没有缺失数据的假设而构建,NA值自动被排除
          - 方法
              - `df.mean(axis='columns', skipna=False)`
              - `df.idxmax()`
              - `df.cumsum()`
              - `df.describe()`
      - 相关系数与协方差
          - corr(),cov()
              - 用于计算两个Series中重叠的、 非NA的、 按索引对齐的值的相关系数 
              - `returns['MSFT'].corr(returns['IBM'])` 
              - DataFrame:`returns.corr()`
          - corrwith()
              - 可以计算其列或行跟另一个Series或DataFrame之间的相关系数
      - 唯一值,值计数以及成员资格
          - unique()
          - value_counts()
              - 同时也是pd顶级方法
              - `result = data.apply(pd.value_counts).fillna(0)`
          - isin()
              - 判断矢量化集合的成员资格,过滤子集
             ```
             mask = obj.isin(['b', 'c'])
             obj[mask]
             ```
          - Index.get_indexer()

  
####数据加载,存储与文件格式
1. 读写文本格式的数据
      - 函数选项
          - 索引
          - 类型推断和数据转换
          - 日期解析
          - 迭代
          - 不规整数据问题
      - read_cvs()
          - 自动类型推断  
          - 层次化索引:index_col=[..]
          - 指定分隔符:sep=..
          - 非固定分隔符:正则表达式,sep='\s+'
          - 处理异形文件格式:跳过指定行,skiprows=[..]
          - 缺省值处理:针对不同列标记缺省值,na_values={..}
      - 逐块读取文本文件
          - 读几行:nrows=..
          - 逐块读取:chunksize=..
              - 返回的是TextParser对象`for piece in chunker`
              - 读取任意大小块:get_chunk
      - 将数据写入文本格式
          - to_csv()
          - 输出指定分隔符,sep='..'
          - 缺省值
              - 缺失值在输出结果中会被表示为空字符串
              - 表示为其他(不同于读入时标记):na_rep='..'
          - 禁用行列标签index=False,header=False
          - 输出指定列并排序columns=[..]
      - 处理分隔符格式
      - JSON数据
          - 将JSON字符串转换成Python形式:json.loads(obj)
          - 将Python对象转换成JSON格式:json.dumps(result)
          - 将JSON对象转换为DataFrame
            `siblings = pd.DataFrame(result['siblings'], columns=['name', 'age'])`
            自动转换:read_json()
          - 将pandas转换为JSON:to_json()
      - XML和HTML： Web信息收集
2. 二进制数据格式
      - pickle序列化  
          - to_pickle()
          - read_pickle()
          - 建议用于短期存储格式
      - HDF5格式
          - 存储大规模科学数组数据,有许多语言的接口,可高效分块读取
          - 层次型数据格式(hierarchical data format):每个HDF5文件都含有一个文件系统式的节点结构,能够存储多个数据集并支持元数据
          - 不是数据库,适合用作“一次写多次读”的数据集.如果同时发生多个写操作,文件就可能会被破坏
          - **PyTables,h5py库**
              - HDFstore()
              - fixed,table:后者支持查询
              - 本地处理海量数据,IO密集型
          - Pandas
              - to_hdf()
              - read_hdf()
      - Microsoft Excel文件
3. Web APIs交互
      - requests包
          - ` resp = requests.get(url)` `data = resp.json()`
          - data中的每个元素都是一个字典,可直接传递到DataFrame再提取数据
4. 数据库交互
      - 商业场景下,大多数数据可能不是存储在文本或Excel文件中,而是储存于基于SQL的关系型数据库


####数据清洗和准备
1. 简述
      - 在数据分析和建模的过程中,相当多的时间要用在数据准备上:加载,清理,转换以及重塑.这些工作会占到分析师时间的80%或更多
2. 处理缺失数据
      - 滤除缺失数据
          - pandas对象的所有描述性统计默认都不包括缺失数据
          - Python内置的None值在对象数组中也可以作为NA
          - dropna()
              - Series:返回一个仅含非空数据和索引值的Series
              - DataFrame:默认丢弃任何含有缺失值的行
                  - how='all'
                  - axis=1
                  - thresh=..
      - 填充缺失数据
          - fillna()
              - 字典调用实现对不同的列填充不同的值
              - 默认会返回新对象,对现有对象进行就地修改:inplace=True
              - 插值
              - 用平均值或中位值填充
3. 数据转换
      - 移除重复数据
          - duplicated(),drop_duplicates()
              - 默认判断全部列,可指定列
              - 默认保留第一个出现的值组合,keep='last'
      - 利用函数或映射进行数据转换
          - 映射:字典对象,注意大小写
          - map()
              - 可以接受一个函数或含有映射关系的字典型对象
              - 实现元素级转换及其他数据清理工作
              - `data['food'].map(lambda x: meat_to_animal[x.lower()])`
      - 替换值
          - replace()
          - `data.replace([-999, -1000], [np.nan, 0])`
          - `data.replace({-999: np.nan, -1000: 0})`
      - 重命名轴索引
          - map(..)
              - `data.index = data.index.map(transform)`
          - rename()
              - `data.rename(index=str.title, columns=str.upper)`
              - `..(index={'a':'b'})`
      - 离散化和面元(Bin)划分
          - cut()
              - 返回的是一个特殊的Categorical对象
              - cats = pd.cut(ages, bins)
              - cats.codes
              - cats.categories
              - pd.value_counts(cats)
              - 闭端修改:right=False
              - 设置面元名称:labels=..
              - 传入面元数量时,会根据数据的最小值和最大值计算等长面元:precision=..
          - qcut()
              - 根据样本分位数对数据进行面元划分
              - 也可以传递自定义的分位数(0,1),包含端点
      - **检测和过滤异常值**
          - 找出某列中绝对值大小超过3的值
            ```
            col = data[2]
            col[np.abs(col)>3]
            ```
          - 选出全部含有“超过3或－3的值”的行
            `data[(np.abs(data) > 3).any(1)]`
          - 限制异常值
            `data[(np.abs(data) > 3).any(1)]=np.sign(data) * 3`
      - 排列和随机采样
          - np.random.permutation()再使用iloc索引或take()
          - sample(n=..)
              - 替换(允许重复选择)replaced=True
      - 计算指标/哑变量
          - 另一种常用于统计建模或机器学习的转换方式是:将分类变量(categorical variable+转换为“哑变量”或“指标矩阵”
4. 字符串操作
      - 字符串对象方法
          - split()
          - strip()
            `pieces = [x.strip() for x in val.split(',')]`
          - join(),相当于加法
            `'::'.join(pieces)`
          - index(),返回1,异常
          - find(),返回1,-1
          - count()
          - replace(',','::'),也可用于删除
          - 都可用正则表达式
      - **正则表达式(regex)**
          - re模块:模式匹配,替换,拆分
          - findall()
          - search()
          - match()
          - sub()
          - map()
          - 对许多字符串应用同一条正则表达式时,应通过re.compile创建regex对象,这将节省大量的CPU时间
          - ...
      - pandas的矢量化字符串函数
          - str(),跳过NA值面向数组方法,直接进行字符串操作
              - str.contains()
              - str.findall()
              - str.get()
              - str[:]


####数据规整:聚合,合并和重塑
1. 层次化索引
      - 层次化索引
          - 能在一个轴上拥有多个(两个以上)索引级别,以低维度形式处理高维度数据
          - 对层次化索引的对象可以使用部分索引`data.loc[:, 2]`
          - un.stack(),stack()
          - DataFrame每条轴都可以有分层索引
              - 小心区分索引名与行标签
              - 可以单独创建MultiIndex然后复用
      - 重排与分级排序
          - swaplevel()
          - sort_index()
            `frame.swaplevel(0, 1).sort_index(level=0)`
      - 根据级别汇总统计
          - `frame.sum(level='color', axis=1)`
      - 使用DataFrame的列进行索引
          - set_index()
            `frame2 = frame.set_index(['c', 'd'],drop=false)`
          - reset_index()
2. 合并数据集
      - 数据库风格的DataFrame合并
          - 多对一的合并
              - merge(),on='',left_on='',right_on='',how=''
          - 多对多的合并
              - 产生的是行的笛卡尔积 
              - 多个键形成一系列元组,并将其当做单个连接键
              - 索引会被丢弃
              - 重复列名:suffixes=('','')
      - 索引上的合并
          - `pd.merge(left1, right1, left_on='key', right_index=True)`
          - 层次化索引的数据
              - 必须以列表的形式指明用作合并键的多个列
              - join(),要求没有重叠的列,默认左连接
      - 轴向连接
          - 也称连接(concatenation),绑定(binding)或堆叠(stacking)
          - concat()
          - 行:axis=0,列axis=1变为DataFrame
          - 交集:join='inner'
          - 指定索引:join_axes=[]
          - 创建层次化索引:keys=[],传入字典则字典的键作为keys选项的值
          - 命名轴:names=[]
          - 行索引不包括数据时:ignore_index=True
      - 合并重叠数据
          - where()
            `np.where(pd.isnull(a), b, a)`
          - combine_first
              - 用传递对象中的数据为调用对象的缺失数据“打补丁” 
3. 重塑和轴向旋转
      - 重塑层次化索引
          - stack(),unstack()
              - 对DataFrame使用stack将列转换为行,得到一个Series
              - 对于一个层次化索引的Series,unstack将其重排为一个DataFrame
              - 传入分层级别的编号或名称即可对其它级别进行unstack操作
              - 缺失数据时,unstack操作可能会引入缺失数据,stack默认会滤除缺失数据,因此该运算是可逆的
      - 旋转DataFrame
          - pivot()
              - pivot其实就是用set_index创建层次化索引， 再用unstack重塑
              - `pivoted = ldata.pivot('date', 'item')`
          - melt()
              - 必须指明哪些列是分组指标
              - pivot()重塑,pivot的从列创建了一个索引用作行标签,可以使用reset_index将数据移回列
              - 指定列的子集,value_vars=[]


####绘图和可视化
1. matplotlib API入门
      - Figure和Subplot
          - figure()
              - figure对象,`fig = plt.figure()`
              - `ax1 = fig.add_subplot(2, 2, 1)`
          - subplots()
              - `fig, axes = plt.subplots(2, 3)`
              - axes[0,1]实用
          - subplots_adjust()
              - wspace=0,haspace=0
          - set_xlim()
      - 颜色,标记和线型
          - 'ko--'
          - `plot(randn(30).cumsum(), color='k', linestyle='dashed', marker='o')`
      - 标题,轴标签,刻度,刻度标签,注解,绘图
          - 实现方式
              - 过程型的pyplot接口
              - 面向对象的原生matplotlib API
          - 刻度
              - set_xticks()
              - set_xticklabels()
              - set_xlabel()
          - 标题
              - set_title()
          - **批量设定**
            ```
            props = {
                'title': 'My first matplotlib plot',
                'xlabel': 'Stages'
            } 
            ax.set(**props)
            ```
          - 图例
              - 绘图时传入label=''
              - 自动创建ax.legend(loc='best'),plt.legend()
          - 注解,箭头,图形
              - ax.text(x,y,...)
              - ax.annotate
              - add_patch()
      - 将图表保存到文件
          - plt.savefig()
          - 实例方法
          - `plt.savefig('figpath.png', dpi=400, bbox_inches='tight')`
          - 也可写入任何文件型对象
      - matplotlib配置
          - rc()
            ```
            font_options = {'family' : 'monospace',
                            'weight' : 'bold',
                            'size'   : 'small'}
            plt.rc('font', **font_options)
            ```
          - 配置文件matplotlib/mpl-data/matplotlibrc
2. 使用pandas和seaborn绘图
      - 线型图
          - Series及DataFrame本身即有plot()
          - 索引默认x轴,use_index=False禁止
      - 柱状图
          - 索引将被用于X或Y刻度
          - bar(),barh()
          - stacked=True堆积
          -  柱状图有一个非常不错的用法:利用value_counts图形化显示Series中各值的出现频率,比如s.value_counts().plot.bar()
          - seaborn模块:sns.barplot()
      - 直方图和密度图
          - plot.hist()
          - plot,density()
          - sns.displot()
      - 散布图或点图
          - sns.regplot()
          - 散步图矩阵sns.pairplot()
      - 分面网格(facet grid)和类型数据
          - sns.factorplot()
          - 盒图(显示中位数，四分位数及异常值)
  

####数据聚合与分组运算
1. 简介
      - 关系型数据库和SQL(Structured Query Language,结构化查询语言)处理数据但很有限
      - python和pandas能执行复杂的分组运算
2. GroupBy机制
      - 分组运算"split-apply-combine"(拆分－应用－合并)
      - groupby
          - grouped为GroupBy对象
            ```
            grouped = df['data1'].groupby(df['key1'])
            grouped.mean()
            ```
            数据(Series)根据分组键进行了聚合,产生了一个新的Series,其索引为key1列中的唯一值
          - 传入多个数组的列表得到具有层次化索引的Series
          - 分组键可以是任何长度适当的数组,但通常位于要处理的数据中
          - 分组键可以是列名,字符串,数字或其他Python对象
          - 任何分组关键词中的缺失值,都会被从结果中除去
      - 对分组进行迭代
          - `for name, group in df.groupby('key1'):...`
          - 多重键元组的第一个元素将会是由键值组成的元组
          - 将数据片段做成字典:`pieces = dict(list(df.groupby('key1')))`
          - 对列分组axis=1
      - 选取一列或列的子集
          - s_grouped=`df.groupby(['key1', 'key2'])[['data2']].mean()`
          - [[]]表示省略Name,dtype
      - 通过字典或Series进行分组
          - 多对一映射,可以存在未使用的分组键
          - `by_column = people.groupby(mapping, axis=1)`
          - ` people.groupby(map_series, axis=1).count()`
      - 通过函数进行分组
          - 将函数跟数组,列表,字典,Series混合使用也不是问题,因为任何东西在内部都会被转换为数组
          - `people.groupby([len, key_list]).min()`
      - 根据索引级别分组
          - 层次化索引数据集最方便的地方就在于它能够根据轴索引的一个级别进行聚合
          - `hier_df.groupby(level='cty', axis=1).count()`
3. 数据聚合
      - 简介
          - 聚合指的是任何能够从数组产生标量值的数据转换过程
          - 可以使用自定义的聚合运算:`grouped.agg(peak_to_peak)`
      - 面向列的多函数应用
          - 默认函数名为列名
          - 传入多组函数并命名`grouped_pct.agg([('foo', 'mean'), ('bar', np.std)])`
          - 自定义一组函数func=['func1','func2',...],agg(func)
          - 不同列应用不同函数使用字典映射,结果产生层次化的列
             ```
              grouped.agg({'tip_pct' : ['min', 'max', 'mean', 'std'],'size':'sum'})
             ```
      - 禁用层次化行索引:as_index=False
4. apply:一般性的“拆分－应用－合并”
      - apply()
          - ```
            def top(df, n=5, column='tip_pct'):
                return df.sort_values(by=column)[-n:]
            tips.groupby(['smoker', 'day']).apply(top, n=1, column='total_bill')
            ```
          - pply的威力很大程度上取决于你的创造力,它只需返回一个pandas对象或标量值即可
      - 禁止分组键:group_keys=False
      - 分位数和桶分析
             ```
             grouped = frame.data2.groupby(quartiles)
             grouped.apply(get_stats).unstack()
             ```
          - cut(),qcut()
          - labels=False,即可只获取分位数编号
5. 示例
      - 特定于分组的值填充缺失值
          - 分组平均值填充` data.groupby(group_key).apply(fill_mean)`
          - 预定义值填充`fill_values = {'East': 0.5, 'West': -1}`
      - 随机采样和排列
      - 分组加权平均数和相关系数
      - 组级别的线性回归
6. 透视表和交叉表
      - 透视表(pivot table)
          - 根据一个或多个键对数据进行聚合,并根据行和列上的分组键将数据分配到各个矩形区域中
          - `tips.pivot_table(['tip_pct', 'size'], index=['time', 'day'],columns='smoker', margins=True,aggfunc='mean', fill_value=0)`
      - 交叉表(crosstab)
          - 用于计算分组频率的特殊透视表
          - `pd.crosstab(data.Nationality, data.Handedness, margins=True)`
####总结
1. 数据处理流程
      - 数据准备:加载,清理,转换,重塑
      - 分析数据:聚合,合并,重塑
2. python万物皆为对象
3. 某些流程或者步骤可以直接定义来重复使用
      - 对象定义emp1=df[].groupby()
      - 字典定义(映射)
      - 函数定义:def...
4. 参数可以是标量,也可以是列表,字典甚至函数,取决于你的创造力

