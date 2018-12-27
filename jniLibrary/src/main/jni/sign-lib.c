#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void sortBuff(char **buff, int len){

    char *temp;    //零时交换变量

    int i, j;
//    int len = sizeof(buff) / sizeof(buff[0]);

    /*选择排序法*/
    for (i = 0; i < len; ++i){

        for (j = i + 1; j < len; ++j){

            if( strcmp(buff[i], buff[j]) > 0){ //应用string.h  
                //    int strcmp(    
                temp = buff[i];                    //        const char *string1,
                //        const char *string2 
                buff[i] = buff[j];                //    );
                //string1 > string2 返回值大于0 ， == 为等于0， < 为小于0
                buff[j] = temp;

            }

        }

    }

}

JNIEXPORT jstring JNICALL
Java_com_aaa_jnilibrary_SignUtil_sign(JNIEnv *env, jclass type, jstring a_, jstring b_) {
    const char *a = (*env)->GetStringUTFChars(env, a_, 0);
    const char *b = (*env)->GetStringUTFChars(env, b_, 0);

    const char *list[] = {a, b}; 
    sortBuff(list, 2);
    char *first = (char *) list[0];
    char *second = (char *) list[1];
   

    char *value = (char *) malloc(strlen(first) + strlen(second));
    sprintf(value, "%s%s", first, second);


    return (*env)->NewStringUTF(env, value);
}
