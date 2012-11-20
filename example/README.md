这里实现一个简易的使用CUnit进行测试的例子。

要被测试的对象是一个静态库libcompare.a

libcompare.a的实现代码位于src目录中，libcompare.a对外提供的头文件和库文件将分别被复制到include和lib目录中。

src/         libcompare.a的实现代码
include/     libcompare.a对外提供的头文件
lib/         libcompare.a存放的路径
testcase/    libcompare.a的测试用例
