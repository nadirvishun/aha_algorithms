<?php
/**
 * 栈
 * 检测输入的字符串是否为回文字符串（正序读倒序读都是同样的）
 */
error_reporting(E_ALL ^ E_NOTICE);

//输入字符串
echo "please input a string:";
$str=trim(fgets(STDIN));

//查看输入的字符个数
$len=strlen($str);
if($len <= 0){
	echo 'can not input empty!';
	exit;
}

//将字符串转为数组，方便直观的展示操作,当然也可以直接用字符串的裁切
$data=str_split($str);

//取中间值，这里有两种情况一种是“abcba”，一种是"abba"，也就是一个是奇数一个是偶数
$mid=floor($len/2)-1;//需要注意与C的不同
if($len%2==0){
	$next=$mid+1;
}else{
	$next=$mid+2;
}

//先将$mid之前（包含自身）的入栈在left数组中
$left=[];
for($i=0;$i<=$mid;$i++){
	$left[$i]=$data[$i];
}

//将$mid之后的依次和前面的进行比较
$is=true;
for($j=$next;$j<$len;$j++){
	$pop=array_pop($left);//left数组出栈
	if($data[$j]!=$pop){
		$is=false;
		break;
	}
}
if($is){
	echo 'YES!';
}else{
	echo "NO!";
}
