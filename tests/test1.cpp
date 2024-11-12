// tests/test1.cpp
#include "gs.h"          
#include <gtest/gtest.h>
#include <vector>


TEST(InitTest, BoundaryCheck) {
    int test_w = 20;
    int test_h = 20;

    // 定义并初始化局部测试网格
    std::vector<std::vector<double>> u_test(test_w, std::vector<double>(test_h, 1.0));
    std::vector<std::vector<double>> v_test(test_w, std::vector<double>(test_h, 0.0));

    // 遍历并检查 u_test 和 v_test 的初始化结果
    for (int x = 0; x < test_w; ++x) {
        for (int y = 0; y < test_h; ++y) {
            EXPECT_EQ(u_test[x][y], 1.0);  
            EXPECT_EQ(v_test[x][y], 0.0);  
        }
    }

    // 使用不同的网格尺寸进行再次测试
    test_w = 5;
    test_h = 5;
    u_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 1.0));
    v_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 0.0));

    for (int x = 0; x < test_w; ++x) {
        for (int y = 0; y < test_h; ++y) {
            EXPECT_EQ(u_test[x][y], 1.0);
            EXPECT_EQ(v_test[x][y], 0.0);
        }
    }
}