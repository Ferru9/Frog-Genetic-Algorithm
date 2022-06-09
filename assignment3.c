// INCLUDE THE LIBRARIES
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

// main function
void array_print(float[100][2]);
void random_arrays(float[100][2]);
void array_print_random(float[20][3], float[20][3], float[20][3], float[20][3], float[20][3]);
void array_print_random_normal(float[20][3], float[20][3], float[20][3], float[20][3], float[20][3]);
void goldenFrog(float[100][2]);
void shuffle(float[100][2]);
void randomY(float[100][2]);

// declaring array
float xy[100][2];
float a1[20][3];
float a2[20][3];
float a3[20][3];
float a4[20][3];
float a5[20][3];
float shuffle1[10][3];
float shuffle2[10][3];
float shuffle3[10][3];
float shuffle4[10][3];

int main()
{
    int i;
    // declare the array

    srand(time(NULL));
    for (i = 0; i < 100; i++)
    {
        // generating float numbers for x b/w -1 and 2
        xy[i][0] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        xy[i][0] = (int)(xy[i][0] * 100 + .5);
        xy[i][0] = (float)xy[i][0] / 100;

        // generating float numbers for x b/w -1 and 2
        xy[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        xy[i][1] = (int)(xy[i][1] * 100 + .5);
        xy[i][1] = (float)xy[i][1] / 100;
    }

    // printing the numbers

    array_print(xy);
    printf("\n\n");
    random_arrays(xy);
    array_print_random_normal(a1,a2,a3,a4,a5);
    printf("\n\n");
    array_print_random(a1,a2,a3,a4,a5);
    printf("\n\n");

    for (i = 0; i < 100; i++)
    {
        /* code */
        random_arrays(xy);
        shuffle(xy);
        randomY(xy);
    }

    goldenFrog(xy);

    // END OF THE PROGRAM
    return 0;
}

void array_print(float a[100][2])
{
    int i;

    for (i = 0; i < 100; i++)
    {
        // print all the elements
        printf("x = %0.2f, y= %0.2f\n\n", a[i][0], a[i][1]);
    }
}

void array_print_random(float a1[20][3], float a2[20][3], float a3[20][3], float a4[20][3], float a5[20][3])
{

    int i;

    for (i = 0; i < 8; i++)
    {
        printf("Array 1 - P%2d = %0.2f, %0.2f, F = %0.2f\n\n", i + 1, a1[i][0], a1[i][1], a1[i][2]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 2 - P%2d = %0.2f, %0.2f, F = %0.2f\n\n", i + 1, a2[i][0], a2[i][1], a2[i][2]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 3 - P%2d = %0.2f, %0.2f, F = %0.2f\n\n", i + 1, a3[i][0], a3[i][1], a3[i][2]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 4 - P%2d = %0.2f, %0.2f,  F = %0.2f\n\n", i + 1, a4[i][0], a4[i][1], a4[i][2]);
    }

    for (i = 0; i < 8; i++)
    {
        printf("Array 5 - P%2d = %0.2f, %0.2f, F = %0.2f\n\n", i + 1, a5[i][0], a5[i][1], a5[i][2]);
    }
}

void array_print_random_normal(float a1[20][3], float a2[20][3], float a3[20][3], float a4[20][3], float a5[20][3])
{

    int i;

    for (i = 0; i < 8; i++)
    {
        printf("Array 1 - P%2d = %0.2f, %0.2f\n\n", i + 1, a1[i][0], a1[i][1]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 2 - P%2d = %0.2f, %0.2f\n\n", i + 1, a2[i][0], a2[i][1]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 3 - P%2d = %0.2f, %0.2f\n\n", i + 1, a3[i][0], a3[i][1]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("Array 4 - P%2d = %0.2f, %0.2f\n\n", i + 1, a4[i][0], a4[i][1]);
    }

    for (i = 0; i < 8; i++)
    {
        printf("Array 5 - P%2d = %0.2f, %0.2f\n\n", i + 1, a5[i][0], a5[i][1]);
    }
}

// Function definition
void random_arrays(float a[100][2])
{
    // Declaring the iterators
    int i, j, k, index;
    int x;
    float temp;

    // Declaring an empty array for copying the original array
    float copy[100][2];
    srand(time(NULL));

    // Copying the original random array
    for (i = 0; i < 100; i++)
    {
        copy[i][0] = a[i][0];
        copy[i][1] = a[i][1];
    }

    // Populating first array
    for (i = 0; i < 20;)
    {
        // Choosing a random index
        index = ((float)(rand()) / (float)(RAND_MAX)) * 100;

        if (copy[index][0] >= -2)
        {
            // Populating the elements of the array
            a1[i][0] = copy[index][0];
            a1[i][1] = copy[index][1];

            // Marking an element as chosen
            copy[index][0] = -5;
            // Incrementing iterator
            i++;
        }
    }

    // Populating second array
    for (i = 0; i < 20;)
    {
        // Choosing a random index
        index = ((float)(rand()) / (float)(RAND_MAX)) * 100;

        // Checking if the random index has not already been chosen.
        if (copy[index][0] >= -2)
        {
            // Populating the elements of the array
            a2[i][0] = copy[index][0];
            a2[i][1] = copy[index][1];

            // Marking an element as chosen
            copy[index][0] = -5;

            // Incrementing iterator
            i++;
        }
    }

    // Populating third array
    for (i = 0; i < 20;)
    {
        // Choosing a random index
        index = ((float)(rand()) / (float)(RAND_MAX)) * 100;

        // Checking if the random index has not already been chosen.
        if (copy[index][0] >= -2)
        {
            // Populating the elements of the array
            a3[i][0] = copy[index][0];
            a3[i][1] = copy[index][1];

            // Marking an element as chosen
            copy[index][0] = -5;

            // Incrementing iterator
            i++;
        }
    }

    // Populating fourth array
    for (i = 0; i < 20;)
    {
        // Choosing a random index
        index = ((float)(rand()) / (float)(RAND_MAX)) * 100;

        // Checking if the random index has not already been chosen.
        if (copy[index][0] >= -2)
        {
            // Populating the elements of the array
            a4[i][0] = copy[index][0];
            a4[i][1] = copy[index][1];

            // Marking an element as chosen
            copy[index][0] = -5;

            // Incrementing iterator
            i++;
        }
    }

    // Populating fifth array
    for (i = 0; i < 20;)
    {
        // Choosing a random index
        index = ((float)(rand()) / (float)(RAND_MAX)) * 100;

        // Checking if the random index has not already been chosen.
        if (copy[index][0] >= -2)
        {
            // Populating the elements of the array
            a5[i][0] = copy[index][0];
            a5[i][1] = copy[index][1];

            // Marking an element as chosen
            copy[index][0] = -5;

            // Incrementing iterator
            i++;
        }
    }

    // Getting the fitness value (F) of each index on array 1

    for (i = 0; i < 20;)
    {

        // populating the array with the fitness equation

        a1[i][2] = ((7) * (a1[i][0]) * (a1[i][1])) / (exp((pow(a1[i][0], 2)) + (pow(a1[i][1], 2))));

        // Incrementing iterator
        i++;
    }

    // Getting the fitness value (F) of each index on array 2

    for (i = 0; i < 20;)
    {

        // populating the array with the fitness equation

        a2[i][2] = ((7) * (a2[i][0]) * (a2[i][1])) / (exp((pow(a2[i][0], 2)) + (pow(a2[i][1], 2))));

        // Incrementing iterator
        i++;
    }

    // Getting the fitness value (F) of each index on array 3

    for (i = 0; i < 20;)
    {

        // populating the array with the fitness equation

        a3[i][2] = ((7) * (a3[i][0]) * (a3[i][1])) / (exp((pow(a3[i][0], 2)) + (pow(a3[i][1], 2))));

        // Incrementing iterator
        i++;
    }

    // Getting the fitness value (F) of each index on array 4

    for (i = 0; i < 20;)
    {

        // populating the array with the fitness equation

        a4[i][2] = ((7) * (a4[i][0]) * (a4[i][1])) / (exp((pow(a4[i][0], 2)) + (pow(a4[i][1], 2))));

        // Incrementing iterator
        i++;
    }

    // Getting the fitness value (F) of each index on array 5

    for (i = 0; i < 20;)
    {

        // populating the array with the fitness equation

        a5[i][2] = ((7) * (a5[i][0]) * (a5[i][1])) / (exp((pow(a5[i][0], 2)) + (pow(a5[i][1], 2))));

        // Incrementing iterator
        i++;
    }

    // sorting fist array

    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (a1[i][2] > a1[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = a1[i][x];
                    a1[i][x] = a1[j][x];
                    a1[j][x] = temp;
                }
            }
        }
    }

    // sorting second array

    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (a2[i][2] > a2[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = a2[i][x];
                    a2[i][x] = a2[j][x];
                    a2[j][x] = temp;
                }
            }
        }
    }

    // sorting third array

    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (a3[i][2] > a3[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = a1[i][x];
                    a3[i][x] = a3[j][x];
                    a3[j][x] = temp;
                }
            }
        }
    }

    // sorting forth array

    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (a4[i][2] > a4[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = a4[i][x];
                    a4[i][x] = a4[j][x];
                    a4[j][x] = temp;
                }
            }
        }
    }

    // sorting fifth array

    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (a5[i][2] > a5[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = a5[i][x];
                    a5[i][x] = a5[j][x];
                    a5[j][x] = temp;
                }
            }
        }
    }
}

