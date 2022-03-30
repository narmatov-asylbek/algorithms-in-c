#include <stdio.h>


void two_d_array(void)
{
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            printf("%d, \n", A[i][j]);
        }
    }

}

int main(void)
{
    two_d_array();
    return 0;
}