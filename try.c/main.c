//
//  main.c
//  try.c
//
//  Created by Deniz zengin on 25.02.2024.
//

//quick_sort with recursion
//öncelikle en sağdan bir pivot belirliyorsun, daha sonra bu pivotun sol tarafında ondan küçükler
//sağ tarafından ondan büyükler olacak şekilde arrayini manipüle ediyorsun
//her bi tarafı yni bir sub array oluyor ve her subarray için aynı partition işlemini yapıyorsun

#include <stdio.h>
void swap(int *array, int i, int j);

void swap(int *array, int i, int j)
{
    int temp;
    temp = array[i];
    array[i]=array[j];
    array[j]=temp;
    return;
}


int partition(int *A, int l, int r)
{
    int i, j, pivot;
    i=l-1;
    j=r;
    pivot = A[r];

    while(i<j)      //i soldan sağa pivottan büyük arıyor:  j sağdan sola pivottan küçük arıyor
    {
        while(A[++i] < pivot); //i'yi pivottan büyük bir element bulana kadar artırıyor
        //looptan çıktı A[i]>pivot
        while(j>l && A[--j]>=pivot);
        //looptan çıktı A[j]<pivot

        if(i<j) //i:büyük j:küçük ---> i j nin solunduysa yer değiştirmeli
        {
            swap(A, i, j);
        }
    }
    swap(A,i,r); //i ve j cross etmesi == partition gerçekleşti: r pivottu
    // bu durumda inin solundaki bütün elemanlar pivottan küçük sağındaki bütün elementler de büyük:
    // o yüzden pivotu inin yerine alıyoruz
    return i;
    //This returned index (i) helps the Quick Sort algorithm determine the boundaries for further recursive sorting of subarrays.
    // The left subarray will have elements less than the pivot (indices from l to i-1),
    // and the right subarray will have elements greater than or equal to the pivot (indices from i+1 to r).
}

void quick_sort(int *A, int l, int r)
{
    int c;
    if(r<=l)
        return;
    c = partition(A,l,r); //ilk partitiondaki c=i pivotun yeri
    quick_sort(A,l,c-1);//pivotu yerleştirdikten sonra left subbarraydeki last elementi pivot yapıyor-->c-1
    quick_sort(A,c+1,r); //right subarrayde c+1 pivot oluyor;
}


int main() {
    {
        int array[10]={1,7,4,2,6,9};
        quick_sort(array, 0, 5);
        for (int i=0; i<6; i++) {
            printf("%d", array[i]);
        }

        return 0;
    }

}
