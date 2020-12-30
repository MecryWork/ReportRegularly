#include"Funtion.h"
#include"CallBackHelper.h"

#include<iostream>
using namespace std;

void CFunc::GetProcess()
{

}
void CFunc::ClallBackResult()
{
    //to do
}

void CFunc::ClallBackProcess()
{
    cout<<"nProcess :"<<nProcess<<endl;

}

void CFunc::DoFuncMan()
{
    CallBackThread myThread(this);
    myThread.Start();
    while(true)
    {
        nProcess++;
    }
}
