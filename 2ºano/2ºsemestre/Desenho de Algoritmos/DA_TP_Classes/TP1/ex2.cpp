// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = A[0];
    int sum[3] = {0};
    for(i = 0; i < n; i++) {
        for(j = 1; j < n; j++) {
            for(unsigned int k = i; k <= j; k++) {
               sum[0] += A[k];
            }
            if(sum[0] > maxSum) {
                maxSum = sum[0];
                sum[1] = i;
                sum[2] = j;
            }
            sum[0] = 0;
        }
    }
    i = sum[1];
    j = sum[2];
    return maxSum;
}
/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}