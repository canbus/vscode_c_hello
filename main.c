#include <stdio.h>
#include <string.h>

int msg_level = 3;//0:不打印,1:不符加,2:附加DEBUG_TAG,3:符加DEBUG_TAG及函数名和行号
#define DEBUG_TAG "INF:"

#define __output1(...) \
		do{	\
			char __buf[200];\
			if(msg_level > 1) \
				strcpy(__buf,DEBUG_TAG); \
			sprintf(&__buf[msg_level > 1 ? strlen(DEBUG_TAG):0],__VA_ARGS__); \
			if(msg_level > 0) printf("%s",__buf);	\
		}while(0)

#define __format1(__fmt__) __fmt__ ""
#define __format2(__fmt__) __fmt__ ""
#define __format3(__fmt__) __fmt__ "%s() L%d:"
#define INFO(__fmt__, ...) \
		do{	\
			if(msg_level == 1) \
				__output1(__format1(__fmt__), ##__VA_ARGS__);	\
			else if(msg_level == 2) \
    			__output1(__format2(__fmt__), ##__VA_ARGS__);	\
			else if(msg_level == 3) \
				__output1(__format3(__fmt__), __FUNCTION__, __LINE__, ##__VA_ARGS__);	\
		}while(0)


extern void myprintf();
void main()
{
    myprintf();
    for (int i = 0; i < 10; i++) 
        INFO("==hello==\n");
}