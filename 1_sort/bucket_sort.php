<?php
/**
 * 简单桶排序
 * 原理就是：
 * 1、先要有足够的桶，排序中最大的数字为桶个数
 * 2、桶按照从小到大的顺序摆放好
 * 而数组正好能满足以上两个要求，因为数组可以设定长度，而下标依次递增
 * 然后排序数字依次对应相同下标的桶，每对应一次，则数组的值加1，然后分析这个数组，将值大于1的数组下标拿出来即可，而下标就是要排序的数字，需要注意值大于1的情况下，需要多次拿出。
 *
 * 时间复杂度O(M+N),是非常快的排序，但是也有很多的局限性,例如适用于排序数字比较小的情况，否则数组太大了太占空间了。
 */
error_reporting(E_ALL ^ E_NOTICE);
$a = [];
//循环输入5个数值不超过10的数字
for ($i = 1; $i <= 5; $i++) {
    echo 'please input number:';
    $num = intval(fgets(STDIN));//获取用户输入，回车分割,必须转为数字
    $a[$num]++;
}
//依次遍历数组$a
for ($i = 0; $i <= 10; $i++) {
    // 不需要，因为后面的语句决定$a[$i]必须大于等于1才会打印，但是加上这个的话更容易理解
    // if($a[$i]==0){
    // 	continue;
    // }
    for ($j = 1; $j <= $a[$i]; $j++) {//由于$a[$i]可能大于1，所以出现这种情况需要多次展示
        echo $i;
    }
}

//书中说不能同时展示名称和分数的排序，但用多维数组也可以实现：
// for ($i = 1; $i <= 5; $i++) {
//     printf("please input name and score:");
//     $input = trim(fgets(STDIN));
//     list($name, $score) = explode(' ', $input);
//     //为了能展示名字，用多维数组来存储
//     $score = intval($score);//需要转为整型
//     $a[$score][]['name'] = $name;
// }
// for ($i = 0; $i <= 10; $i++) {
//     if (count($a[$i]) >= 1) {//如果有值
//         foreach ($a[$i] as $key => $value) {//遍历出来即可
//             echo $i . ' ' . $value['name'] . "\n";
//         }
//     }
// }