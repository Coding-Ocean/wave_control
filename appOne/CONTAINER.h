#pragma once
#include"DATA_TYPE.h"
class CONTAINER{
    class DATA_TYPE<int>* Int = 0;
    int NumIntData = 0;
    class DATA_TYPE<float>* Float = 0;
    int NumFloatData = 0;
    class DATA_TYPE<std::string>* String=0;
    int NumStringData = 0;
public:
    ~CONTAINER();
    //�t�@�C������f�[�^��ǂݍ���
    int loadData(const char* filename);
    //float�擾
    float floatData(const char* name);
    //int�擾
    int intData(const char* name);
    //string�擾
    std::string stringData(const char* name, int idx = -1);
};

