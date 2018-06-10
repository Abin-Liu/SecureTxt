#ifndef __SECURETXTCRYPTO_H__
#define __SECURETXTCRYPTO_H__

class CSecureTxtCrypto
{
public:
	
	CSecureTxtCrypto();
	~CSecureTxtCrypto();

	void SetPassword(LPCTSTR lpszPassword, BOOL bBackupOldPassword = FALSE);
	void DeletePassword();
	BOOL HasPassword() const;	
	void RestoreLastPassword();

	void Encrypt(LPBYTE pData, DWORD dwLength) const;
	void Decrypt(LPBYTE pData, DWORD dwLength) const;
	
private:
	static void _PasswordTo16Bytes(LPCTSTR lpszPassword, LPBYTE pBuff);
	void _BackupPassword();
	LPBYTE m_pPasswordMd5;
	LPBYTE m_pBackupPasswordMd5;
};

#endif // __SECURETXTCRYPTO_H__