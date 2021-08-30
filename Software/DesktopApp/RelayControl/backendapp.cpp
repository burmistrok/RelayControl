#include "backendapp.h"

BackEndApp::BackEndApp()
{

}


void BackEndApp::run(void)
{
    while(true)
    {
        emit this->CheckDataFromCommPort();
        this->msleep(10);
    }
}
