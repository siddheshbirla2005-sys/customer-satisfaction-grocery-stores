#include <stdio.h>
void merge(int a[], int low, int mid, int high)
{
int i = low;
int j = mid + 1;
int k = 0;
int temp[high - low + 1];
while(i <= mid && j <= high)
{
if(a[i] <= a[j])
{
temp[k] = a[i];
i++;
}
else
{

temp[k] = a[j];
j++;
}
k++;
}
while(i <= mid)
{
temp[k] = a[i];
i++;
k++;
}
while(j <= high)
{
temp[k] = a[j];
j++;
k++;
}
for(i = low, k = 0; i <= high; i++, k++)
{
a[i] = temp[k];
}
}
void mergeSort(int a[], int low, int high)
{
if(low < high)
{
int mid = (low + high) / 2;
mergeSort(a, low, mid);
mergeSort(a, mid + 1, high);
merge(a, low, mid, high);
}
}
int main()
{
int n;
printf("Enter number of elements: ");
scanf("%d", &n);
int a[n];

printf("Enter elements:\n");
for(int i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
mergeSort(a, 0, n - 1);
printf("Sorted array:\n");
for(int i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
return 0;
}
