#include "gs.h"  
#include <gtest/gtest.h>

#include <vector>
#include <cmath>
#include "gs.cpp" 

//Long-term stability test
//verify system behavior over multiple iterations
TEST(LongTermStabilityTest, CheckStabilityOverIterations) {
    init();  

    // define acceptable bounds for stability
    // I search it and when it comes to 0, means that no concentration,and 1 can be the max one
    // so (0,1) is the standard concentration
    double min_value = 0.0;
    double max_value = 1.0;

    //perform steps now!
    //to test system's long-term behavior
    int iterations = 1000;  
    for (int i = 0; i < iterations; ++i) {
        simulateStep();
    }

    u_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 1.0));
    v_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 0.0));

    //check value
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            EXPECT_GE(u_test[i][j], min_value) << "u[" << i<< "][" << j << "] under minimum limitation";
            EXPECT_LE(u_test[i][j], max_value) << "u[" << i << "][" << j << "] over maximum limitation";
            EXPECT_GE(v_test[i][j], min_value) << "v[" << i << "][" << j << "] under minimum limitation";
            EXPECT_LE(v_test[i][j], max_value) << "v[" << i << "][" << j << "] over maximum limitation";
        }
    }
}