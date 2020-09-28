/**
  ******************************************************************************
  * @file    aes_cmac.h
  * @author  MCD Application Team
  * @version V2.0.6
  * @date    25-June-2013
  * @brief   AES in CMAC Mode
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  *****************************************************************************/
/*!  
* \page Tutorial_AES_CMAC AES-CMAC Tutorial
*
* Please remember that before starting to call the Encryption function the context \b requires user 
* initialization. The Key Size, Tag Size, Flags member must be initialized prior to calling the 
*  init function. 
* Before the last call to AES_CMAC_Encrypt_Append the flag E_SK_FINAL_APPEND must be set in the context.
* Look at the each function documentation to see what is needed prior of calling.
*
* The API functions to be used are:
*  - \ref AES_CMAC_Encrypt_Init initialize an \ref AESCMACctx_stt context with key, tag size, flags.
*  - \ref AES_CMAC_Encrypt_Append process the input. It doesn't produce any output.
*    It can be called multiple times but the input size must be multiple of 16. 
*    A last append call is allowed with any, positive, input size, but prior to that the flag 
*    E_SK_FINAL_APPEND must be set.
*  - \ref AES_CMAC_Encrypt_Finish can be called only one time for the finalization process and it will generate
*         the authentication TAG
*
* Here follows an example of AES-128-CMAC authentication, it will process a NIST test vector and generate the 
* authentication TAG.
*
* \code
* #include <stdio.h>
* #include "crypto.h"
* 
* int main()
* {
*   const uint8_t KEY_CMAC[] ={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};  
*   const uint8_t PLAIN_TEXT_CMAC[] = {0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,
*                                     0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51,
*                                     0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef,
*                                     0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10};  
*   uint8_t     TagAesCmac[16] = {0,};
*   int32_t     TagSize=0;
*   uint32_t    error_status = 0;
* 
*   AESCMACctx_stt tst_AesCmac;
*   
*   // Set flag field to default value 
*   tst_AesCmac.mFlags = E_SK_DEFAULT;
* 
*   // Set key size to 16 (correspondng to AES-128)
*   tst_AesCmac.mKeySize = 16;
* 
*   // Pointer to original Key buffer
*   tst_AesCmac.pmKey = (uint8_t *) KEY_CMAC;
* 
*   // Size of returned authentication TAG
*   tst_AesCmac.mTagSize = 16;
* 
*   // Initialize the operation, by passing the key and IV 
*   error_status = AES_CMAC_Encrypt_Init(&tst_AesCmac);
* 
*   // check for initialization errors
*   if(error_status == AES_SUCCESS)
*   {
*     // Message is 4 blocks of 16 bytes each, do first append of 16 bytes     
*     error_status = AES_CMAC_Encrypt_Append(&tst_AesCmac, (uint8_t *) PLAIN_TEXT_CMAC, 16);
*     if(error_status == AES_SUCCESS)
*     {
*       // Do second append of 32 bytes
*       error_status = AES_CMAC_Encrypt_Append(&tst_AesCmac, (uint8_t *) PLAIN_TEXT_CMAC + 16, 32);
*     }            
*     if(error_status == AES_SUCCESS)
*     {
*       // Do last append of the remaining 16 bytes, but first set the flag
*      tst_AesCmac.mFlags |= E_SK_FINAL_APPEND;
*      error_status = AES_CMAC_Encrypt_Append(&tst_AesCmac, (uint8_t *) PLAIN_TEXT_CMAC + 16 + 32, 16);
*      if(error_status == AES_SUCCESS)
*      {
*        // Do the Finalization, write the TAG at the end of the encrypted message
*        error_status = AES_CMAC_Encrypt_Finish(&tst_AesCmac, (uint8_t*) TagAesCmac, &TagSize);
*      }
*    }    
*  }
*  printf("Returned: %d\n", error_status);
*  print_buffer("Returned TAG:",TagAesCmac,TagSize);  
*  return(0);
* }
* \endcode
*/
#ifndef __CRL_AES_CMAC_H__
#define __CRL_AES_CMAC_H__

#ifdef __cplusplus
 extern "C" {
#endif

/** @ingroup AESCMAC
  * @{
  */

typedef struct
{
  uint32_t   mContextId;   /*!< Unique ID of this context. \b Not \b used in current implementation. */  
  SKflags_et mFlags; /*!< 32 bit mFlags, used to perform keyschedule, choose betwen hw/sw/hw+dma and future use */  
  const uint8_t *pmKey; /*!< Pointer to original Key buffer */  
  const uint8_t *pmIv; /*!< Pointer to original Initialization Vector buffer */  
  int32_t   mIvSize; /*!< Size of the Initialization Vector in bytes */  
  uint32_t   amIv[4]; /*!< Temporary result/IV */
  int32_t   mKeySize;   /*!< Key length in bytes */
  uint32_t   amExpKey[CRL_AES_MAX_EXPKEY_SIZE];   /*!< Expanded AES key */
  const uint8_t *pmTag;   /*!< Pointer to Authentication TAG. This value must be set in decryption, and this TAG will be verified */  
  int32_t mTagSize; /*!< Size of the Tag to return. This must be set by the caller prior to calling Init */
} AESCMACctx_stt; /*<! AES context structure for CMAC mode */


int32_t AES_CMAC_Encrypt_Init(AESCMACctx_stt *P_pAESCMACctx);

int32_t AES_CMAC_Encrypt_Append (AESCMACctx_stt *P_pAESCMACctx,
                        const uint8_t *P_pInputBuffer,
                        int32_t        P_inputSize);

int32_t AES_CMAC_Encrypt_Finish (AESCMACctx_stt *P_pAESCMACctx,
                                uint8_t       *P_pOutputBuffer,
                                int32_t       *P_pOutputSize);

int32_t AES_CMAC_Decrypt_Init(AESCMACctx_stt *P_pAESCMACctx);

int32_t AES_CMAC_Decrypt_Append (AESCMACctx_stt *P_pAESCMACctx,
                        const uint8_t *P_pInputBuffer,
                        int32_t        P_inputSize);

int32_t AES_CMAC_Decrypt_Finish (AESCMACctx_stt *P_pAESCMACctx,
                                uint8_t       *P_pOutputBuffer,
                                int32_t       *P_pOutputSize);


 /**
  * @}  
  */
 
#ifdef __cplusplus
}
#endif
 
#endif /* __CRL_AES_CMAC_H__ */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
