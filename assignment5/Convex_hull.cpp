#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


#define MAX_POINTS  1000


int minimum_index = 1;

int size = -1;


typedef struct Point
{
    int x;
    int y;
}Point;

Point P0;

struct Point stack[MAX_POINTS];


bool checktie(int y_min, int y, int x, int x_min)
{
    bool flag = false;

    if (y_min == y)
    {
        if (x < x_min)
        {
            flag = true;
        }
    }
    return flag;
}


int find_miny(int total_points, Point points[MAX_POINTS])
{
    int bottom_y = points[0].y;
    int i = 1;
    while (i < total_points)
    {
        int point_y = points[i].y;
       
        bool tie = checktie(bottom_y, point_y, points[i].x, points[minimum_index].x);
        if ((point_y < bottom_y) || (tie == true))
        {
            bottom_y = points[i].y;
            minimum_index = i;
        }
        i++;
    }
    return bottom_y;
}


void swap_points(int total, Point points[MAX_POINTS], int first_index, int second_index)
{
    Point temp = points[first_index];
    points[first_index] = points[second_index];
    points[second_index] = temp;
}


int find_greater(Point p1, Point p2, Point p3)
{
    int first_distance = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    int second_distance = (p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y);
    if (first_distance >= second_distance)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


void push(Point P)
{
    size = size + 1;
    stack[size] = P;
}


void pop()
{
    size = size - 1;
}


void print()
{
    int i = 0;
    for (i = 0; i <= size; i++)
    {
        printf("%d\t%d\n", stack[i].x, stack[i].y);
    }
}

int find(Point p0, Point p1, Point p2)
{

    int cross_product = (p1.y - p0.y) * (p2.x - p1.x) -
        (p1.x - p0.x) * (p2.y - p1.y);
    if (cross_product == 0)
    {
        return 0;
    }
    else if (cross_product > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int check(int total, Point points[MAX_POINTS])
{

    int new_size = 1;
    int counter = 1;
    while (counter < total)
    {

        while (counter < total - 1 && find(P0, points[counter], points[counter + 1]) == 0)
        {
            counter++;
        }
        points[new_size] = points[counter];

        new_size = new_size + 1;
        counter = counter + 1;
    }
    return new_size;
}

int qsort_compare_coordinates(const void* p, const void* q)
{
    Point* P1 = (Point*)p;
    Point* P2 = (Point*)q;

    int orint = find(P0, *P1, *P2);
    if (orint == 0)
    {
        return find_greater(P0, *P2, *P1);
    }
    if (orint == -1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


void convexHull(int total_points, Point points[MAX_POINTS])
{
    
    int bottom_y = find_miny(total_points, points);
    
    swap_points(total_points, points, 0, minimum_index);

    
    P0 = points[0];
    qsort(&points[1], total_points - 1, sizeof(Point), qsort_compare_coordinates);

   
    int updated_size = check(total_points, points);

   
    if (updated_size < 3)
    {
        return;
    }

  
    push(points[0]);
    push(points[1]);
    push(points[2]);

 
    int i = 1;
    for (i = 3; i < updated_size; i++)
    {
        while (find(stack[size - 1], stack[size], points[i]) > -1)
        {
            pop();
        }
        push(points[i]);
    }

    printf("\n");
    printf("Following vertices form the convex hull:\n");
    printf(" x\t y\n");
    print();

}

int main()
{
    int i = 0;
    int total_points = 0;

    
    printf("\nEnter total points you want to check for: ");
    scanf("%d", &total_points);
    Point arr_points[MAX_POINTS];
    printf("\nEnter two numbers separated by a space for (e.g: 10 15):\n");
    for (i = 0; i < total_points; i++)
    {
        scanf("%d %d", &arr_points[i].x, &arr_points[i].y);
    }

 
    printf("\nPrinting all the points to compute convex hall.\n");
    printf(" x\t y\n");
    for (i = 0; i < total_points; i++)
    {
        printf("%d\t%d\n", arr_points[i].x, arr_points[i].y);
    }

    convexHull(total_points, arr_points);
    return 0;
}
