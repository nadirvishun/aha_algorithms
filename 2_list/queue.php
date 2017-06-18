<?php
/**
 * 队列
 * 实现功能描述有些麻烦，直接看书吧
 */
error_reporting(E_ALL ^ E_NOTICE);
//初始数组
$data=[6,3,1,7,5,8,9,2,4];
//新数组
$qq=[];
//当数组为空前一直循环
while (count($data)>0) {
	//将第一个数组元素剔除，然后放入新数组中
	$del=array_shift($data);
	if($del!==null){
		array_push($qq, $del);
	}
	//继续剔除第二个数组元素，然后放到自身的最后面
	$append=array_shift($data);
	if($append!==null){
		array_push($data, $append);
	}
}
// var_dump($qq);
echo implode(',', $qq);