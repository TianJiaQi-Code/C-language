#pragma once
#include <stdio.h>
#include <string.h>

void PrintArray(int* a, int n);

// 插入排序
void InsertSort(int* a, int n);
// 希尔排序
void ShellSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 堆排序
void HeapSort(int* a, int n);
// 选择排序
void SelectSort(int* a, int n);
// 快速排序
void QuickSort(int* a, int begin, int end);
// 快速排序 小区间优化
void QuickSort1(int* a, int begin, int end);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);