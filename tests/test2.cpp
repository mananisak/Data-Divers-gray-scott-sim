// tests/test3.cpp
#include "gs.h"               // 主程序声明
#include <gtest/gtest.h>       // Google Test 库
#include <fstream>             // 用于文件操作
#include <sstream>             // 用于字符串操作
#include <cstdio>              // 删除文件


const int width = 256;
const int height = 256;


// 测试 VTK 文件的大小和内容一致性
TEST(SimulationTest, VTKFileSizeCheck) {
    int fileIndex = 1;
    writeVTKFile(fileIndex);  // 调用函数生成文件

    // 构造文件名
    std::stringstream filenameStream;
    filenameStream << "output_" << fileIndex << ".vtk";
    std::string outputFileName = filenameStream.str();

    // 打开文件，检查是否成功创建
    std::ifstream vtkFile(outputFileName, std::ios::binary | std::ios::ate);
    ASSERT_TRUE(vtkFile.is_open()) << "Failed to create VTK output file.";

    // 获取文件大小
    std::streamsize actualFileSize = vtkFile.tellg();
    vtkFile.seekg(0, std::ios::beg);

    // 估计文件的预期大小
    int headerEstimatedSize = 200; // 头部信息大小估计值
    int numDataPoints = width * height;  // 计算数据点的数量
    int estimatedTotalSize = headerEstimatedSize + numDataPoints * 8;  // 每个 double 占 8 字节

    // 验证实际文件大小是否在合理范围内
    EXPECT_NEAR(actualFileSize, estimatedTotalSize, 100) << "File size is not within the expected range.";

    // 关闭文件流
    vtkFile.close();

    // 删除测试生成的文件
    std::remove(outputFileName.c_str());
}