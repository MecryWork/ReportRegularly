#ifndef CALLBACKHELPER_H
#define CALLBACKHELPER_H

#include"Thread.h"

class ICallBackReport
{
public:
    virtual void ClallBackProcess() = 0;
    virtual void ClallBackResult() = 0;
};

class CallBackThread:public Thread
{
public:
    CallBackThread(ICallBackReport* pCallBack)
    {
        m_pCallBack = pCallBack;
        m_bStop = false;
    }
    void Start()
    {
        start();
    }

    void ReportProcess()
    {
        if(m_pCallBack)
        {
            m_pCallBack->ClallBackProcess();
        }
    }
    void run()
    {
        while(!m_bStop)
        {
            sleep(1000);
            ReportProcess();
        }
    }

private:
    ICallBackReport *m_pCallBack;
    bool m_bStop;
};

#endif // CALLBACKHELPER_H
