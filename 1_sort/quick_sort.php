<?php
/**
 * 快速排序
 * 快速排序的最差时间复杂度与冒泡排序的一致为O(N^2),但平均时间复杂度为O(NlogN)
 * 对于一般的情况来说，是相对最快的排序（当然不能和桶排序比），但是对于已经顺序比较规则的来说，并不一定比插入排序等更快
 * 总的来说还是要根据具体的情况来选择不同的算法才行
 */
error_reporting(E_ALL & ~E_NOTICE);
//输入总个数
echo 'please input total number:';
$num = intval(fgets(STDIN));
$a = [];
//输入名称和分数，中间空格分割
for ($i = 0; $i < $num; $i++) {//下标从0开始
    printf("please input number:");
    $input = fgets(STDIN);
    $a[$i] = intval($input);//必须转为数字,否则按照字符串来排序
}
//开始快速排序
$a = quickSort($a, 0, $num - 1);
//输出名字及分数
for ($i = 0; $i < $num; $i++) {
    echo $a[$i] . ' ';
}
/**
 * 快速排序方法(从小到大)
 */
function quickSort($data, $left, $right)
{
    if ($left > $right || !is_array($data) || empty($data)) {
        return;
    }
    $temp = $data[$left];//基准
    $i = $left;
    $j = $right;
    while ($i != $j) {
        //先从右向左寻找小于基准的
        while ($data[$j] >= $temp && $i < $j) {//如果大于基准，并且$i<$j,则$j减1后继续寻找，否则找到后直接跳出while循环
            $j--;
        }
        //再从做向右找
        while ($data[$i] <= $temp && $i < $j) {//如果小于基准，且$i<$j,则$i加1后继续寻找，否则直接跳出循环
            $i++;
        }
        //上方两个找到后，则交换位置
        if ($i < $j) {
            $t = $data[$i];
            $data[$i] = $data[$j];
            $data[$j] = $t;
        }
    }
    //最后将基准放到中间位置
    $data[$left] = $data[$i];
    $data[$i] = $temp;
    //递归继续处理
    if ($left < $i - 1) {
        $data = quickSort($data, $left, $i - 1);
    }
    if ($right > $i + 1) {
        $data = quickSort($data, $i + 1, $right);
    }
    return $data;
}