void goldenFrog(float a[100][2])
{
    int i, j, x;
    float temp;

    float smallestNumbers[9][3];
    float goldenFrog[1][3];

    for (i = 0; i < 3; i++)
    {
        smallestNumbers[0][i] = a1[0][i];
        smallestNumbers[1][i] = a2[0][i];
        smallestNumbers[2][i] = a3[0][i];
        smallestNumbers[3][i] = a4[0][i];
        smallestNumbers[4][i] = a5[0][i];
        smallestNumbers[5][i] = shuffle1[0][i];
        smallestNumbers[6][i] = shuffle2[0][i];
        smallestNumbers[7][i] = shuffle3[0][i];
        smallestNumbers[8][i] = shuffle4[0][i];
    }

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            if (smallestNumbers[i][2] > smallestNumbers[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = smallestNumbers[i][x];
                    smallestNumbers[i][x] = smallestNumbers[j][x];
                    smallestNumbers[j][x] = temp;
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        goldenFrog[0][i] = smallestNumbers[0][i];
    }

    for (i = 0; i < 1; i++)
    {
        printf("GoldenFrog = %0.2f, %0.2f, Fitness Value = %0.2f\n\n", goldenFrog[i][0], goldenFrog[i][1], goldenFrog[i][2]);
    }
}

void shuffle(float a[100][2])
{
    int i, j, x, k;
    float temp;

    srand(time(NULL));

    // Populating first array
    for (i = 0; i < 8;)
    {

        for (k = 0; k < 2;)
        {
            // Populating the elements of the array
            shuffle1[k][0] = a1[k][0];
            shuffle1[k][1] = a1[k][1];
            shuffle1[i][2] = ((7) * (shuffle1[i][0]) * (shuffle1[i][1])) / (exp((pow(shuffle1[i][0], 2)) + (pow(shuffle1[i][1], 2))));
            k++;
        }
        for (k = 2; k < 4;)
        {
            // Populating the elements of the array
            shuffle1[k][0] = a2[k][0];
            shuffle1[k][1] = a2[k][1];
            shuffle1[i][2] = ((7) * (shuffle1[i][0]) * (shuffle1[i][1])) / (exp((pow(shuffle1[i][0], 2)) + (pow(shuffle1[i][1], 2))));
            k++;
        }
        for (k = 4; k < 6;)
        {
            // Populating the elements of the array
            shuffle1[k][0] = a3[k][0];
            shuffle1[k][1] = a3[k][1];
            shuffle1[i][2] = ((7) * (shuffle1[i][0]) * (shuffle1[i][1])) / (exp((pow(shuffle1[i][0], 2)) + (pow(shuffle1[i][1], 2))));
            k++;
        }
        for (k = 6; k < 8;)
        {
            // Populating the elements of the array
            shuffle1[k][0] = a4[k][0];
            shuffle1[k][1] = a4[k][1];
            shuffle1[i][2] = ((7) * (shuffle1[i][0]) * (shuffle1[i][1])) / (exp((pow(shuffle1[i][0], 2)) + (pow(shuffle1[i][1], 2))));
            k++;
        }
        for (k = 8; k < 10;)
        {
            // Populating the elements of the array
            shuffle1[k][0] = a5[k][0];
            shuffle1[k][1] = a5[k][1];
            shuffle1[i][2] = ((7) * (shuffle1[i][0]) * (shuffle1[i][1])) / (exp((pow(shuffle1[i][0], 2)) + (pow(shuffle1[i][1], 2))));
            k++;
        }

        // Incrementing iterator
        i++;
    }

    // Populating second array
    for (i = 0; i < 8;)
    {

        for (k = 0; k < 2;)
        {
            // Populating the elements of the array
            shuffle2[k][0] = a2[k][0];
            shuffle2[k][1] = a2[k][1];
            shuffle2[i][2] = ((7) * (shuffle2[i][0]) * (shuffle2[i][1])) / (exp((pow(shuffle2[i][0], 2)) + (pow(shuffle2[i][1], 2))));
            k++;
        }
        for (k = 2; k < 4;)
        {
            // Populating the elements of the array
            shuffle2[k][0] = a1[k][0];
            shuffle2[k][1] = a1[k][1];
            shuffle2[i][2] = ((7) * (shuffle2[i][0]) * (shuffle2[i][1])) / (exp((pow(shuffle2[i][0], 2)) + (pow(shuffle2[i][1], 2))));
            k++;
        }
        for (k = 4; k < 6;)
        {
            // Populating the elements of the array
            shuffle2[k][0] = a3[k][0];
            shuffle2[k][1] = a3[k][1];
            shuffle2[i][2] = ((7) * (shuffle2[i][0]) * (shuffle2[i][1])) / (exp((pow(shuffle2[i][0], 2)) + (pow(shuffle2[i][1], 2))));
            k++;
        }
        for (k = 6; k < 8;)
        {
            // Populating the elements of the array
            shuffle2[k][0] = a4[k][0];
            shuffle2[k][1] = a4[k][1];
            shuffle2[i][2] = ((7) * (shuffle2[i][0]) * (shuffle2[i][1])) / (exp((pow(shuffle2[i][0], 2)) + (pow(shuffle2[i][1], 2))));
            k++;
        }
        for (k = 8; k < 10;)
        {
            // Populating the elements of the array
            shuffle2[k][0] = a5[k][0];
            shuffle2[k][1] = a5[k][1];
            shuffle2[i][2] = ((7) * (shuffle2[i][0]) * (shuffle2[i][1])) / (exp((pow(shuffle2[i][0], 2)) + (pow(shuffle2[i][1], 2))));
            k++;
        }

        // Incrementing iterator
        i++;
    }

    // Populating third array
    for (i = 0; i < 8;)
    {

        for (k = 0; k < 2;)
        {
            // Populating the elements of the array
            shuffle3[k][0] = a3[k][0];
            shuffle3[k][1] = a3[k][1];
            shuffle3[i][2] = ((7) * (shuffle3[i][0]) * (shuffle3[i][1])) / (exp((pow(shuffle3[i][0], 2)) + (pow(shuffle3[i][1], 2))));
            k++;
        }
        for (k = 2; k < 4;)
        {
            // Populating the elements of the array
            shuffle3[k][0] = a2[k][0];
            shuffle3[k][1] = a2[k][1];
            shuffle3[i][2] = ((7) * (shuffle3[i][0]) * (shuffle3[i][1])) / (exp((pow(shuffle3[i][0], 2)) + (pow(shuffle3[i][1], 2))));
            k++;
        }
        for (k = 4; k < 6;)
        {
            // Populating the elements of the array
            shuffle3[k][0] = a1[k][0];
            shuffle3[k][1] = a1[k][1];
            shuffle3[i][2] = ((7) * (shuffle3[i][0]) * (shuffle3[i][1])) / (exp((pow(shuffle3[i][0], 2)) + (pow(shuffle3[i][1], 2))));
            k++;
        }
        for (k = 6; k < 8;)
        {
            // Populating the elements of the array
            shuffle3[k][0] = a4[k][0];
            shuffle3[k][1] = a4[k][1];
            shuffle3[i][2] = ((7) * (shuffle3[i][0]) * (shuffle3[i][1])) / (exp((pow(shuffle3[i][0], 2)) + (pow(shuffle3[i][1], 2))));
            k++;
        }
        for (k = 8; k < 10;)
        {
            // Populating the elements of the array
            shuffle3[k][0] = a5[k][0];
            shuffle3[k][1] = a5[k][1];
            shuffle3[i][2] = ((7) * (shuffle3[i][0]) * (shuffle3[i][1])) / (exp((pow(shuffle3[i][0], 2)) + (pow(shuffle3[i][1], 2))));
            k++;
        }

        // Incrementing iterator
        i++;
    }

    // Populating fourth array
    for (i = 0; i < 8;)
    {

        for (k = 0; k < 2;)
        {
            // Populating the elements of the array
            shuffle4[k][0] = a4[k][0];
            shuffle4[k][1] = a4[k][1];
            shuffle4[i][2] = ((7) * (shuffle4[i][0]) * (shuffle4[i][1])) / (exp((pow(shuffle4[i][0], 2)) + (pow(shuffle4[i][1], 2))));
            k++;
        }
        for (k = 2; k < 4;)
        {
            // Populating the elements of the array
            shuffle4[k][0] = a3[k][0];
            shuffle4[k][1] = a3[k][1];
            shuffle4[i][2] = ((7) * (shuffle4[i][0]) * (shuffle4[i][1])) / (exp((pow(shuffle4[i][0], 2)) + (pow(shuffle4[i][1], 2))));
            k++;
        }
        for (k = 4; k < 6;)
        {
            // Populating the elements of the array
            shuffle4[k][0] = a2[k][0];
            shuffle4[k][1] = a2[k][1];
            shuffle4[i][2] = ((7) * (shuffle4[i][0]) * (shuffle4[i][1])) / (exp((pow(shuffle4[i][0], 2)) + (pow(shuffle4[i][1], 2))));
            k++;
        }
        for (k = 6; k < 8;)
        {
            // Populating the elements of the array
            shuffle4[k][0] = a1[k][0];
            shuffle4[k][1] = a1[k][1];
            shuffle4[i][2] = ((7) * (shuffle4[i][0]) * (shuffle4[i][1])) / (exp((pow(shuffle4[i][0], 2)) + (pow(shuffle4[i][1], 2))));
            k++;
        }
        for (k = 8; k < 10;)
        {
            // Populating the elements of the array
            shuffle4[k][0] = a5[k][0];
            shuffle4[k][1] = a5[k][1];
            shuffle4[i][2] = ((7) * (shuffle4[i][0]) * (shuffle4[i][1])) / (exp((pow(shuffle4[i][0], 2)) + (pow(shuffle4[i][1], 2))));
            k++;
        }

        // Incrementing iterator
        i++;
    }

    // sorting fist array

    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (shuffle1[i][2] > shuffle1[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = shuffle1[i][x];
                    shuffle1[i][x] = shuffle1[j][x];
                    shuffle1[j][x] = temp;
                }
            }
        }
    }

    // sorting second array

    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (shuffle2[i][2] > shuffle2[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = shuffle2[i][x];
                    shuffle2[i][x] = shuffle2[j][x];
                    shuffle2[j][x] = temp;
                }
            }
        }
    }

    // sorting third array

    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (shuffle3[i][2] > shuffle3[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = shuffle3[i][x];
                    shuffle3[i][x] = shuffle3[j][x];
                    shuffle3[j][x] = temp;
                }
            }
        }
    }

    // sorting forth array

    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (shuffle4[i][2] > shuffle4[j][2])
            {
                for (x = 0; x < 3; x++)
                {
                    temp = shuffle4[i][x];
                    shuffle4[i][x] = shuffle4[j][x];
                    shuffle4[j][x] = temp;
                }
            }
        }
    }
}

