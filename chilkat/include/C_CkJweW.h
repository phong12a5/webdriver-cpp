// This is a generated source file for Chilkat version 9.5.0.79
#ifndef _C_CkJweWH
#define _C_CkJweWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"


CK_VISIBLE_PUBLIC HCkJweW CkJweW_Create(void);
CK_VISIBLE_PUBLIC void CkJweW_Dispose(HCkJweW handle);
CK_VISIBLE_PUBLIC void CkJweW_getDebugLogFilePath(HCkJweW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkJweW_putDebugLogFilePath(HCkJweW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_debugLogFilePath(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void CkJweW_getLastErrorHtml(HCkJweW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_lastErrorHtml(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void CkJweW_getLastErrorText(HCkJweW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_lastErrorText(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void CkJweW_getLastErrorXml(HCkJweW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_lastErrorXml(HCkJweW cHandle);
CK_VISIBLE_PUBLIC BOOL CkJweW_getLastMethodSuccess(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void  CkJweW_putLastMethodSuccess(HCkJweW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC int CkJweW_getNumRecipients(HCkJweW cHandle);
CK_VISIBLE_PUBLIC BOOL CkJweW_getPreferCompact(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void  CkJweW_putPreferCompact(HCkJweW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkJweW_getPreferFlattened(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void  CkJweW_putPreferFlattened(HCkJweW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkJweW_getVerboseLogging(HCkJweW cHandle);
CK_VISIBLE_PUBLIC void  CkJweW_putVerboseLogging(HCkJweW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC void CkJweW_getVersion(HCkJweW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_version(HCkJweW cHandle);
CK_VISIBLE_PUBLIC BOOL CkJweW_Decrypt(HCkJweW cHandle, int index, const wchar_t *charset, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_decrypt(HCkJweW cHandle, int index, const wchar_t *charset);
CK_VISIBLE_PUBLIC BOOL CkJweW_DecryptBd(HCkJweW cHandle, int index, HCkBinDataW bd);
CK_VISIBLE_PUBLIC BOOL CkJweW_DecryptSb(HCkJweW cHandle, int index, const wchar_t *charset, HCkStringBuilderW contentSb);
CK_VISIBLE_PUBLIC BOOL CkJweW_Encrypt(HCkJweW cHandle, const wchar_t *content, const wchar_t *charset, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkJweW_encrypt(HCkJweW cHandle, const wchar_t *content, const wchar_t *charset);
CK_VISIBLE_PUBLIC BOOL CkJweW_EncryptBd(HCkJweW cHandle, HCkBinDataW contentBd, HCkStringBuilderW jweSb);
CK_VISIBLE_PUBLIC BOOL CkJweW_EncryptSb(HCkJweW cHandle, HCkStringBuilderW contentSb, const wchar_t *charset, HCkStringBuilderW jweSb);
CK_VISIBLE_PUBLIC int CkJweW_FindRecipient(HCkJweW cHandle, const wchar_t *paramName, const wchar_t *paramValue, BOOL caseSensitive);
CK_VISIBLE_PUBLIC BOOL CkJweW_LoadJwe(HCkJweW cHandle, const wchar_t *jwe);
CK_VISIBLE_PUBLIC BOOL CkJweW_LoadJweSb(HCkJweW cHandle, HCkStringBuilderW sb);
CK_VISIBLE_PUBLIC BOOL CkJweW_SaveLastError(HCkJweW cHandle, const wchar_t *path);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetAad(HCkJweW cHandle, const wchar_t *aad, const wchar_t *charset);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetAadBd(HCkJweW cHandle, HCkBinDataW aad);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetPassword(HCkJweW cHandle, int index, const wchar_t *password);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetPrivateKey(HCkJweW cHandle, int index, HCkPrivateKeyW privKey);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetProtectedHeader(HCkJweW cHandle, HCkJsonObjectW json);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetPublicKey(HCkJweW cHandle, int index, HCkPublicKeyW pubKey);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetRecipientHeader(HCkJweW cHandle, int index, HCkJsonObjectW json);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetUnprotectedHeader(HCkJweW cHandle, HCkJsonObjectW json);
CK_VISIBLE_PUBLIC BOOL CkJweW_SetWrappingKey(HCkJweW cHandle, int index, const wchar_t *encodedKey, const wchar_t *encoding);
#endif
