# 包装类型 不变类
1. public final class Integer
2. 比较需用.equre();不能用等于
3. .toUnsignedInt();处理无符号整形
## Integer
```java
Integer n = Integer.valueOf(100);//初始化方法
System.out.println(Integer.toHexString(255));//ff
System.out.println(Integer.toBinaryString(255));//1111 1111
```
# Random 伪随机数 需要指定随机种子（默认系统时间戳）
# SecureRandom 真随机数（安全随机数）不需要指定随机种子
# BigInteger 大整数
# BigDecimal 精准浮点数
# var 相当于C++ auto var b = new Person();
# enumerate 枚举
```java
enum Weekday {
    SUN, MON, TUE,WED, THU, FRI,SAT;
}
/**
 * 构造方法要设置成私有private
 * 字段为final修饰
 */
enum Weekday {
    SUN("星期日"), MON("星期一"), TUE("星期二"),
    WED("星期三"), THU("星期四"), FRI("星期五"),
    SAT("星期六");
    private final String dayValue;

    private Weekday(String dayValue) {
        this.dayValue = dayValue;
    }
    @Override
    public String toString() {
        return this.dayValue;
    }
}
```
# 字符串相关
## String 值不可更改
## StringBuilder 可以添加(append)插入(insert)和删除(delete)
## StringJoiner 以某字符串进行分割符号 内部实现 StringBuilder
```java
StringBuilder stringBuilder = new StringBuilder("Home ")
// 分隔符 开头 结尾
String[] fields = {"name","age","address"}
StringJoiner joiner = new StringJoiner(", ", stringBuilder.toString(), "!!!");
for (var str : fields) {
    joiner.add(str);
}
joiner.toString();//="Home name, age, address!!!";
```
# Inteface 接口
```java
interface Interface {
    void cat();
    void run();
    //定义一个默认方法，可以不必重写这个方法
    default void abs(int a) {
        System.out.println("Interface Hello");
    }
}
```
# Java具有多态性，
```java
Person p = new Student();//其中Student继承Person并重写了Person的print方法
p.print();//执行的是Student的print方法 
/*在C++中要想实现多态需要生命函数为virtual（虚函数）*/
```
# java异常
## 继承关系图
                     ┌───────────┐
                     │  Object   │
                     └───────────┘
                           ▲
                           │
                     ┌───────────┐
                     │ Throwable │
                     └───────────┘
                           ▲
                 ┌─────────┴─────────┐
                 │                   │
           ┌───────────┐       ┌───────────┐
           │   Error   │       │ Exception │
           └───────────┘       └───────────┘
                 ▲                   ▲
         ┌───────┘              ┌────┴──────────┐
         │                      │               │
┌─────────────────┐    ┌─────────────────┐┌───────────┐
│OutOfMemoryError │... │RuntimeException ││IOException│...
└─────────────────┘    └─────────────────┘└───────────┘
                                ▲
                    ┌───────────┴─────────────┐
                    │                         │
         ┌─────────────────────┐ ┌─────────────────────────┐
         │NullPointerException │ │IllegalArgumentException │...
         └─────────────────────┘ └─────────────────────────┘
