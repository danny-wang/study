/* 
 * File:   Log.h
 * Author: danny
 *
 * Created on January 29, 2015, 5:17 PM
 */

#ifndef LOG_H
#define	LOG_H
#include <fstream>  
#include <string>  
#include <sstream>  
#include <ctime>  
namespace tl
{  
using namespace std;  
  
  
/** 
 * 用于输出log文件的类. 
 */  
class Log  
{  
public:  
    Log();  
    ~Log();  
  
    bool Open(string strFileName);  
    void Close();  
  
    bool CommonLogInit(); //打开默认的log 文件  
  
    void Enable();  
    void Disable();  
  /**
 * 得到当前时间的字符串  
 * @return 
 */
    string GetTimeStr(); 
  
    template <typename T> void LogOut(const T& value)  
    {  
        if (m_bEnabled)  
        {  
            m_tOLogFile << value;  
        }  
    }  
  
    template <typename T> void LogOutLn(const T& value)  
    {  
        if (m_bEnabled)  
        {  
            m_tOLogFile << value << endl;  
        }  
    }  
  
    void LogOutLn()  
    {  
        if (m_bEnabled)  
        {  
            m_tOLogFile << endl;  
        }  
    }  
  
    template <typename T> Log& operator<<(const T& value)  
    {  
        if (m_bEnabled)  
        {  
            m_tOLogFile << value;  
        }  
        return (*this);  
    }  
  
    Log& operator<<(ostream& (*_Pfn)(ostream&))  
    {  
        if (m_bEnabled)  
        {  
            (*_Pfn)(m_tOLogFile);  
        }  
        return (*this);  
    }  
  
private:  
    template<typename T> string ValueToStr(T value)  
    {  
        ostringstream ost;  
        ost << value;  
        return ost.str();  
    }  
private:  
    ofstream m_tOLogFile;  
  
    bool m_bEnabled;  
};  
  
}
#endif	/* LOG_H */
/**
 how to use this class:
    Log mainLog;
    mainLog.CommonLogInit();
    mainLog << mainLog.GetTimeStr() << "测试Log类." << endl;
 */
