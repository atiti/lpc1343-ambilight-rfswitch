/**************************************************************************/
/*! 
    @file     main.c
    @author   K. Townsend (microBuilder.eu)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2010, microBuilder SARL
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#include "projectconfig.h"
#include "sysinit.h"

#include "core/gpio/gpio.h"
#include "core/systick/systick.h"

#include "core/usbcdc/cdcuser.h"
static char usbcdcBuf [64];

/**************************************************************************/
int main(void)
{
  // Configure cpu and mandatory peripherals
  systemInit();
  int c = 0;
  uint32_t currentSecond, lastSecond;
  currentSecond = lastSecond = 0;

  // Toggle LED once per second and constantly check CLI input
  while (1)
  {
    // Get the number of seconds the CPU has been active
    // If the value has changed we've advanced at least 1 second
    currentSecond = systickGetSecondsActive();
    if (currentSecond != lastSecond)
    {
      lastSecond = currentSecond;
      // Toggle the LED
/*      if (gpioGetValue(CFG_LED_PORT, CFG_LED_PIN) == CFG_LED_OFF)
      {
        gpioSetValue (CFG_LED_PORT, CFG_LED_PIN, CFG_LED_ON); 
      }
      else
      {
        gpioSetValue (CFG_LED_PORT, CFG_LED_PIN, CFG_LED_OFF); 
      }
*/
      gpioSetValue(CFG_LED_PORT, c, CFG_LED_OFF);
      c++;
      if (c > 3) c = 0;
      gpioSetValue(CFG_LED_PORT, c, CFG_LED_ON);
      ser_puts(CDC_SERIAL_PORT_1, "hello port 1\r\n");
      ser_puts(CDC_SERIAL_PORT_2, "hello port 2\r\n");
      ser_puts(CDC_SERIAL_PORT_3, "hello port 3\r\n");

    }

    int  numBytesToRead, numBytesRead, numAvailByte;

    CDC_OutBufAvailChar (CDC_SERIAL_PORT_1, &numAvailByte);
    if (numAvailByte > 0) {
      gpioSetValue(CFG_LED_PORT, 0, CFG_LED_ON);
      numBytesToRead = numAvailByte > 64 ? 64 : numAvailByte;
      numBytesRead = CDC_RdOutBuf (CDC_SERIAL_PORT_1, &usbcdcBuf[0], &numBytesToRead);
      ser_puts(CDC_SERIAL_PORT_1, usbcdcBuf);
    }
    CDC_OutBufAvailChar (CDC_SERIAL_PORT_2, &numAvailByte);
    if (numAvailByte > 0) {
      gpioSetValue(CFG_LED_PORT, 1, CFG_LED_ON);
      numBytesToRead = numAvailByte > 64 ? 64 : numAvailByte;
      numBytesRead = CDC_RdOutBuf (CDC_SERIAL_PORT_2, &usbcdcBuf[0], &numBytesToRead);
      ser_puts(CDC_SERIAL_PORT_2, usbcdcBuf);
    }
    CDC_OutBufAvailChar (CDC_SERIAL_PORT_3, &numAvailByte);
    if (numAvailByte > 0) {
      gpioSetValue(CFG_LED_PORT, 2, CFG_LED_ON);
      numBytesToRead = numAvailByte > 64 ? 64 : numAvailByte;
      numBytesRead = CDC_RdOutBuf (CDC_SERIAL_PORT_3, &usbcdcBuf[0], &numBytesToRead);
      ser_puts(CDC_SERIAL_PORT_3, usbcdcBuf);
    }

/*    CDC_OutBufAvailChar (CDC_SERIAL_PORT_2, &numAvailByte);
    if (numAvailByte > 0)
    {
      numBytesToRead = numAvailByte > 64 ? 64 : numAvailByte;
      numBytesRead = CDC_RdOutBuf (CDC_SERIAL_PORT_2, &usbcdcBuf[0], &numBytesToRead);
      puts(usbcdcBuf);
      //CDC_WrOutBuf(&usbcdcBuf[0], &numBytesToRead);
      int i;
      for (i = 0; i < numBytesRead; i++)
      {
*/
      // Toggle the LED
/*      if (gpioGetValue(CFG_LED_PORT, CFG_LED_PIN) == CFG_LED_OFF)
      {
        gpioSetValue (CFG_LED_PORT, CFG_LED_PIN, CFG_LED_ON);
      }
      else
      {
        gpioSetValue (CFG_LED_PORT, CFG_LED_PIN, CFG_LED_OFF);
      }
      }
    }
*/

  }

  return 0;
}
