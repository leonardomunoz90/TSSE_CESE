/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_ports.h"

static const char* CMockString_addr = "addr";
static const char* CMockString_buf = "buf";
static const char* CMockString_data = "data";
static const char* CMockString_readI2C_Data = "readI2C_Data";
static const char* CMockString_sendCMD = "sendCMD";
static const char* CMockString_sendI2C_CMD = "sendI2C_CMD";
static const char* CMockString_sendStringUart = "sendStringUart";
static const char* CMockString_size = "size";

typedef struct _CMOCK_sendI2C_CMD_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_addr;
  uint8_t* Expected_sendCMD;
  int8_t Expected_size;
  int Expected_sendCMD_Depth;
  char ReturnThruPtr_sendCMD_Used;
  uint8_t* ReturnThruPtr_sendCMD_Val;
  size_t ReturnThruPtr_sendCMD_Size;
  char IgnoreArg_addr;
  char IgnoreArg_sendCMD;
  char IgnoreArg_size;

} CMOCK_sendI2C_CMD_CALL_INSTANCE;

typedef struct _CMOCK_readI2C_Data_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_addr;
  uint8_t* Expected_data;
  int8_t Expected_size;
  int Expected_data_Depth;
  char ReturnThruPtr_data_Used;
  uint8_t* ReturnThruPtr_data_Val;
  size_t ReturnThruPtr_data_Size;
  char IgnoreArg_addr;
  char IgnoreArg_data;
  char IgnoreArg_size;

} CMOCK_readI2C_Data_CALL_INSTANCE;

typedef struct _CMOCK_sendStringUart_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int CallOrder;
  uint8_t* Expected_buf;
  uint8_t Expected_size;
  int Expected_buf_Depth;
  char ReturnThruPtr_buf_Used;
  uint8_t* ReturnThruPtr_buf_Val;
  size_t ReturnThruPtr_buf_Size;
  char IgnoreArg_buf;
  char IgnoreArg_size;

} CMOCK_sendStringUart_CALL_INSTANCE;

