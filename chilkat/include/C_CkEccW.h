// This is a generated source file for Chilkat version 9.5.0.79
#ifndef _C_CkEccWH
#define _C_CkEccWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"


CK_VISIBLE_PUBLIC HCkEccW CkEccW_Create(void);
CK_VISIBLE_PUBLIC void CkEccW_Dispose(HCkEccW handle);
CK_VISIBLE_PUBLIC void CkEccW_getDebugLogFilePath(HCkEccW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkEccW_putDebugLogFilePath(HCkEccW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_debugLogFilePath(HCkEccW cHandle);
CK_VISIBLE_PUBLIC void CkEccW_getLastErrorHtml(HCkEccW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_lastErrorHtml(HCkEccW cHandle);
CK_VISIBLE_PUBLIC void CkEccW_getLastErrorText(HCkEccW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_lastErrorText(HCkEccW cHandle);
CK_VISIBLE_PUBLIC void CkEccW_getLastErrorXml(HCkEccW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_lastErrorXml(HCkEccW cHandle);
CK_VISIBLE_PUBLIC BOOL CkEccW_getLastMethodSuccess(HCkEccW cHandle);
CK_VISIBLE_PUBLIC void  CkEccW_putLastMethodSuccess(HCkEccW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkEccW_getVerboseLogging(HCkEccW cHandle);
CK_VISIBLE_PUBLIC void  CkEccW_putVerboseLogging(HCkEccW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC void CkEccW_getVersion(HCkEccW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_version(HCkEccW cHandle);
CK_VISIBLE_PUBLIC HCkPrivateKeyW CkEccW_GenEccKey(HCkEccW cHandle, const wchar_t *curveName, HCkPrngW prng);
CK_VISIBLE_PUBLIC HCkPrivateKeyW CkEccW_GenEccKey2(HCkEccW cHandle, const wchar_t *curveName, const wchar_t *encodedK, const wchar_t *encoding);
CK_VISIBLE_PUBLIC BOOL CkEccW_SaveLastError(HCkEccW cHandle, const wchar_t *path);
CK_VISIBLE_PUBLIC BOOL CkEccW_SharedSecretENC(HCkEccW cHandle, HCkPrivateKeyW privKey, HCkPublicKeyW pubKey, const wchar_t *encoding, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_sharedSecretENC(HCkEccW cHandle, HCkPrivateKeyW privKey, HCkPublicKeyW pubKey, const wchar_t *encoding);
CK_VISIBLE_PUBLIC BOOL CkEccW_SignHashENC(HCkEccW cHandle, const wchar_t *encodedHash, const wchar_t *encoding, HCkPrivateKeyW privkey, HCkPrngW prng, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkEccW_signHashENC(HCkEccW cHandle, const wchar_t *encodedHash, const wchar_t *encoding, HCkPrivateKeyW privkey, HCkPrngW prng);
CK_VISIBLE_PUBLIC int CkEccW_VerifyHashENC(HCkEccW cHandle, const wchar_t *encodedHash, const wchar_t *encodedSig, const wchar_t *encoding, HCkPublicKeyW pubkey);
#endif
