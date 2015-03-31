#include <stdio.h>
#include <stdlib.h>
const int N = 8;
/*
设 A 为一个有 n 个数字的有序集 (n>1)，其中所有数字各不相同。
如果存在正整数 i, j 使得 1 ≤ i < j ≤ n 而且 A[i] > A[j]，则 <A[i], A[j]> 这一个有序对称为 A 的一个逆序对，也称作逆序数。
求逆序对数目
*/
int ReverseNumber; //逆序对数目 

bool MergeSort(int arr[], int size);
void MSort(int arr[], int left, int right, int tmpArr[]);
void Merge(int arr[], int left, int mid, int right, int tmpArr[]);

int main(int argc, char** argv)
{
    int arr[N] = {4,3,7,10,9,5,6,2};
    for (int i = 0; i < N; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    MergeSort(arr, N);
    for (int i = 0; i < N; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("逆序对数目:%d", ReverseNumber);
    return 0;
}

bool MergeSort(int arr[], int size)
{
    int* tmpArr = (int *)malloc(size * sizeof(int));
    if (tmpArr != NULL) {
        MSort(arr, 0, size - 1, tmpArr);
        free(tmpArr);
        return true;
    } else {
        return false;
    }
}

void MSort(int arr[], int left, int right, int tmpArr[])
{
    int mid = (left + right) / 2;
    if (left < right) {
        MSort(arr, left, mid, tmpArr);
        MSort(arr, mid+1, right, tmpArr);
        Merge(arr, left, mid, right, tmpArr);
    }
}

void Merge(int arr[], int left, int mid, int right, int tmpArr[])
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmpArr[k++] = arr[i++];
        } else {
            tmpArr[k++] = arr[j++];
            ReverseNumber += mid - i + 1;
        }
    }
    while (i <= mid) {
        tmpArr[k++] = arr[i++];
    }
    while (j <= right) {
        tmpArr[k++] = arr[j++];
    }
    for (k = left; k <= right; k++) {
        arr[k] = tmpArr[k];
    }
}