void randomY(float a[100][2])
{

    int i;
    // declare the array

    srand(time(NULL));

    for (i = 0; i < 100; i++)
    {
        // generating float numbers for y b/w -1 and 2
        xy[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        xy[i][1] = (int)(xy[i][1] * 100 + .5);
        xy[i][1] = (float)xy[i][1] / 100;
    }

    for (i = 0; i < 20; i++)
    {
        // generating float numbers for y b/w -1 and 2
        a1[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        a1[i][1] = (int)(a1[i][1] * 100 + .5);
        a1[i][1] = (float)a1[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        a2[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        a2[i][1] = (int)(a2[i][1] * 100 + .5);
        a2[i][1] = (float)a2[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        a3[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        a3[i][1] = (int)(a3[i][1] * 100 + .5);
        a3[i][1] = (float)a3[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        a4[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        a4[i][1] = (int)(a4[i][1] * 100 + .5);
        a4[i][1] = (float)a4[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        a5[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        a5[i][1] = (int)(a5[i][1] * 100 + .5);
        a5[i][1] = (float)a5[i][1] / 100;
    }

    for (i = 0; i < 10; i++)
    {

        // generating float numbers for y b/w -1 and 2
        shuffle1[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        shuffle1[i][1] = (int)(shuffle1[i][1] * 100 + .5);
        shuffle1[i][1] = (float)shuffle1[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        shuffle2[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        shuffle2[i][1] = (int)(shuffle2[i][1] * 100 + .5);
        shuffle2[i][1] = (float)shuffle2[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        shuffle3[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        shuffle3[i][1] = (int)(shuffle3[i][1] * 100 + .5);
        shuffle3[i][1] = (float)a5[i][1] / 100;

        // generating float numbers for y b/w -1 and 2
        shuffle4[i][1] = ((float)(rand()) / (float)(RAND_MAX)) * 4 - 2;

        // converting it to two digitprecision
        shuffle4[i][1] = (int)(shuffle4[i][1] * 100 + .5);
        shuffle4[i][1] = (float)shuffle4[i][1] / 100;
    }
}