static struct mock_portsInstance
{
  char sendI2C_CMD_IgnoreBool;
  uint8_t sendI2C_CMD_FinalReturn;
  char sendI2C_CMD_CallbackBool;
  CMOCK_sendI2C_CMD_CALLBACK sendI2C_CMD_CallbackFunctionPointer;
  int sendI2C_CMD_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE sendI2C_CMD_CallInstance;
  char readI2C_Data_IgnoreBool;
  uint8_t readI2C_Data_FinalReturn;
  char readI2C_Data_CallbackBool;
  CMOCK_readI2C_Data_CALLBACK readI2C_Data_CallbackFunctionPointer;
  int readI2C_Data_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE readI2C_Data_CallInstance;
  char sendStringUart_IgnoreBool;
  char sendStringUart_CallbackBool;
  CMOCK_sendStringUart_CALLBACK sendStringUart_CallbackFunctionPointer;
  int sendStringUart_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE sendStringUart_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_ports_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.sendI2C_CMD_CallInstance;
  if (Mock.sendI2C_CMD_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_sendI2C_CMD);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.sendI2C_CMD_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.readI2C_Data_CallInstance;
  if (Mock.readI2C_Data_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_readI2C_Data);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.readI2C_Data_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.sendStringUart_CallInstance;
  if (Mock.sendStringUart_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_sendStringUart);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.sendStringUart_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_ports_Init(void)
{
  mock_ports_Destroy();
}

void mock_ports_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint8_t sendI2C_CMD(uint8_t addr, uint8_t* sendCMD, int8_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_sendI2C_CMD);
  cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sendI2C_CMD_CallInstance);
  Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemNext(Mock.sendI2C_CMD_CallInstance);
  if (Mock.sendI2C_CMD_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.sendI2C_CMD_FinalReturn;
    Mock.sendI2C_CMD_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.sendI2C_CMD_CallbackBool &&
      Mock.sendI2C_CMD_CallbackFunctionPointer != NULL)
  {
    uint8_t cmock_cb_ret = Mock.sendI2C_CMD_CallbackFunctionPointer(addr, sendCMD, size, Mock.sendI2C_CMD_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_addr)
  {
    UNITY_SET_DETAILS(CMockString_sendI2C_CMD,CMockString_addr);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_addr, addr, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_sendCMD)
  {
    UNITY_SET_DETAILS(CMockString_sendI2C_CMD,CMockString_sendCMD);
    if (cmock_call_instance->Expected_sendCMD == NULL)
      { UNITY_TEST_ASSERT_NULL(sendCMD, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_sendCMD, sendCMD, cmock_call_instance->Expected_sendCMD_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_sendI2C_CMD,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.sendI2C_CMD_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.sendI2C_CMD_CallbackFunctionPointer(addr, sendCMD, size, Mock.sendI2C_CMD_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_sendCMD_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(sendCMD, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)sendCMD, (void*)cmock_call_instance->ReturnThruPtr_sendCMD_Val,
      cmock_call_instance->ReturnThruPtr_sendCMD_Size);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_sendI2C_CMD(CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance, uint8_t addr, uint8_t* sendCMD, int sendCMD_Depth, int8_t size);
void CMockExpectParameters_sendI2C_CMD(CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance, uint8_t addr, uint8_t* sendCMD, int sendCMD_Depth, int8_t size)
{
  cmock_call_instance->Expected_addr = addr;
  cmock_call_instance->IgnoreArg_addr = 0;
  cmock_call_instance->Expected_sendCMD = sendCMD;
  cmock_call_instance->Expected_sendCMD_Depth = sendCMD_Depth;
  cmock_call_instance->IgnoreArg_sendCMD = 0;
  cmock_call_instance->ReturnThruPtr_sendCMD_Used = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void sendI2C_CMD_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendI2C_CMD_CALL_INSTANCE));
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemChain(Mock.sendI2C_CMD_CallInstance, cmock_guts_index);
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.sendI2C_CMD_IgnoreBool = (char)1;
}

void sendI2C_CMD_CMockStopIgnore(void)
{
  if(Mock.sendI2C_CMD_IgnoreBool)
    Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemNext(Mock.sendI2C_CMD_CallInstance);
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
}

void sendI2C_CMD_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendI2C_CMD_CALL_INSTANCE));
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemChain(Mock.sendI2C_CMD_CallInstance, cmock_guts_index);
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void sendI2C_CMD_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t addr, uint8_t* sendCMD, int8_t size, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendI2C_CMD_CALL_INSTANCE));
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemChain(Mock.sendI2C_CMD_CallInstance, cmock_guts_index);
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_sendI2C_CMD(cmock_call_instance, addr, sendCMD, 1, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void sendI2C_CMD_AddCallback(CMOCK_sendI2C_CMD_CALLBACK Callback)
{
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  Mock.sendI2C_CMD_CallbackBool = (char)1;
  Mock.sendI2C_CMD_CallbackFunctionPointer = Callback;
}

void sendI2C_CMD_Stub(CMOCK_sendI2C_CMD_CALLBACK Callback)
{
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  Mock.sendI2C_CMD_CallbackBool = (char)0;
  Mock.sendI2C_CMD_CallbackFunctionPointer = Callback;
}

void sendI2C_CMD_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t addr, uint8_t* sendCMD, int sendCMD_Depth, int8_t size, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendI2C_CMD_CALL_INSTANCE));
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendI2C_CMD_CallInstance = CMock_Guts_MemChain(Mock.sendI2C_CMD_CallInstance, cmock_guts_index);
  Mock.sendI2C_CMD_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_sendI2C_CMD(cmock_call_instance, addr, sendCMD, sendCMD_Depth, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void sendI2C_CMD_CMockReturnMemThruPtr_sendCMD(UNITY_LINE_TYPE cmock_line, uint8_t* sendCMD, size_t cmock_size)
{
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendI2C_CMD_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_sendCMD_Used = 1;
  cmock_call_instance->ReturnThruPtr_sendCMD_Val = sendCMD;
  cmock_call_instance->ReturnThruPtr_sendCMD_Size = cmock_size;
}

void sendI2C_CMD_CMockIgnoreArg_addr(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendI2C_CMD_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_addr = 1;
}

void sendI2C_CMD_CMockIgnoreArg_sendCMD(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendI2C_CMD_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_sendCMD = 1;
}

void sendI2C_CMD_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_sendI2C_CMD_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendI2C_CMD_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendI2C_CMD_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

uint8_t readI2C_Data(uint8_t addr, uint8_t* data, int8_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_readI2C_Data);
  cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.readI2C_Data_CallInstance);
  Mock.readI2C_Data_CallInstance = CMock_Guts_MemNext(Mock.readI2C_Data_CallInstance);
  if (Mock.readI2C_Data_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.readI2C_Data_FinalReturn;
    Mock.readI2C_Data_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.readI2C_Data_CallbackBool &&
      Mock.readI2C_Data_CallbackFunctionPointer != NULL)
  {
    uint8_t cmock_cb_ret = Mock.readI2C_Data_CallbackFunctionPointer(addr, data, size, Mock.readI2C_Data_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_addr)
  {
    UNITY_SET_DETAILS(CMockString_readI2C_Data,CMockString_addr);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_addr, addr, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_data)
  {
    UNITY_SET_DETAILS(CMockString_readI2C_Data,CMockString_data);
    if (cmock_call_instance->Expected_data == NULL)
      { UNITY_TEST_ASSERT_NULL(data, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_data, data, cmock_call_instance->Expected_data_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_readI2C_Data,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_INT8(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.readI2C_Data_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.readI2C_Data_CallbackFunctionPointer(addr, data, size, Mock.readI2C_Data_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_data_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(data, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)data, (void*)cmock_call_instance->ReturnThruPtr_data_Val,
      cmock_call_instance->ReturnThruPtr_data_Size);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_readI2C_Data(CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance, uint8_t addr, uint8_t* data, int data_Depth, int8_t size);
void CMockExpectParameters_readI2C_Data(CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance, uint8_t addr, uint8_t* data, int data_Depth, int8_t size)
{
  cmock_call_instance->Expected_addr = addr;
  cmock_call_instance->IgnoreArg_addr = 0;
  cmock_call_instance->Expected_data = data;
  cmock_call_instance->Expected_data_Depth = data_Depth;
  cmock_call_instance->IgnoreArg_data = 0;
  cmock_call_instance->ReturnThruPtr_data_Used = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void readI2C_Data_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readI2C_Data_CALL_INSTANCE));
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readI2C_Data_CallInstance = CMock_Guts_MemChain(Mock.readI2C_Data_CallInstance, cmock_guts_index);
  Mock.readI2C_Data_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.readI2C_Data_IgnoreBool = (char)1;
}

void readI2C_Data_CMockStopIgnore(void)
{
  if(Mock.readI2C_Data_IgnoreBool)
    Mock.readI2C_Data_CallInstance = CMock_Guts_MemNext(Mock.readI2C_Data_CallInstance);
  Mock.readI2C_Data_IgnoreBool = (char)0;
}

void readI2C_Data_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readI2C_Data_CALL_INSTANCE));
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readI2C_Data_CallInstance = CMock_Guts_MemChain(Mock.readI2C_Data_CallInstance, cmock_guts_index);
  Mock.readI2C_Data_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void readI2C_Data_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t addr, uint8_t* data, int8_t size, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readI2C_Data_CALL_INSTANCE));
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readI2C_Data_CallInstance = CMock_Guts_MemChain(Mock.readI2C_Data_CallInstance, cmock_guts_index);
  Mock.readI2C_Data_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_readI2C_Data(cmock_call_instance, addr, data, 1, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void readI2C_Data_AddCallback(CMOCK_readI2C_Data_CALLBACK Callback)
{
  Mock.readI2C_Data_IgnoreBool = (char)0;
  Mock.readI2C_Data_CallbackBool = (char)1;
  Mock.readI2C_Data_CallbackFunctionPointer = Callback;
}

void readI2C_Data_Stub(CMOCK_readI2C_Data_CALLBACK Callback)
{
  Mock.readI2C_Data_IgnoreBool = (char)0;
  Mock.readI2C_Data_CallbackBool = (char)0;
  Mock.readI2C_Data_CallbackFunctionPointer = Callback;
}

void readI2C_Data_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t addr, uint8_t* data, int data_Depth, int8_t size, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readI2C_Data_CALL_INSTANCE));
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readI2C_Data_CallInstance = CMock_Guts_MemChain(Mock.readI2C_Data_CallInstance, cmock_guts_index);
  Mock.readI2C_Data_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_readI2C_Data(cmock_call_instance, addr, data, data_Depth, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void readI2C_Data_CMockReturnMemThruPtr_data(UNITY_LINE_TYPE cmock_line, uint8_t* data, size_t cmock_size)
{
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.readI2C_Data_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_data_Used = 1;
  cmock_call_instance->ReturnThruPtr_data_Val = data;
  cmock_call_instance->ReturnThruPtr_data_Size = cmock_size;
}

void readI2C_Data_CMockIgnoreArg_addr(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.readI2C_Data_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_addr = 1;
}

void readI2C_Data_CMockIgnoreArg_data(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.readI2C_Data_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_data = 1;
}

void readI2C_Data_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_readI2C_Data_CALL_INSTANCE* cmock_call_instance = (CMOCK_readI2C_Data_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.readI2C_Data_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

void sendStringUart(uint8_t* buf, uint8_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_sendStringUart);
  cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sendStringUart_CallInstance);
  Mock.sendStringUart_CallInstance = CMock_Guts_MemNext(Mock.sendStringUart_CallInstance);
  if (Mock.sendStringUart_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.sendStringUart_CallbackBool &&
      Mock.sendStringUart_CallbackFunctionPointer != NULL)
  {
    Mock.sendStringUart_CallbackFunctionPointer(buf, size, Mock.sendStringUart_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_buf)
  {
    UNITY_SET_DETAILS(CMockString_sendStringUart,CMockString_buf);
    if (cmock_call_instance->Expected_buf == NULL)
      { UNITY_TEST_ASSERT_NULL(buf, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_buf, buf, cmock_call_instance->Expected_buf_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_sendStringUart,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.sendStringUart_CallbackFunctionPointer != NULL)
  {
    Mock.sendStringUart_CallbackFunctionPointer(buf, size, Mock.sendStringUart_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_buf_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(buf, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)buf, (void*)cmock_call_instance->ReturnThruPtr_buf_Val,
      cmock_call_instance->ReturnThruPtr_buf_Size);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_sendStringUart(CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance, uint8_t* buf, int buf_Depth, uint8_t size);
void CMockExpectParameters_sendStringUart(CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance, uint8_t* buf, int buf_Depth, uint8_t size)
{
  cmock_call_instance->Expected_buf = buf;
  cmock_call_instance->Expected_buf_Depth = buf_Depth;
  cmock_call_instance->IgnoreArg_buf = 0;
  cmock_call_instance->ReturnThruPtr_buf_Used = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void sendStringUart_CMockIgnore(void)
{
  Mock.sendStringUart_IgnoreBool = (char)1;
}

void sendStringUart_CMockStopIgnore(void)
{
  Mock.sendStringUart_IgnoreBool = (char)0;
}

void sendStringUart_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendStringUart_CALL_INSTANCE));
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendStringUart_CallInstance = CMock_Guts_MemChain(Mock.sendStringUart_CallInstance, cmock_guts_index);
  Mock.sendStringUart_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void sendStringUart_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t* buf, uint8_t size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendStringUart_CALL_INSTANCE));
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendStringUart_CallInstance = CMock_Guts_MemChain(Mock.sendStringUart_CallInstance, cmock_guts_index);
  Mock.sendStringUart_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_sendStringUart(cmock_call_instance, buf, 1, size);
}

void sendStringUart_AddCallback(CMOCK_sendStringUart_CALLBACK Callback)
{
  Mock.sendStringUart_IgnoreBool = (char)0;
  Mock.sendStringUart_CallbackBool = (char)1;
  Mock.sendStringUart_CallbackFunctionPointer = Callback;
}

void sendStringUart_Stub(CMOCK_sendStringUart_CALLBACK Callback)
{
  Mock.sendStringUart_IgnoreBool = (char)0;
  Mock.sendStringUart_CallbackBool = (char)0;
  Mock.sendStringUart_CallbackFunctionPointer = Callback;
}

void sendStringUart_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, uint8_t* buf, int buf_Depth, uint8_t size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendStringUart_CALL_INSTANCE));
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sendStringUart_CallInstance = CMock_Guts_MemChain(Mock.sendStringUart_CallInstance, cmock_guts_index);
  Mock.sendStringUart_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_sendStringUart(cmock_call_instance, buf, buf_Depth, size);
}

void sendStringUart_CMockReturnMemThruPtr_buf(UNITY_LINE_TYPE cmock_line, uint8_t* buf, size_t cmock_size)
{
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendStringUart_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_buf_Used = 1;
  cmock_call_instance->ReturnThruPtr_buf_Val = buf;
  cmock_call_instance->ReturnThruPtr_buf_Size = cmock_size;
}

void sendStringUart_CMockIgnoreArg_buf(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendStringUart_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_buf = 1;
}

void sendStringUart_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_sendStringUart_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendStringUart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.sendStringUart_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

