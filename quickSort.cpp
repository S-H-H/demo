#include <iostream>
#include <cstdio>
using namesapce std;

// 产生[a,b]之间的随机整数
int RandomInRange(a,b)
{	
	return rand()%(b-a+1) + a; 
}

//比选择数字小的数字移到数组的左边，比选择的数字大的数字移动到数组的右边
int Partition(int data[],int length,int start,int end)
{
	if(data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new exception("Invalid Parameters");

	int index = RandomInRange(start,end);
	Swap(&data[index],&data[end]);//将基准数移到最后一个元素

	int small = start - 1;
	for(index = start; index < end; ++index)
	{
		if(data[index] < data[end])
		{
			++small;
			if(small != index)
				Swap(&data[index],&data[small]);
		}
	}

	++small;
	Swap(&data[index],&data[end]);//将基准数换到原来的位置
	//位于基准数的左边都小于基准数右边

	return index；//返回基准数的位置
}

void QiuckSort(int data[],int length,int start,int end)
{
	if(start == end)
		return ;
	int index = Partition(data,length,start,end);
	if(index > start)
		QiuckSort(data,length,start,index - 1);//比较基准左边的元素
	if(index < end)
		QiuckSort(data,length,index + 1,end);//计较基准值右边的元素
}