/*Makenna Loewenherz*/
/*eecs 348 lab 03*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(double* arr, int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
// Function to print an array
void printArray(int sales[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d \n", sales[i]);
    printf("\n");
}

int get_index_from_value(double sale, double* array, int size) {
    for (int find_index = 0; find_index < size; find_index++) {
        if (array[find_index] == sale) {
            return find_index;
        }
    }
    return -1;
}
    
double average(double* array, int list_size){
    double average = 0;
    for (int i=0; i<list_size; i++) {
        average += array[i];
    }
    average /= list_size;
    return average;
    }
int main() {
    FILE* file_pointer;
    char str[50];
    file_pointer = fopen("input.txt", "r");
    
    //original array
    double sales[12];
    for (int i = 0; i < 12; i++) 
    { 
        fscanf(file_pointer, "%lf", &sales[i]); 
    }


    printf("\nsales report: \n");
    for (int i = 0; i < 12; i++) 
    { 
        printf("%s\t$%f\n", months[i], sales[i]);
    }

    //sorted array
    double sorted_sales[12];
    memcpy (sorted_sales, sales, sizeof(sales));
    selectionSort(sorted_sales, 12);
    printf("\nsales report (highest to lowest): \n");
    for (int i = 0; i < 12; i++) 
    { 
        int index = get_index_from_value(sorted_sales[i], sales, 12);
        printf("%s\t$%f\n", months[index], sorted_sales[i]);
    }

    //sales summary
    printf("\nsales summary: \n");
    printf("\nminimum sales: %f", sorted_sales[0]);
    printf("\nmaximum sales: %f", sorted_sales[11]);
    printf("\naverage sales: %f \n", average(sales, 12));

    //sixth month average moving report
    printf("\nsixth month average moving report \n");
    printf("January - June: %f\n", average(&sales[0], 6));
    printf("February - July: %f\n", average(&sales[1], 6));
    printf("March - August: %f\n", average(&sales[2], 6));
    printf("April - September: %f\n", average(&sales[3], 6));
    printf("May - October: %f\n", average(&sales[4], 6));
    printf("June - November: %f\n", average(&sales[5], 6));
    printf("July - December: %f\n", average(&sales[6], 6));












    return 0;
}