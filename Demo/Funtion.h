#ifndef FUNTION_H
#define FUNTION_H

#include"CallBackHelper.h"

class CFunc:public ICallBackReport
{
public:
    CFunc()
    {
        nProcess = 0;
    }
    void GetProcess();
    void DoFuncMan();
    void ClallBackProcess();
    void ClallBackResult();
private:
    int nProcess;
};

#endif // FUNTION_H