## Error 严重错误
1. OutOfMemoryError：内存耗尽
2. NoClassDefFoundError：无法加载某个Class
3. StackOverflowError：栈溢出
## Exception 运行时错误，可以被捕获并处理。
1. NumberFormatException：数值类型的格式错误
2. FileNotFoundException：未找到文件
3. SocketException：读取网络失败
4. NullPointerException：对某个null的对象调用方法或字段
5. IndexOutOfBoundsException：数组索引越界
### Exception 分为RuntimeException和非RuntimeException
***Java规定：***
必须捕获的异常，包括Exception及其子类，但不包括RuntimeException及其子类，这种类型的异常称为Checked Exception。不需要捕获的异常，包括Error及其子类，RuntimeException及其子类。
## 捕获异常
定义函数可能会抛出UnsupportedEncodingException异常
public void func() throws UnsupportedEncodingException{}
```java
try{
    //
}catch (IOException | NumberFormatException e) { // IOException或NumberFormatException
        System.out.println("Bad input");
} catch (Exception e) {//注意父类要写在后面，否则会捕获父类，无法捕获子类无法捕获
        System.out.println("Unknown error");
} finally {
    //不论程序如何运行都执行本语句
}
```
## 自定义异常类型
1. 一般创建一个BaseException继承自RuntimeException类
2. 自定义的异常类继承自BaseException类
# Assertion 断言
是一种调试方法，只能用于程序开发阶段，启用断言需要命令行加参数-enableassertions(可简写为-ea)
```java
public static void main(String[] args) {
    double x = Math.abs(-123.45);
    assert x >= 0;//如果x<0则抛出AssertionError异常，无法被程序捕获，
    System.out.println(x);
}
```
# Logger 日志类
## 日志级别
1. SEVERE 严重
2. WARNING 警告
3. INFO (Default:默认级别)
4. CONFIG
5. FINE
6. FINER
7. FINEST
## 使用
启动时传递参数-Djava.util.logging.config.file=<config-file-name>来更改默认配置
```java
Logger log = Logger.getGlobal();
log.info("info");
```
# Commons Logging是一个第三方日志库
# Commons Logging加Log4j
# SLF4J加Logback
# 反射
## 获取一个class的Class实例
1. Class cls = Student.class;
2. Student stu = new Student();Class cls = stu.getClass();
3. Class cls = Class.forName("java.lang.String");//通过完整类名获取
## 总结
1. Java的反射API提供的Field类封装了字段的所有信息：
2. 通过Class实例的方法可以获取Field实例：getField()***[public]***，getFields()，getDeclaredField()***[private]***，getDeclaredFields()；
3. 通过Field实例可以获取字段信息：getName()，getType()，getModifiers()；
4. 通过Field实例可以读取或设置某个对象的字段，如果存在访问限制，要首先调用setAccessible(true)来访问非public字段。
5. 通过反射读写字段是一种非常规方法，它会破坏对象的封装。
## Java的反射API提供的Method对象封装了方法的所有信息：
1. 通过Class实例的方法可以获取Method实例：getMethod()，getMethods()，getDeclaredMethod()，getDeclaredMethods()；
2. 通过Method实例可以获取方法信息：getName()，getReturnType()，getParameterTypes()，getModifiers()；
3. 通过Method实例可以调用某个对象的方法：Object invoke(Object instance, Object... parameters)；
4. 通过设置setAccessible(true)来访问非public方法；
## Constructor对象封装了构造方法的所有信息；
1. 通过Class实例的方法可以获取Constructor实例：getConstructor()，getConstructors()，getDeclaredConstructor()，getDeclaredConstructors()；
2. 通过Constructor实例可以创建一个实例对象：newInstance(Object... parameters); 通过设置setAccessible(true)来访问非public构造方法。
## 通过Class对象可以获取继承关系：
1. Class getSuperclass()：获取父类类型；
2. Class[] getInterfaces()：获取当前类实现的所有接口。
3. 通过Class对象的isAssignableFrom()方法可以判断一个向上转型是否可以实现。
4. 当我们判断一个实例是否是某个类型时，正常情况下，使用instanceof操作符：
# 注解
## 由编译器使用的注解 不会被编译到class文件
1. @Override：让编译器检查该方法是否正确地实现了覆写。
2. @SuppressWarnings：告诉编译器忽略此处代码产生的警告。
## 由工具处理.class文件使用的注解
比如有些工具会在加载class的时候，对class做动态修改，实现一些特殊的功能。这类注解会被编译进入.class文件，但加载结束后并不会存在于内存中。这类注解只被一些底层库使用，一般我们不必自己处理。
## 在程序运行期能够读取的注解
## 使用@interface定义一个注解
## 元注解 用于修饰注解
使用@Target可以定义Annotation能够被应用于源码的哪些位置：
1. 类或接口：ElementType.TYPE；
2. 字段：ElementType.FIELD；
3. 方法：ElementType.METHOD；
4. 构造方法：ElementType.CONSTRUCTOR；
5. 方法参数：ElementType.PARAMETER。
另一个重要的元注解@Retention定义了Annotation的生命周期：
1. 仅编译期：RetentionPolicy.SOURCE；
2. 仅class文件：RetentionPolicy.CLASS；
3. 运行期：RetentionPolicy.RUNTIME。
```java
// @Target({
//     ElementType.METHOD,
//     ElementType.FIELD
// })
@Retention(RetentionPolicy.RUNTIME)//生命周期为运行期
@Target(ElementType.METHOD)//定义注解Report能够用在方法上
public @interface Report {
    int type() default 0;
    String level() default "info";
    String value() default "";//最常用的参数应该指定为value
}
```
# 泛型 
泛型是一种代码模板
```java
class Pair<T> {
    private T first;
    private T second;
    Pair(T first, T second) {
        this.first = first;
        this.second = second;
    }
    //...
}
```
## 注意事项
1. T实际上是Object类所以不能为int等基本数据类型
2. new T(); 这种写法是错误的
3. Pair<? super Integer> 类型只能是Integer类及其父类 只能写不能读
4. Pair<? extend Number> 类型只能是Number类及其子类  只能读不能写
5. <? extends T>允许调用读方法T get()获取T的引用，但不允许调用写方法set(T)传入T的引用（传入null除外）；
6. <? super T>允许调用写方法set(T)传入T的引用，但不允许调用读方法T get()获取T的引用（获取Object除外）。
```java
// 把src的每个元素复制到dest中: dest只写 src只读
public static <T> void copy(List<? super T> dest, List<? extends T> src) {
    for (int i=0; i<src.size(); i++) {
        T t = src.get(i);
        dest.add(t);
    }
}
```
## PECS(Prudecer extents Consumer super)原则
1. 生产者用extents 只读不写
2. 消费者用super 只写不读
## 无限定通配符<?>很少使用，可以用<T>替换，同时它是所有<T>类型的超类。
不可读也不可写，常用于一些判断，可以使用<T>替换
# 集合
1. add 添加元素
2. contains 判断是否有该元素
3. size 存放元素个数
5. remove 移除
6. clear 清空
7. peek 窥视
8. poll 轮询
9. offer 提供
10. element 元素
11. isEmpty 是否为空
键值需要重写equals与hashCode方法 需要排序是需要继承Comparable接口或指定Comparable
Objects.hash(Object... values);
Objects.equals(this.text, msg.text) && this.sequence == msg.sequence&&
# Map
## HashMap 无序
```java 
Map<String, Integer> map = new HashMap<>();
```
## TreeMap 关键字有序
```java
Map<String, Integer> map = new TreeMap<>();
```
# Set
## HashMap 无序
```java 
Set<String> set = new HashSet<>();
```
## TreeMap 关键字有序
```java
Set<String> set = new TreeSet<>();
```
# Queue
## Queue<String> stringQueue = new LinkedList<>();
1. 通过add()/offer()方法将元素添加到队尾；
2. 通过remove()/poll()从队首获取元素并删除；
3. 通过element()/peek()从队首获取元素但不删除。
4. ***注意：add,remove,element失败时会抛出异常，offer,poll,peek失败是会返回flase或null***
***要避免把null添加到队列。***
# PriorityQueue 有限队列，优先级高的先出队列
## PriorityQueue<User> userQueue = new PriorityQueue<>(new UserComparator());
1. 实现PriorityQueue的关键在于提供的UserComparator对象，它负责比较两个元素的大小***较小的在前***
2. PriorityQueue实现了一个优先队列：从队首获取元素时，总是获取优先级最高的元素。
3. PriorityQueue默认按元素比较的顺序排序（必须实现Comparable接口），也可以通过Comparator自定义排序算法（元素就不必实现Comparable接口）。
# Deque 双端队列
|                 |Queue|Deque|
|-----------------|---------------------|---------------------|
|添加元素到队尾    |add(E e) / offer(E e)|	addLast(E e) / offerLast(E e)|
|取队首元素并删除  |E remove() / E poll()|	E removeFirst() / E pollFirst()|
|取队首元素但不删除|E element() / E peek()|	E getFirst() / E peekFirst()|
|添加元素到队首    |无                   |	addFirst(E e) / offerFirst(E e)|
|取队尾元素并删除  |无                   |	E removeLast() / E pollLast()|
|取队尾元素但不删除|无                   |	E getLast() / E peekLast()|
# Stack 栈 ，使用Deque来实现，不可以用Stack
1. Deque<String> stringDeque = new LinkedList<>();
2. stringDeque.pop();//出栈 返回栈顶元素
3. stringDeque.push();//入栈
4. stringDeque.peek();//查看栈顶元素
# Collections
* Collections.emptyList()/Collections.emptySet()/Collections.emptyMap() 创建final（不可变）空列表/集合/map
* Collections.singletonList("AAA")， 创建单元素
* List.of("AAA") 创建的集合都是不可变集合
* Collections.sort(list);//对可可变集合进行排序
* Collections.shuffle(list);//洗牌
* Collections.unmodifiableList(); 返回 封装成不可变集合
# 日期时间
## 本地日期和时间：
1. LocalDateTime(日期与时间)
2. LocalDate(日期)
3. LocalTime(时间) 
4. LocalDate.plusDays(n) 加n天 
5. LocalDate.minusHours(n) 减n小时 
6. 调整年：withYear()
7. 调整月：withMonth()
8. 调整日：withDayOfMonth()
9. 调整时：withHour()
10. 调整分：withMinute()
11. 调整秒：withSecond()
12. isBefore isAfter 比较两个日期
```java
LocalDate date = LocalDate.now();返回当前日期
LocalDateTime dt = LocalDateTime.now();
LocalTime time = dt.toLoaclTime();//转成时间
LocalDate date = LocalDate.of(2020.2.2);//指定日期
LocalDateTime dt = LocalDateTime.parse("2019-11-19T15:16:17");//按照ISO 8601格式设置时间
```
## DateTimeFormatter 自定义日期输出格式
```java
// 自定义格式化:
DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
System.out.println(dtf.format(LocalDateTime.now()));
// 用自定义格式解析:
LocalDateTime dt2 = LocalDateTime.parse("2019/11/30 15:16:17", dtf);
System.out.println(dt2);
```
## 带时区的日期和时间：ZonedDateTime；
1. ZonedDateTime.now();
2. ZonedDateTime.now(ZoneID.of("America/New_York"));
3. LocalDateTime.now().atZone(ZoneId.of("Asia/Shanghai"));
4. LocalDateTime.now().atZone(ZoneId.SystemDefault());
5. withZoneSameInstant(ZoneId.of());转换时区
```java
LocalDateTime localDateTime = LocalDateTime.now();//获取本地时间
ZonedDateTime zonedDateTime = localDateTime.atZone(ZoneId.systemDefault());//为本地时间设置时区

ZonedDateTime zTime = ZonedDateTime.now(ZoneId.of("Asia/Shanghai"));//获取时间
ZonedDateTime nTime = zTime.withZoneSameInstant(ZoneId.of("America/New_York"));//转换时区
LocalDateTime lTime = zTime.toLocalDateTime();转换成本地时间
```
## 时刻：Instant 表示高精度时间戳
1. getEpochSecond();//输出毫秒
2. toEpochMilli();//纳秒
3. atZone(ZoneId.systemDefault());//转换成ZonedDateTime
```java
Instant now = Instant.now();//获取当前时间 最小为纳秒级别
Instant now = Instant.ofEpochSecond(1988568760);//以指定时间 从1970-01-01T00:00:00Z 所经过的秒数 创建
System.out.println(now.getEpochSecond());//获取秒数
System.out.println(now.toEpochMilli());//获取毫秒
ZonedDateTime time = now.atZone(ZoneId.systemDefault());//转换成ZonedDateTime
System.out.println(time);
```
## 时区：ZoneId，ZoneOffset；
## 时间间隔：Duration和Period。
```java
Duration d = Duration.between(LoaclDateTime time1, LocalDateTime time2);//PT1235H10M30S 1235小时10分30秒
Period p = tim21.until(time2);//P1M2D 1个月2天
```
## 旧A时间API(Date/Calendar)转换成新的API
1. 通过toInstant()转为Instant对象
2. 通过Instant在转成ZonedDateTime
## 新API转旧API
1. 通过long行时间戳进行转换
```java
// ZonedDateTime -> long:
ZonedDateTime zdt = ZonedDateTime.now();
long ts = zdt.toEpochSecond() * 1000;//转成毫秒级时间戳

// long -> Date:
Date date = new Date(ts);

// long -> Calendar:
Calendar calendar = Calendar.getInstance();
calendar.clear();
//新的ZoneId转为旧的TimeZone需要借助ZoneId.getId()返回String实现
calendar.setTimeZone(TimeZone.getTimeZone(zdt.getZone().getId()));
calendar.setTimeInMillis(zdt.toEpochSecond() * 1000);
```
***在数据库中存储时间尽量存储Instant时间戳（在数据库中存储为BIGINT类型）然后需要显示时在转成指定格式***
# JUnit 测试
```java
@Test
public void testFact() {//测试结果是否正确
    assertEquals(1, Factorial.fact(0));
    assertEquals(1, Factorial.fact(1));
    assertEquals(2, Factorial.fact(2));
    assertEquals(6, Factorial.fact(3));
    assertEquals(3628800, Factorial.fact(10));//测试结果是不是3628800
    assertEquals(2432902008176640000L, Factorial.fact(20));
}
@Test(expected = IllegalArgumentException.class)
public void testNegative() {//测试是否抛出IllegalArgumentException异常
    Factorial.fact(-1);
    Factorial.fact(-2);
    Factorial.fact(-3);
    Factorial.fact(-5000);
}
@Test(expected = ArithmeticException.class)
public void testLargeInput() {
    Factorial.fact(21);
    Factorial.fact(22);
    Factorial.fact(232);
    Factorial.fact(5000);
}
```
# 正则表达式regex
## 字符匹配
1. . 匹配任意一个字符
2. \d 匹配一个数字
3. \D 匹配一个非数字
4. \w 匹配字符数字下划线_
5. \W 匹配\w不能匹配的字符
6. \s 匹配一个空格或者一个制表符【\t】
7. \S 匹配\s不能匹配的字符
9. \u548c 指定Unicode字符[和：548c]
## 数量匹配
1. * [0,) 0个至多个
2. + [1,) 
3. ? [0,1]
4. {n} [n]
5. {n,m} [n,m]
6. {n,} [n,)
## 特殊匹配
1. ^ 括号外 代表开头
2. $ 结尾
3. [123456] 括号中的任意一个
4. [1-9] ->[123456789]
5. [1-9a-zA-Z] 匹配数字和大小写字母
6. ^(中括号内) 非 [^1-9] 匹配除了1-9的数字之外的
7. | 或 java|php 匹配java或者php
8. learn\\s(java|php|go) 匹配learn java/learn php/learn go
9. learn\\s((j|J)ava|(P|p)hp|(G|g)o) 括号可以嵌套使用
## 分组匹配
```java
Pattern pattern = Pattern.compile("(\\d{3,4})\\-(\\d{7,8})");
Matcher matcher = pattern.matcher("0370-5972337");
System.out.println(matcher);
if (matcher.matches()) {
    String whole = matcher.group(0);//0代表整合匹配
    String area = matcher.group(1);//1待变第一个组():(\\d{3,4})
    String tel = matcher.group(2);
    System.out.println(whole);
    System.out.println(area);
    System.out.println(tel);
}
```
***例如 \d* 匹配 ***
## 示例
```java
/**
* 通过Pattern陪匹配效率高因为String每一次匹配都会创建一个Patten对象
* 创建一次Pattern可以实现一次创建多次匹配
*/
Pattern pattern = Pattern.compile("(\\d{3,4})\\-(\\d{7,8})");//创建一个Pattern对象
pattern.matcher("010-12345678").matches(); // true 匹配
String.matches(String regex);//直接使用String提供的方法 内部是通过Pattern实现的
"2020".matches("20\\d\\d");// true, \d 代表一个数字
```
## 非贪婪匹配 
默认为贪婪匹配，尽可能匹配多的字符串
1. (\d+)(0*) 使用默认（贪婪）前面的数字都被(\d+)匹配 12350000  (\d+?)匹配12350000 (0*)匹配
2. (\d+?)(0*) 加?代表使用非贪婪模式 12350000  (\d+?)匹配1235 (0*)匹配0000
## 搜索和替换
1. "a, b ;; c".split("[\\,\\;\\s]+"); // { "a", "b", "c" }
# 编码与算法
## URL编码
## 编码规则
1. 如果字符是A~Z，a~z，0~9以及-、_、.、*，则保持不变；
2. 如果是其他字符，先转换为UTF-8编码，然后对每个字节以%XX表示。
- 例如 字符**中**的UTF-8编码是0xe4b8ad，因此，它的URL编码是%E4%B8%AD。URL编码总是大写
- 在Java中使用URLEncoder对字符出进行URL编码 会将空格编码成+
- 使用URLDecoder进行解码
```java
String encoder = URLEncoder.encode("中文! ", StandardCharsets.UTF_8);//编码 ！随时ASCII码但是也编码成了%21
System.out.println(encoder);//%E4%B8%AD%E6%96%87%21+
String decode = URLDecoder.decode(encoder,StandardCharsets.UTF_8);//解码
System.out.println(decode);//中文! 
```
**注意：URL编码只是编码算法不是加密算法**
## Base64编码
1. 对二进制进行编码表示成文本格式
2. 它的原理是把3字节的二进制数据按6bit一组，用4个int整数表示，然后查表，把int整数用索引对应到字符，得到编码后的字符串。
3. 6位整数的范围总是0~63，所以，能用64个字符表示：字符A~Z对应索引0~25，字符a~z对应索引26~51，字符0~9对应索引52~61，最后两个索引62、63分别用字符+和/表示。
4. 过高长度不是3的整数倍则在后面加一个或者两个0x00编码后在尾部加一个或者两个=
5. Base64编码会出现+/=所以不适合放入URL中一种针对URL的Base64编码可以在URL中使用的Base64编码，它仅仅是把+变成-，/变成_
```java
byte[] data = new byte[]{(byte) 0xe4, (byte) 0xb8, (byte) 0xad, (byte)0x01, (byte)0x02, (byte)0x7f, (byte)0x00};
//编码
String base64Coding = Base64.getEncoder().encodeToString(data);
//withoutPadding()去除末尾的=
String base64Coding2 = Base64.getEncoder().withoutPadding().encodeToString(data);
//针对URl的Base64编码 只是将编码后的+变成-，/变成_
String base64Url = Base64.getUrlEncoder().encodeToString(data);
System.out.println(base64Coding);//5LitAQJ/AA==
System.out.println(base64Coding2);//5LitAQJ/AA
System.out.println(base64Url);//5LitAQJ_AA==
//解码，末尾无=也能解码出来
byte[] decode = Base64.getDecoder().decode(base64Coding2);
System.out.println(Arrays.toString(decode));//[-28, -72, -83, 1, 2, 127, 0]
//解URL格式的Base64码
byte[] urlDecode = Base64.getUrlDecoder().decode(base64Url);
System.out.println(Arrays.toString(urlDecode));//[-28, -72, -83, 1, 2, 127, 0]
```
1. URL编码和Base64编码都是编码算法，它们不是加密算法；
2. URL编码的目的是把任意文本数据编码为%前缀表示的文本，便于浏览器和服务器处理；
3. Base64编码的目的是把任意二进制数据编码为文本，但编码后数据量会增加1/3。
## 哈希算法
安全的哈希算法时碰撞概率低，很难通过哈希值逆推出原始值
### 作用
1. 对任意一组输入数据进行计算，得到一个固定长度的输出摘要
2. 因为相同的输入永远会得到相同的输出，因此，如果输入被修改了，得到的输出就会不同。就可对文件进行校验
3. 存储密码时存储的时计算后的哈希值，而不是明文密码， 当输入密码的哈希值与存储的哈希值一致代表密码正确
### 特点
1. 相同输入一点过得相同输出
2. 不同输入大概率得到不同输出
3. 如果哈希值不同则说明两个对象一定不同，哈希值相同则不一定还需equals()方法进行比较
### 哈希碰撞
1. 碰撞不可避免
2. 一个安全的哈希算法必须满足 碰撞概率低，不能猜测输出(很难通过输出推出输入的才是安全的)
3. 哈希算法的输出长度越长，碰撞的概率就越低，算法也就约安全
### 常见的哈希算法
1. MD5         128bits
2. SHA-1       160bits
3. RipeMD-160  160bits
4. SHA-256     256bits
5. SHA-512     512bits
### 彩虹表
存储常用的指令和对应的哈希值
这样可有通过查表的形式判断出密码，当然前提条件是你的密码在彩虹表中
### 加盐处理
用于抵御彩虹表攻击，就是在密码后加一个随机数，digest = md5(salt+inputPassword)
### BouncyCastle 哈希算法和加密算法的第三方库
1. BouncyCastle是一个开源的第三方算法提供商；
2. BouncyCastle提供了很多Java标准库没有提供的哈希算法和加密算法；
3. 使用第三方算法前需要通过Security.addProvider()注册。
[BouncyCastle](https://www.bouncycastle.org/latest_releases.html)
```java
MessageDigest md5Digest = MessageDigest.getInstance("MD5");
md5Digest.update("Hello".getBytes("UTF-8"));
md5Digest.update("World".getBytes("UTF-8"));

MessageDigest shaDigest = MessageDigest.getInstance("SHA-1");
shaDigest.update("Hello".getBytes("UTF-8"));
shaDigest.update("World".getBytes("UTF-8"));

byte[] md5Result = md5Digest.digest();//68e109f0f40ca72a15e05cc22786f8e6
byte[] shaResult = shaDigest.digest();//db8ac1c259eb89d4a131b253bacfca5f319d54f2
System.out.println(new BigInteger(1, md5Result).toString(16));//将byte合成一个大整数并转成16进制输出
System.out.println(new BigInteger(1, shaResult).toString(16));
/*----------------------------------------------------------*/
// 注册BouncyCastle:
Security.addProvider(new BouncyCastleProvider());
// 按名称正常调用:
MessageDigest md = MessageDigest.getInstance("RipeMD160");
md.update("HelloWorld".getBytes("UTF-8"));
byte[] result = md.digest();
System.out.println(new BigInteger(1, result).toString(16));
```
### Hmac算法 即加盐处理的算法
#### HmacMD5可以看作带有一个安全的key的MD5。使用HmacMD5而不是用MD5加salt，有如下好处：
1. HmacMD5使用的key长度是64字节，更安全；
2. Hmac是标准算法，同样适用于SHA-1等其他哈希算法；
3. Hmac输出和原有的哈希算法长度一致。
#### 使用
使用时需要指定key，我们不会自己指定key，而是通过Java标准库的KeyGenerator生成一个安全的随机的key
```java
KeyGenerator keyGenerator = KeyGenerator.getInstance("HmacMD5");
SecretKey key = keyGenerator.generateKey();//获取key
byte[] sKey = key.getEncoded();//可以数组 随哈希值一起保存到数据库中 new SecretKeySpec(hkey, "HmacMD5")。
System.out.println(new BigInteger(1, sKey).toString(16));
Mac mac = Mac.getInstance("HmacMD5");
mac.init(key);//设置key
mac.update("HelloWorld".getBytes());
byte[] result = mac.doFinal();//获取计算后的哈希值 保存于数据库中与sKey结合进行校验信息
System.out.println(new BigInteger(1, result).toString(16));
//校验
SecretKey key = new SecretKey(byte[] sKey, "HmacMD5");//通过sKey获取key
```
### 对称加密算法
对称加密算法就是传统的用一个密码进行加密和解密
#### 使用AES加密
1. 根据算法名称/工作模式/填充模式获取Cipher实例；
2. 根据算法名称初始化一个SecretKey实例，密钥必须是指定长度；
3. 使用SerectKey初始化Cipher实例，并设置加密或解密模式；
4. 传入明文或密文，获得密文或明文。
```java
//解密
private static byte[] decrypt(byte[] key, byte[] encrypted) throws Exception {
    Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");//ECB工作模式需要128位（16字节）密匙
    SecretKey keySpec = new SecretKeySpec(key, "AES");
    cipher.init(Cipher.DECRYPT_MODE, keySpec);//
    return cipher.doFinal(encrypted);
}
//加密
private static byte[] encrypt(byte[] key, byte[] bytes) throws Exception {
    Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
    SecretKey keySpec = new SecretKeySpec(key, "AES");
    cipher.init(Cipher.ENCRYPT_MODE, keySpec);//
    return cipher.doFinal(bytes);
}


```