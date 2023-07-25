#include "exercises.h"

bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    unsigned int minCoins[] = {0};
    unsigned int lastCoin[] = {0};
    for(int i = 0; i < n; i++)
        usedCoins[i] = 0;

    for (int i = 0; i < n; i++)
        for (int k = C[i]; k <= T; k++)
            if(C[i] + minCoins[k] > minCoins[k]) {
                minCoins[k] = C[i] + minCoins[k];
                lastCoin[k] = i;
            }

    usedCoins[0] = minCoins[T];
    int i = 1;
    for(int k = T; k > 0 && lastCoin[k] > 0; k -= lastCoin[k]) {
        usedCoins[i] = lastCoin[k];
        i++;
    }
    return true;
}
/*
*                       |     0     1     2     3     4    5     6     7     8     9     ...
* ----------------------------------------------------------------------------------------------
* minCoins              |     0     ∞     ∞     ∞     ∞     ∞     ∞     ∞     ∞     ∞
* ----------------------------------------------------------------------------------------------
* lastCoin              |     0     0     0     0     0     0     0     0     0     0
* ----------------------------------------------------------------------------------------------
* i = 1    | minCoins   |     0     1     2     3     4     5     6     7     8     9
* coin = 1 | lastCoin   |     0     1     1     1     1     1     1     1     1     1
* ----------------------|-----------------------------------------------------------------------
* i = 2    |            |           1     1     2     2     3     3     4     4     5
* coin = 2 |            |           1     2     2     2     2     2     2     2     2
* ----------------------|-----------------------------------------------------------------------
*
* troco 9 = 2 + 2 + 2 + 2 + 1
* R = 7 5 3 1 0
*/
/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, hasChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 1);
    EXPECT_EQ(usedCoins[3], 3);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,10,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP4_Ex2, hasChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,7,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 2);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);
}

TEST(TP4_Ex2, hasNoChange) {
    unsigned int C[] = {5,10};
    unsigned int n = 2;
    unsigned int usedCoins[2];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,1,usedCoins), false);
}