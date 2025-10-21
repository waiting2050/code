**markdown语法aa** // 前后两个*或者__是加粗
*markdown* // 前后一个*是斜体
_markdown_ // 前后都是_只有单独存在才行，左右两边有字符连着不行
***markdown*** // 三个是斜体且加粗

***
// 三个星号是分割线，中间加不加空格都行

- - -
//三个-号是分割线，中间必须有空格

~~markdown~~ // 前后两个~是横线穿过字符串

# markdown // #之后空一格是一级标题
## markdown // 两个#之后空一格是二级标题，最多支持六级标题

markdown
-
// 一段话之后一个-号是二级标题

markdown
=
// 一段话之后=是一级标题


* markdown // *或/或+再一个空格是无序列表，注意不能混着用，不然分属于不同的无序列表

1. markdown // 数字后加.再空一格是有序列表
2. markdown // 因为有序，若将2改为3，实际显示的还是2，只与最开始的序号有关
3. markdown
   * markdown
   * markdown
        * markdown // 在列表下tab缩进四个空格，再用无序列表嵌套
4. markdown
    1. markdown
    2. markdown
        1. markdown // 在列表下tab缩进四个空格，再用无序列表嵌套
5. markdown

* [ ] markdown // *空格[空格]空格 会生成勾选框（未勾选）
* [x] markdown // *空格[x]空格 会生成勾选框（已勾选），x大小写均可

``` cpp
int main()
{
    printf("markdown");
  
    return 0;
}
```
// 将代码用三个```包裹，表示这是一个代码块

这里有一个`markdown()`函数 // 用一对`可以在行内标注一个小的代码块

> markdown // 用一个>空格表示这是一段引用
> > markdown // 引用里还能嵌套引用

mark[down](https://isaac.huijiwiki.com/wiki/%E9%A6%96%E9%A1%B5) // 将字符串用[]括起以后加()，再在里面加上网址，就可以添加上超链接了

m[a][alian]r[k][blian][d][clian]own

[alian]: https://isaac.huijiwiki.com/wiki/%E9%A6%96%E9%A1%B5
[blian]: https://isaac.huijiwiki.com/wiki/%E9%A6%96%E9%A1%B5
[clian]: https://isaac.huijiwiki.com/wiki/%E9%A6%96%E9%A1%B5
// 假如想添加多个链接在一句话，用这种变量代替的方式就更简洁，而且可以复用，eg：
m[a][alian]rkdown
当然直接把链接贴上去也行：https://isaac.huijiwiki.com/wiki/%E9%A6%96%E9%A1%B5

// 生成脚注的方法
markdown[^1]
markdown[^2]

[^1]: 我是脚注
[^2]: 我也是脚注

![图片](https://huiji-public.huijistatic.com/isaac/uploads/0/04/Collectibles_sprite.png)
// 展示图片，[]里是文字说明，与上文的区别是多了个感叹号


| 姓名 | 年龄 | 性别 |
| :----: | ---- | --- |
| 小明 |  18  |  男 |
| 小红hhhhh |  17  | 女  |

// 表格制作，第二行的横杠只有一个也行，但对齐了更美观
// 在横杠左边加冒号表示左对齐，两边都加就是居中对齐

==markdown== // 左右两个等号是高亮

markdown^2^ // 左右两边各一个^表示商标
markdown~2~ // 左右两边各一个~表示下标

$markdown$ // 左右各一个$表示数学公式

$$markdown$$ // 表示数学公式换行且居中

$$
markdown \\
markdown
$$
// 数学公式之间用两个\表示换行

$\frac{mark}{down}$ // 表示分数，前一个{}是分子，后一个{}是分母
$mark^{down}$ // 想在在数学公式里表示上标用一个^就足够了
$mark_{down}$ // 同理下标也是如此
$mark^{do}_{wn}$ // 连在一起用也没有问题
$\sqrt[down]{mark}$ // 前面是开多少次方根（不写默认为2），后面是被开根的数
$\sqrt[down]{\{mark\}}$ // 直接打花括号是会失败的，要在前面加\转义

// 以下是一些常用的数学符号
$\not=$ // 不等于
$\approx=$ // 约等于
$\leq$ // 小于等于
$\geq$ // 大于等于
$\times$ // 乘号
$\div$ // 除号
$\pm$ // 正负号
$\sum$ // 求和符号，一般与上标和下标配合使用
$\prod$ // 累乘符号
$\coprod$ // 累除符号
$\overline{1+2+3=4}$ // 求平均

$$
sin \\
cos \\
90^\circ // circ是圆，加上角标是度数 \\
\int // 定积分 \\
\iint // 双重定积分
$$