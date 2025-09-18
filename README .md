# Secure File Transfer Simulation
A Windows-based simulation project that demonstrates cryptography, system-level programming, and **Dynamic Link Library (DLL)** integration using the **Win32 SDK**.

---

## Description
This project implements a **secure file transfer simulation** with file-based encryption and decryption.  
The cryptographic logic (Caesar, XOR, and Vigenère ciphers) is encapsulated inside a reusable **DLL (`EncryptDecrypt.dll`)**, which can be dynamically loaded by client applications.  

Instead of standard C library functions, the project makes use of **Windows system calls (Win32 API)** for file handling, showcasing **low-level programming** and secure modular development.

---

## Key Features
- **File-based Encryption & Decryption**
  - Encrypt and decrypt text files securely.
- **Multiple Cryptographic Algorithms**
  - **Caesar Cipher** — character shift substitution.  
  - **XOR Cipher** — bitwise XOR with user-defined key.  
  - **Vigenère Cipher** — polyalphabetic substitution with repeating key.  
- **System-Level File Handling**
  - Uses low-level system calls (`open`, `_read`, `_write`, `_close`) or Win32 APIs.
- **DLL Integration**
  - Exports encryption/decryption functions via a reusable DLL (`EncryptDecrypt.dll`).  
  - Client applications load functions dynamically at runtime using `LoadLibrary` and `GetProcAddress`.  
- **Learning Outcome**
  - Hands-on with DLL creation, modular programming, Windows API, and cryptographic logic.  

---

## Technologies Used
- **Language**: C (Win32 SDK)  
- **Platform**: Windows (tested on Windows 10/11)  
- **IDE/Tools**: Visual Studio / MinGW  
- **APIs**: Windows API (`CreateFile`, `ReadFile`, `WriteFile`, `CloseHandle`)  

---

## Getting Started

### Dependencies
- Windows OS (Windows 10 or later)  
- Visual Studio (MSVC) or MinGW for compilation  

### Compiling the DLL
1. Open the project in Visual Studio.  
2. Build the project as a **Dynamic Link Library (DLL)**.  
   - Output will be `EncryptDecrypt.dll`.  

### Compiling the Client
1. Create a client application (e.g., `client.c`).  
2. Dynamically load the DLL:
   ```cpp
   HINSTANCE hdll = LoadLibrary("EncryptDecrypt.dll");
   FARPROC fp = GetProcAddress(hdll, "Encrypt_XOR_Cipher");
   ```
3. Call DLL functions for encryption/decryption.

---


---

## Help
- Ensure `EncryptDecrypt.dll` is located in the same directory as your client executable (`.exe`).  
- Use ASCII characters as keys for XOR and Vigenère.  
- For Caesar cipher, provide an integer shift value.  
- Run with administrator privileges if file access errors occur.  

---

## Authors

- **Ankita Patil** 

---

## Version History
- **0.2** — Added Vigenère cipher, improved file handling.  
- **0.1** — Initial release with Caesar and XOR ciphers.  

---

## License
This project is licensed under the MIT License — see the [LICENSE.md](LICENSE.md) file for details.  

---

## Acknowledgments
- Marvellous Infosystems — Training and guidance.  
- Windows API documentation — Microsoft Docs.  
