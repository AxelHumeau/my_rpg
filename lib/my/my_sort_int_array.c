/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** sort
*/

void min_search(int *array, int *min, int b, int size)
{
    int i = b;

    while (i < size){
        if (array[*min] > array[i]){
            *min = i;
        }
        i = i + 1;
    }
}

void my_sort_int_array(int *array, int size)
{
    int min = 0;
    int temp;
    int b = 0;

    while (b < size){
        min_search(array, &min, b, size);
        temp = array[b];
        array[b] = array[min];
        array[min] = temp;
        b = b + 1;
        min = b;
    }
}
