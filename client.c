//EncryptDecryptClient.cpp

#include<windows.h>
#include "pch.h"
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fcntl.h>
//#include<unistd.h> error yeil may be ...remove if necessry

//Replace open with _open
//Replace open woth _read

typedef void (*FPTR) (char* , char*,char);

int main()
{
    HINSTANCE hdll = LoadLibrary("EncryptDecrypt.dll");
    if(hdll == NULL)
    {
        std::cout<<"Unable to load library\n";
    }

    FPTR fp1 = (FPTR) GetProcAddress(hdll,Encrypt_XOR_Cipher);
    if(fp1 == NULL)
    {
        std::cout<<"Unable to get address of function\n";
    }

    fp1("input.txt","Output.txt",c);

    FPTR fp2 = (FPTR) GetProcAddress(hdll,Encrypt_Caesar_Cipher);
    if(fp2 == NULL)
    {
        std::cout<<"Unable to get address of function\n";
    }

    fp2("input.txt","Output.txt",c);
}