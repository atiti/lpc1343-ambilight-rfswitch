/*----------------------------------------------------------------------------
 *      Name:    cdc_buf.h
 *      Purpose: usb cdc buffer handling
 *      Version: V1.00
 *---------------------------------------------------------------------------*/

#ifndef __CDC_BUF_H__ 
#define __CDC_BUF_H__

#include "projectconfig.h"

// Buffer used for circular fifo
typedef struct _cdc_buffer_t
{
  volatile uint8_t len;
  volatile uint8_t wr_ptr;
  volatile uint8_t rd_ptr;
  uint8_t buf[CFG_USBCDC_BUFFERSIZE];
} cdc_buffer_t;

cdc_buffer_t * cdcGetBuffer(int port);
void           cdcBufferInit(int port);
uint8_t        cdcBufferRead(int port);
uint32_t       cdcBufferReadLen(int port, uint8_t* buf, uint32_t len);
void           cdcBufferWrite(int port, uint8_t data);
void           cdcBufferClearFIFO(int port);
uint8_t        cdcBufferDataPending(int port);

#endif
