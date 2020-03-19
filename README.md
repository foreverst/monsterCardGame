# monsterCardGame
一款基于命令行下的玩家操作怪兽卡牌对战游戏



一款交易卡牌游戏，目标是通过
将生命点降低为零。
________________________________________

了解卡：
召唤怪物卡来攻击对手的生命点并捍卫自己的生命。他们
通常是橙色（效果）或黄色（正常），但是还有许多其他颜色。
怪物的等级介于1到12之间（由顶部的星星表示），以及
右上角的符号表示属性。攻击和防御统计数据列为
底部是ATK和DEF。
您将实现：
怪兽卡：（节点结构）
a。名称
b。攻击点 –从生命点中获得的点数
C。防御点 –保持后续攻击的点数
d。类型 -怪物类型为ATK或DEF得分提供额外的得分
实施方式：
每个玩家都可以从一组纸牌（套牌）开始：
a。玩家分别添加卡片
b。玩家获得一组预定义的卡
2.玩家可以参加战斗
a。玩家以8000点生命值开始
b。投币看谁先去玩家1或玩家2
C。每个玩家选择5卡从牌组到各自手中
i。玩家只能从牌组顶部选择
d。每位玩家将自己选择的一张牌放入防御模式（队列）
________________________________________

e。每位玩家将自己选择的一张牌放入攻击模式（队列）
F。每个玩家将从一个队列中选择激活一张卡
i。如果一个玩家激活了攻击卡，而另一个则激活了防御
	卡
1.新生命点=生命点-（ATK-DEF）
ii。如果双方都选择防守
1.卡片被丢弃–不会获得生命点
iii。如果双方都选择进攻
1.攻击力更大的人获胜
2.新生命点=生命点-（ATK-ATK）
G。第一轮之后
i。5 cards should be in the players hand(array) at all times retrieved from the deck(stack) 
ii。另外两张卡处于攻击和防御模式（队列）
iii。卡必须在队列模式下激活
3.当玩家没有生命点时，战斗结束
4.玩家可以交易卡：
可以从任何玩家牌组中添加和删除卡。
输出示例：
从以下选项中选择一个：
1.创建玩家
2.将卡添加到特定玩家
3.与其他玩家交易卡
4.与其他玩家对战
输入4
第1轮：
玩家1在ATK模式中选择Cyber Dragon
玩家2在DEF模式中选择黑暗魔术师
玩家2损失0点生命
玩家1：8000 LP
玩家2：8000 LP
第2轮：....


•选项1的玩家创建应为两个玩家提供30张卡组
•选项2，如果某位玩家想要向其30张牌堆中添加更多特定的牌
注意：菜单中的选项1必须由玩家运行在开始交易或争斗前。
•您将有两个类：堆栈类和队列类。
• main.cpp将实现上面的菜单。
