// tests/test1.cpp
#include "gs.h"          
#include <gtest/gtest.h>
#include <vector>
#include "gs.cpp"

TEST(InitTest, BoundaryCheck) {
    init();

    const int width = 256;
    const int height = 256;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            EXPECT_EQ(u[x][y], 1.0);
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150){
              v[x][y] = (std::rand() % 100 - 0) / 100.0;  // Random ~ U[0.0,1.0)
              EXPECT_GE(v[x][y], 0.0);
              EXPECT_LE(v[x][y], 1.0);
            }else{
              EXPECT_EQ(v[x][y], 0.0);
            }
        }
    }
}