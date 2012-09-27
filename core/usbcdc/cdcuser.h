/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 *      Name:    cdcuser.h
 *      Purpose: USB Communication Device Class User module Definitions
 *      Version: V1.10
 *----------------------------------------------------------------------------
 *      This software is supplied "AS IS" without any warranties, express,
 *      implied or statutory, including but not limited to the implied
 *      warranties of fitness for purpose, satisfactory quality and
 *      noninfringement. Keil extends you a royalty-free right to reproduce
 *      and distribute executable files created using this software for use
 *      on NXP Semiconductors LPC microcontroller devices only. Nothing else 
 *      gives you the right to use this software.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#ifndef __CDCUSER_H__
#define __CDCUSER_H__

#define CDC_SERIAL_PORT_1 0
#define CDC_SERIAL_PORT_2 1
#define CDC_SERIAL_PORT_3 2

/* CDC buffer handling */
extern int CDC_RdOutBuf        (int port, char *buffer, const int *length);
extern int CDC_WrOutBuf        (int port, const char *buffer, int *length);
extern int CDC_OutBufAvailChar (int port, int *availChar);


/* CDC Data In/Out Endpoint Address */
#define CDC_DEP1_IN       0x83
#define CDC_DEP1_OUT      0x03
#define CDC_DEP2_IN	  0x85
#define CDC_DEP2_OUT	  0x05
#define CDC_DEP3_IN	  0x87
#define CDC_DEP3_OUT	  0x07

/* CDC Communication In Endpoint Address */
#define CDC_CEP1_IN       0x81
#define CDC_CEP2_IN	  0x84
#define CDC_CEP3_IN	  0x86

/* CDC Requests Callback Functions */
extern uint32_t CDC_SendEncapsulatedCommand  (void);
extern uint32_t CDC_GetEncapsulatedResponse  (void);
extern uint32_t CDC_SetCommFeature           (unsigned short wFeatureSelector);
extern uint32_t CDC_GetCommFeature           (unsigned short wFeatureSelector);
extern uint32_t CDC_ClearCommFeature         (unsigned short wFeatureSelector);
extern uint32_t CDC_GetLineCoding            (void);
extern uint32_t CDC_SetLineCoding            (void);
extern uint32_t CDC_SetControlLineState      (unsigned short wControlSignalBitmap);
extern uint32_t CDC_SendBreak                (unsigned short wDurationOfBreak);

/* CDC Bulk Callback Functions */
extern void CDC_BulkIn                   (int port);
extern void CDC_BulkOut                  (int port);

/* CDC Notification Callback Function */
extern void CDC_NotificationIn           (int port);

/* CDC Initializtion Function */
extern void CDC_Init (int port);

/* CDC prepare the SERAIAL_STATE */
extern unsigned short CDC_GetSerialState (int port);

/* flow control */
extern unsigned short CDC_DepInEmpty[3];         // DataEndPoint IN empty

#endif  /* __CDCUSER_H__ */

