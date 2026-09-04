#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
	// 从a[start..end]中选取一ot元素（比如选a[start]为pivot）;
	// 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	// 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	// return mid;
    int pivot = a[start];
    
    while (start < end) {
        while (a[end] >= pivot) {
            --end;
            if (start == end) {
                a[start] = pivot;
                return start;
            }
        }
        a[start] = a[end];
        ++start;
        if (start == end){
            a[start] = pivot;
            return start;
        }
        while (a[start] <= pivot) {
            ++start;
            if (start == end) {
                a[start] = pivot;
                return start;
            }
        }
        a[end] = a[start];
        --end;
        if (start == end) {
            a[start] = pivot;
            return start;
        }
    }
    return -1;
}

void quicksort(int start, int end)
{
    int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}	
}

int main(void)
{
	quicksort(0, LEN-1);
	return 0;
}