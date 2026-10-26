#include <list>
#include <vector>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <string>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.hpp"
#include "Menu/Menu.hpp"
#include "Menu/Jni.hpp"
#include "Includes/Macros.h"
#include "dobby.h"

#define targetLibName OBFUSCATE("libil2cpp.so")

// Definição da Lista de Funções que aparecem no Menu Flutuante
jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_=== PAINEL FREE FIRE === "),
            OBFUSCATE("Toggle_ESP Linha (Line)"),
            OBFUSCATE("Toggle_ESP Caixa (Box)"),
            OBFUSCATE("Toggle_ESP Distância"),
            OBFUSCATE("Category_=== MIRA / AIMBOT ==="),
            OBFUSCATE("Toggle_Aimbot FOV"),
            OBFUSCATE("Toggle_Aimbot No Recoil"),
            OBFUSCATE("SeekBar_Tamanho do FOV_1_360")
    };

    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

// O que acontece quando o utilizador clica em cada botão do painel
void Changes(JNIEnv *env, jclass clazz, jobject obj, jint featNum, jstring featName, jint value, jlong Lvalue, jboolean boolean, jstring text) {

    switch (featNum) {
        case 0: // ESP Linha
            if(boolean) {
                // Ativar ESP Linha
            } else {
                // Desativar ESP Linha
            }
            break;
            
        case 1: // ESP Caixa
            if(boolean) {
                // Ativar ESP Caixa
            }
            break;
            
        case 2: // ESP Distância
            if(boolean) {
                // Ativar ESP Distância
            }
            break;
            
        case 5: // Aimbot FOV
            if(boolean) {
                // Ativar Aimbot FOV
            }
            break;
            
        case 6: // Aimbot No Recoil
            if(boolean) {
                // Ativar No Recoil (Remover Recuo)
                // Exemplo de patch direto de memória:
                    // PATCH
                }