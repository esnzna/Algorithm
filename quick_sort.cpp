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
        while(q[++j]<x);
        if (i < j) swap(q[i], q[j]);
    }
    //第二步：递归处理子问题
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
    //第三步：子问题合并.快排这一步不需要操作，但归并排序的核心在这一步骤
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
