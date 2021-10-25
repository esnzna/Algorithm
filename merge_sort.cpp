void merge_sort(int q[], int l, int r)
{
    //递归的终止情况
    if(l >= r) return;

    //第一步：分成子问题
    int mid = l + r >> 1; //防溢出写法：int mid = l+((r-l)>>1); 

    //第二步：递归处理子问题
    merge_sort(q, l, mid ), merge_sort(q, mid + 1, r);

    //第三步：合并子问题, 临时数组大小只要能够存储当前区间的所有元素即可,当前区间长度为r-l+1
    int k = 0, i = l, j = mid + 1, tmp[r - l + 1];
    while(i <= mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    //将临时数组的元素放置到原数组对应的归并区间中,该区间由l和r标识
    for(k = 0, i = l; i <= r; k++, i++) q[i] = tmp[k];
}



//最好不要这么写
void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int mid = l + r + 1>> 1;//注意mid是向上取整，
    merge_sort(q, l, mid - 1 ), merge_sort(q, mid, r);

    int k = 0, i = l, j = mid, tmp[r - l + 1];
    while(i < mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i < mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(k = 0, i = l; i <= r; k++, i++) q[i] = tmp[k];

}

