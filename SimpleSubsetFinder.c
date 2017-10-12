#include <stdio.h> 
#include <stdlib.h> 
#define ELEMENT_DEFAULT_SIZE 32

int positivePower(int k, int n) // Calculates k to the power of n.
        {
                int i; // Used for iterations.
                int result = 1; // Result of the cumulative multiplications.

                if (n == 0)
                        return 1;
                else if (n < 0) {
                        printf("positivePower MUST be positive!\n");
                        return -1;
                }
                for (i = 0; i < n; i++)
                        result *= k;

                return result;
        }

int main() {
        int i, j; // Used for iterations. 
        int n; // Number of elements in the set.
        char **set; // 2 dimensional set.

        int binaryNum; // Keeps the value of 
        int subSetNum; // Keeps the value of how many subsets the set has.

        printf("How many elements the set has?\n");
        scanf("%d", & n);

        set = (char**) malloc(n * sizeof(char * ));
        if (set == NULL)
                return -1;

        for (i = 0; i < n; i++)
                set[i] = (char * ) malloc(ELEMENT_DEFAULT_SIZE * sizeof(char));

        for (i = 0; i < n; i++) {
                printf("Enter the %d.element: ", i + 1);
                scanf("%s", set[i]);
        }

        printf("-----------------------\n");

        printf("Here is the set below:\n");
        for (i = 0; i < n; i++)
                printf("%s\n", set[i]);

        printf("-----------------------\n");
        subSetNum = positivePower(2, n);

        // Print all subsets.

        printf("Subsets of the set are given below:\n");
        printf("1 -> \t[EMPTY_SET]\n");
        for (i = 1; i < subSetNum; i++) {
                binaryNum = i;
                printf("%d -> \t", i + 1);
                for (j = 0; j < n; j++) {
                        if (binaryNum & 1)
                                printf("%s", set[j]);
                        binaryNum = binaryNum >> 1;
                }
                printf("\n");
        }

        printf("-----------------------\n");
        printf("Program has terminated successfully.\n");
        return 0;
}
