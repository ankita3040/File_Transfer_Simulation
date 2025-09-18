#include<windows.h>
//#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
//#include<unistd.h> error yeil may be ...remove if necessry

//Replace open with _open
//Replace open woth _read

#define MAX_SIZE 1024

// Caesar Cipher
extern "C" declspec(dllexport) void Encrypt_XOR_Cipher (char* , char*,char) 
void Encrypt_XOR_Cipher(char *Src,char *Dest, char key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0;
    char Buffer [MAX_SIZE] = {'\0'};

    fdSrc = open(Src,O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    fdDest = open(Dest,O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdSrc == -1)
    {
        printf("Unable to open destination file \n");
        return;
    }

    while ((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%d",iRet);
        for(i  = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ key;
        }

        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
    
}
extern "C" declspec(dllexport) void Encrypt_Caesar_Cipher (char* , char*,int) 
void Encrypt_Caesar_Cipher(char *Src,char *Dest, int key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0;
    char Buffer [MAX_SIZE] = {'\0'};

    fdSrc = open(Src,O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    fdDest = open(Dest,O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdSrc == -1)
    {
        printf("Unable to open destination file \n");
        return;
    }

    while ((iRet = read(fdSrc,Buffer,sizeof(MAX_SIZE))) > 0)
    {
        printf("%d",iRet);
        for(i  = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + key) % 256;
        }

        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);  

}

extern "C" declspec(dllexport) void Decrypt_XOR_Cipher (char* , char*,char)
void Decrypt_XOR_Cipher(char *Src,char *Dest, char key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0;
    char Buffer [MAX_SIZE] = {'\0'};

    fdSrc = open(Src,O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    fdDest = open(Dest,O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdSrc == -1)
    {
        printf("Unable to open destination file \n");
        return;
    }

    while ((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%d",iRet);
        for(i  = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ key;
        }

        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);
    
}

extern "C" declspec(dllexport) void Decrypt_Caesar_Cipher (char* , char*,int)
void Decrypt_Caesar_Cipher(char *Src,char *Dest, int key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0;
    char Buffer [MAX_SIZE] = {'\0'};

    fdSrc = open(Src,O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    fdDest = open(Dest,O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdSrc == -1)
    {
        printf("Unable to open destination file \n");
        return;
    }

    while ((iRet = read(fdSrc,Buffer,sizeof(MAX_SIZE))) > 0)
    {
        printf("%d",iRet);
        for(i  = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - key) % 256;
        }

        write(fdDest,Buffer,iRet);
    }

    close(fdSrc);
    close(fdDest);  

}
// Vigenère Encryption
extern "C" declspec(dllexport) void Vigenere_Encrypt_Cipher (char* , char*,char)
void Vigenere_Encrypt_Cipher(char *Src, char *Dest, const char *key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0, j = 0;
    char Buffer[MAX_SIZE] = {'\0'};
    int keyLen = strlen(key);

    fdSrc = _open(Src, O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file\n");
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdDest == -1)
    {
        printf("Unable to open destination file\n");
        _close(fdSrc);
        return;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + key[j % keyLen]) % 256;  
            j++;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

// Vigenère Decryption
extern "C" declspec(dllexport) void Vigenere_Decrypt_Cipher (char* , char*,char)
void Vigenere_Decrypt_Cipher(char *Src, char *Dest, const char *key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0, i = 0, j = 0;
    char Buffer[MAX_SIZE] = {'\0'};
    int keyLen = strlen(key);

    fdSrc = _open(Src, O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file\n");
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdDest == -1)
    {
        printf("Unable to open destination file\n");
        _close(fdSrc);
        return;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for(i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - key[j % keyLen] + 256) % 256;  
            j++;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}
