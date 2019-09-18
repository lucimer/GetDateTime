#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define _DATETIME_SIZE  32


// GetDate - 获取当前系统日期
/**
 *  函数名称：GetDate
 *  功能描述：取当前系统日期
 *
 *  输出参数：char * psDate  - 系统日期，格式为yyymmdd
 *  返回结果：0 -> 成功
 */
int 
GetDate(char * psDate){
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds); // 同 nSeconds = time(NULL);
    pTM = localtime(&nSeconds);
    
    /* 系统日期,格式:YYYMMDD */
    sprintf(psDate,"%04d-%02d-%02d", 
            pTM->tm_year + 1900, pTM->tm_mon + 1, pTM->tm_mday);
    
    return 0;
}

// GetTime  - 获取当前系统时间
/**
 *  函数名称：GetTime
 *  功能描述：取当前系统时间
 *
 *  输出参数：char * psTime -- 系统时间，格式为HHMMSS
 *  返回结果：0 -> 成功
 */
int 
GetTime(char * psTime) {
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds);
    pTM = localtime(&nSeconds);
    
    /* 系统时间，格式: HHMMSS */
    sprintf(psTime, "%02d:%02d:%02d",
            pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
           
    return 0;       
}

// GetDateTime - 取当前系统日期和时间
/**
 *  函数名称：GetDateTime
 *  功能描述：取当前系统日期和时间
 *
 *  输出参数：char * psDateTime -- 系统日期时间,格式为yyymmddHHMMSS
 *  返回结果：0 -> 成功
 */
int 
GetDateTime(char * psDateTime) {
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds);
    pTM = localtime(&nSeconds);

    /* 系统日期和时间,格式: yyyymmddHHMMSS */
    sprintf(psDateTime, "%04d-%02d-%02d %02d:%02d:%02d",
            pTM->tm_year + 1900, pTM->tm_mon + 1, pTM->tm_mday,
            pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
            
    return 0;
}

// 测试代码
int main()
{
    int ret;
    char DateTime[_DATETIME_SIZE];
    
    memset(DateTime, 0, sizeof(DateTime));
    
    /* 获取系统当前日期 */
    ret = GetDate(DateTime);
    if(ret == 0) 
        printf("The Local date is %s\n", DateTime);
    else 
        perror("GetDate error!");
    
    memset(DateTime, 0, sizeof(DateTime));
    /* 获取当前系统时间 */
    ret = GetTime(DateTime);
    if(ret == 0) 
        printf("The Local time is %s\n", DateTime);
    else 
        perror("GetTime error!");
    
    memset(DateTime, 0, sizeof(DateTime));
    /* 获取系统当前日期时间 */
    ret = GetDateTime(DateTime);
    if(ret == 0) 
        printf("The Local date and time is %s\n", DateTime);
    else 
        perror("GetDateTime error!");
    
    
    
    return 0;
}
