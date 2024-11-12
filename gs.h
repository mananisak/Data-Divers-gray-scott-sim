// gs.h
#ifndef GS_H
#define GS_H

#include <vector>

// 外部变量声明
extern double Du, Dv, F, k, threshold;
extern const int width;
extern const int height;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;
extern std::vector<std::vector<double>> u, v;

// 函数声明
void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif // GS_H