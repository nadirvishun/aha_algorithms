<?php
/**
 * 小猫钓鱼，不就是排火车吗
 * 需要两个玩家队列，一个桌面上的栈
 */

/*$playerA=[2,4,1,2,5,6];
$playerB=[3,1,3,5,6,4];*/

//模拟真实扑克的数组,J(11),Q(12),K(13),Joker(14)
$poker=range(1, 13);
$poker=array_merge($poker, $poker, $poker, $poker, array(14,14));//4色+大小王
//洗牌
shuffle($poker);
//依次摸牌
foreach ($poker as $k=>$v) {
    if ($k%2==0) {
        $playerA[]=$v;
    } else {
        $playerB[]=$v;
    }
}
$desk=[];//桌面上的牌
$nowPlayer='playerA';//先手的玩家
while (!empty($playerA) && !empty($playerB)) {//一旦有玩家手中牌空，则跳出
    //先取出当前玩家首张牌
    $card=array_shift(${$nowPlayer});//用可变变量来随时变换当前的玩家
    //判定桌面牌中有没有与玩家出的牌一致的
    $sameKey=array_search($card, $desk);//array_search内部应该还是循环，可参照下方的另一种方法进行优化
    if ($sameKey!==false) {//如果存在一样的
        array_push($desk, $card);//先将牌放入桌面
        $diffNum=count($desk)-$sameKey;//计算需要弹出的个数
        for ($i=0;$i<$diffNum;$i++) {
            $winCard=array_pop($desk);//从桌面栈中弹出赢得牌
            array_push(${$nowPlayer}, $winCard);//将赢的牌收入玩家手中
        }
    } else {//如果没有一致的，则仅仅将牌加入桌面栈中
        array_push($desk, $card);
    }
    //变换玩家
    $nowPlayer=($nowPlayer=='playerA')?'playerB':'playerA';
}

//另一种方法，参考C语言中的示例，用桶的方法,且book数组很小，只需要14个即可
/*$book=[];//定义桶
while (!empty($playerA) && !empty($playerB)) {//一旦有玩家手中牌空，则跳出
    //先取出当前玩家首张牌
    $card=array_shift(${$nowPlayer});//用可变变量来随时变换当前的玩家
    //判定桌面牌中有没有与玩家出的牌一致的
    if (isset($book[$card]) && $book[$card]==1) {//如果在桶中
        array_push(${$nowPlayer}, $card);//将牌直接放入自己手中
        $pop=array_pop($desk);//先从桌面弹出一张
        while ($pop!=$card) {//如果不相等，继续弹
            array_push(${$nowPlayer}, $pop);
            $book[$pop]=0;//弹出的桶中置0
            $pop= array_pop($desk);//继续弹
        }
        //当相等时
        array_push(${$nowPlayer}, $pop);
        $book[$pop]=0;//弹出的桶中置0
    } else {//如果没有一致的，则仅仅将牌加入桌面栈中
        array_push($desk, $card);
        $book[$card]=1;//将桶置1
    }
    //变换玩家
    $nowPlayer=($nowPlayer=='playerA')?'playerB':'playerA';
}*/

//输出结果
$winner=empty($playerA)?'playerB':'playerA';
echo 'winner is:'.$winner."\n";
echo 'playerA has cards:'.implode(',', $playerA)."\n";
echo 'playerB has cards:'.implode(',', $playerB)."\n";
echo 'desk has cards:'.implode(',', $desk)."\n";
