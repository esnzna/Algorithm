//y总代码
void quick_sort(int q[], int l, int r)
{
    //递归的终止情况
    if (l >= r) return;

    //第一步：分成子问题
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        //do i ++ ; while (q[i] < x);
        //do j -- ; while (q[j] > x);
        while(q[++i]<x);
        while(q[--j]>x);
        if (i < j) swap(q[i], q[j]);
    }
    //第二步：递归处理子问题
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
    //第三步：子问题合并.快排这一步不需要操作，但归并排序的核心在这一步骤
}

//y总代码，把j换成i的时候
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r + 1 >> 1];//注意是向上取整,因为向下取整可能使得x取到q[l]
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, i - 1), quick_sort(q, i, r);//不用q[l..i],q[i+1..r]划分的道理和分析4中j的情况一样
}



//网友改，可用于没有do while 和没有++运算符的语言如js，可以通过
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int x = q[l + r >> 1], i = l,  j = r;
    while (1) {
        while (q[i] < x) i = i + 1;
        while (q[j] > x) j = j - 1;
        if (i >= j) break;
        swap(q[i], q[j]);
        i = i + 1;
        j = j - 1;
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}










//******************以下代码不能无法全部通过acwing的全部测试用例******************

//这个算法对于所有数都相等时，可能会超时；算法思想类似于快慢指针；似乎可以解决第k大的数的问题
void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int x = q[l], j = l;
    for (int i = l + 1; i <= r; i ++ ) 
        if (q[i] < x) swap(q[ ++ j], q[i]);

    swap(q[l], q[j]);
    quick_sort(q, l, j - 1);
    quick_sort(q, j + 1, r);
}





//此种方法只能选取左或右边的结点的值为划分值；不能随机划分；所以会出现超时的情况
void quick_sort(int *arr,int begin,int end)
{
	//如果区间不只一个数
	if(begin < end)
	{
		int temp = arr[begin]; //将区间的第一个数作为基准数
		int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
		int j = end; //从右到左进行查找时的“指针”，指示当前右位置
		//不重复遍历
		while(i < j)
		{
			//当右边的数大于基准数时，略过，继续向左查找
			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
			while(i<j && arr[j] > temp)
				j--;
			//将右边小于等于基准元素的数填入右边相应位置
			arr[i] = arr[j];
			//当左边的数小于等于基准数时，略过，继续向右查找
			//(重复的基准元素集合到左区间)
			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
			while(i<j && arr[i] <= temp)
				i++;
			//将左边大于基准元素的数填入左边相应位置
			arr[j] = arr[i];
		}
		//将基准元素填入相应位置
		arr[i] = temp;
		//此时的i即为基准元素的位置
		//对基准元素的左边子区间进行相似的快速排序
		quick_sort2(arr,begin,i-1);
		//对基准元素的右边子区间进行相似的快速排序
		quick_sort2(arr,i+1,end);
	}
	//如果区间只有一个数，则返回
	else
		return;
}





//leetcode的方法，但是对于所有元素都相同的方案，会超时，算法会退到O(n^2)
int partition(int *nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

int randomized_partition(int *nums, int l, int r) {
    int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
    swap(nums[r], nums[i]);
    return partition(nums, l, r);
}

void randomized_quicksort(int *nums, int l, int r) {
    if (l < r) {
        int pos = randomized_partition(nums, l, r);
        randomized_quicksort(nums, l, pos - 1);
        randomized_quicksort(nums, pos + 1, r);
    }
}

void sortArray(int* nums,int l,int r) {
    srand((unsigned)time(NULL));
    randomized_quicksort(nums, l, r);
}
