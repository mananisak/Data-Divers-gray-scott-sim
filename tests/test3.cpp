#include "gs.h"
#include <gtest/gtest.h>   

// Test is about verifing the mathematical correctness of reaction term calculations
//it relate to correction of the result, so important
TEST(MathematicalCorrectnessTest, ReactionTermCalculation) {
    //initia value
    double a = 0.5;
    double b = 0.25;

    //now to calculate the diffusion contribution with du and dv
    double diffusion_du = Du * 0.0;
    double diffusion_dv = Dv * 0.0;
    //then calculate the reaction contribution
    double function_action_du =  - (a * b * b) + (F * (1.0 - a));  
    double function_action_dv =  + (a * b * b) - ((F + k) * b);  
    //add them separately
    double expected_du = diffusion_du + function_action_du;
    double expected_dv = diffusion_dv + function_action_dv;

    u_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 1.0));
    v_test = std::vector<std::vector<double>>(test_w, std::vector<double>(test_h, 0.0));

    //set position use a,b at (1,1)
    u_test[1][1] = a, v_test[1][1] = b;

    //perform simulateStep()
    simulateStep();
    


    //check whether the value in position(1,1) is near the value we calculate just before
    //tolerance=1e-5
    EXPECT_NEAR(u_test[1][1], a + dt * expected_du, 1e-5);
    EXPECT_NEAR(v_test[1][1], b + dt * expected_dv, 1e-5);
}
