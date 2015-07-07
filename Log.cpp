/* 
 * File:   Log.cpp
 * Author: danny
 * 
 * Created on January 29, 2015, 5:17 PM
 */

#include "Log.h"

namespace tl
{
Log::Log()  
    :m_bEnabled(true)  
{  
}  
  
Log::~Log()  
{  
}  
  
bool Log::Open(string sFileName)  
{  
    m_tOLogFile.open(sFileName.c_str(), ios_base::out | ios_base::app);  
  
    if( !m_tOLogFile )  
    {  
        return false;  
    }  
  
    return true;  
}  
  
void Log::Close()  
{  
    if(m_tOLogFile.is_open())  
    {  
        m_tOLogFile.close();  
    }  
}  
  
bool Log::CommonLogInit()  
{  
    time_t tNowTime;  
    time(&tNowTime);  
  
    tm* tLocalTime = localtime(&tNowTime);  
  
    //得到日期的字符串  
    string sDateStr = ValueToStr(tLocalTime->tm_year+1900) + "-" +  
        ValueToStr(tLocalTime->tm_mon+1) + "-" +  
        ValueToStr(tLocalTime->tm_mday);  
  
    return Open("Log_" + sDateStr + ".log");  
}  
  
void Log::Enable()  
{  
    m_bEnabled = true;  
}  
  
void Log::Disable()  
{  
    m_bEnabled = false;  
}  
  

string Log::GetTimeStr()  
{  
    time_t tNowTime;  
    time(&tNowTime);  
  
    tm* tLocalTime = localtime(&tNowTime);  
  
    //"2011-07-18 23:03:01 ";  
    string strFormat = "%Y-%m-%d %H:%M:%S ";  
  
    char strDateTime[30] = {'\0'};  
    strftime(strDateTime, 30, strFormat.c_str(), tLocalTime);  
  
    string strRes = strDateTime;  
  
    return strRes;  
}  
}