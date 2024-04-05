#ifndef _CRYPT_H_
#define _CRYPT_H_

//#ifndef WIN32
//#include <arpa/inet.h>
//#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "des.h"

#define ByteSwap32(l) (((l) >> 24) |             \
                       (((l)&0x00ff0000) >> 8) | \
                       (((l)&0x0000ff00) << 8) | \
                       ((l) << 24))

#define BigLittleSwap32(x) ((((unsigned int)(x)&0xff000000) >> 24) | \
                            (((unsigned int)(x)&0x00ff0000) >> 8) |  \
                            (((unsigned int)(x)&0x0000ff00) << 8) |  \
                            (((unsigned int)(x)&0x000000ff) << 24))

#define OS_htonl(x) BigLittleSwap32(x)
#define OS_ntohl(x) ByteSwap32(x)

#define IN
#define OUT

static unsigned char g_key[] = "1231&*5324253245kb31&*5\
376738687&%&khjhoq,mkdjfa;lsdkjf;laskdnbkl\
oielkdkjfs@@*&^trytjtyu;lk';slfavl,;a,;l\
,;alasdfasdfasdfa*8!#%";

static char *GetFileBuf(const char *pFile, unsigned int *pOutLen)
{
    char *pBuf = NULL;
    size_t lFileSize = 0;
    FILE *fp = fopen(pFile, "rb");

    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        lFileSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        //pBuf = new char[lFileSize + 1];
        pBuf = (char *)malloc(sizeof(char) * (lFileSize + 1));
        if (pBuf)
        {
            if (fread(pBuf, 1, lFileSize, fp) != lFileSize)
            {
                free(pBuf);
                pBuf = NULL;
            }
            else
            {
                *pOutLen = lFileSize;
                pBuf[lFileSize] = 0x00;
            }
        }
        fclose(fp);
    }
    return pBuf;
}

static void get_des_key(unsigned char *out_key)
{
    out_key[0] = g_key[47];
    out_key[1] = g_key[92];
    out_key[2] = g_key[210];
    out_key[3] = g_key[166];
    out_key[4] = g_key[146];
    out_key[5] = g_key[202];
    out_key[6] = g_key[212];
    out_key[7] = g_key[47];
    out_key[8] = 0;
}

static unsigned char *DeCrptBuf(IN unsigned char *pBuf, IN int iBufLen, OUT unsigned int *iOutBufLen)
{
    unsigned char _key[9] = {0};
    unsigned char *pNewBuf = NULL;
    unsigned char *pStart = pBuf;
    unsigned int iWriteLen = *(unsigned int *)pStart;
    iWriteLen = OS_ntohl(iWriteLen);

    pStart += sizeof(unsigned int);
    iBufLen -= sizeof(iBufLen);
    //iBufLen = (iBufLen/8+1)*8;
    get_des_key(_key);

    if (iWriteLen <= iBufLen /*&& iBufLen %8 ==0 */)
    {
        //pNewBuf = new unsigned char[iBufLen + 1];
        pNewBuf = (unsigned char *)malloc(sizeof(unsigned char) * (iBufLen + 1));
        if (pNewBuf)
        {
            _DESString(_key, pStart, pNewBuf, iBufLen);
            pNewBuf[iBufLen] = 0x00;
            *iOutBufLen = iWriteLen;
        }
    }
    return pNewBuf;
}
static unsigned char *EnCrptBuf(IN unsigned char *pBuf, IN unsigned int iBufLen, OUT unsigned int *iOutBufLen)
{
    unsigned char _key[9] = {0};
    unsigned int iLen = iBufLen;
    unsigned char *pNewBuf = NULL;
    if (pBuf)
    {
        unsigned int iLen2 = ((iLen - 1) / 8 + 1) * 8 + 4;
        //pNewBuf = new unsigned char[iLen2];
        pNewBuf = (unsigned char *)malloc(sizeof(unsigned char) * (iLen2 + 1));
        if (pNewBuf)
        {
            get_des_key(_key);
            iLen = OS_htonl(iLen);
            memcpy(pNewBuf, &iLen, sizeof(int));
            DESString(_key, pBuf, pNewBuf + 4, iLen2 - 4);
            *iOutBufLen = iLen2;
        }
    }
    return pNewBuf;
}
static unsigned char *EnCrptBufNew(IN unsigned char *pBuf, IN unsigned int iBufLen,
                                   IN OUT unsigned char *pOutBuf, IN unsigned int iEnCrptBufLen)
{
    unsigned char _key[9] = {0};
    unsigned int iLen = iBufLen;
    unsigned char *pNewBuf = NULL;
    if (pBuf && pOutBuf)
    {
        unsigned int iLen2 = iEnCrptBufLen;
        pNewBuf = pOutBuf;
        if (pNewBuf)
        {
            iLen = OS_htonl(iLen);
            memcpy(pNewBuf, &iLen, sizeof(int));
            get_des_key(_key);
            DESString(_key, pBuf, pNewBuf + 4, iLen2 - 4);
        }
    }
    return pNewBuf;
}
static bool DeCrptFile(IN char *pFileIn, IN char *pFileOut)
{
    bool bRet = false;
    unsigned int iLen;
    unsigned int iWriteLen;
    unsigned char *pBuf = (unsigned char *)GetFileBuf(pFileIn, &iLen);
    if (pBuf)
    {
        unsigned char *pNewBuf = DeCrptBuf(pBuf, iLen, &iWriteLen);
        if (pNewBuf)
        {
            FILE *fp = fopen(pFileOut, "wb");
            if (fp)
            {
                fwrite(pNewBuf, 1, iWriteLen, fp);
                fclose(fp);
                bRet = true;
            }
            free(pNewBuf);
        }
        free(pBuf);
    }
    return bRet;
}
static bool EnCrptFile(IN char *pFileIn, IN char *pFileOut)
{
    unsigned char _key[9] = {0};
    bool bRet = false;
    unsigned int iLen;
    unsigned char *pBuf = (unsigned char *)GetFileBuf(pFileIn, &iLen);
    if (pBuf)
    {
        int iLen2 = ((iLen - 1) / 8 + 1) * 8 + 4;
        unsigned char *pNewBuf = (unsigned char *)malloc(sizeof(char)*(iLen2+1));//new unsigned char[iLen2];
        if (pNewBuf)
        {
            iLen = OS_htonl(iLen);
            memcpy(pNewBuf, &iLen, sizeof(int));
            get_des_key(_key);
            DESString(_key, pBuf, pNewBuf + 4, iLen2 - 4);
            FILE *fp = fopen(pFileOut, "wb");
            if (fp)
            {
                fwrite(pNewBuf, 1, iLen2, fp);
                fclose(fp);
                bRet = true;
            }
            free(pNewBuf);
        }
        free(pBuf);
    }
    return bRet;
}
static unsigned char *DeCrptFileToBuf(IN char *pFileIn, OUT int *iOutBufLen)
{
    unsigned char *pNewBuf = NULL;
    unsigned int iLen;
    unsigned char *pBuf = (unsigned char *)GetFileBuf(pFileIn, &iLen);
    if (pBuf)
    {
        pNewBuf = DeCrptBuf(pBuf, iLen, (unsigned int *)iOutBufLen);
        free(pBuf);
    }
    return pNewBuf;
}

#endif