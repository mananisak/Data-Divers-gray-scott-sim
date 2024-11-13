

// gs.h
#ifndef GS_H
#define GS_H

#include <vector>

// 外部变量声明
extern double Du, Dv, F, k, threshold;
//extern int width;               // 移除 const 关键字
//extern int height;              // 移除 const 关键字
const double dt = 0.06;               // Time step
extern const int numIterations;
extern const int outputInterval;
extern std::vector<std::vector<double>> u, v;

// 函数声明
void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif // GS_H