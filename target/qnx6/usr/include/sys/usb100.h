/*
 * $QNXLicenseC:  
 * Copyright 2005, QNX Software Systems. All Rights Reserved.
 *
 * This source code may contain confidential information of QNX Software 
 * Systems (QSS) and its licensors.  Any use, reproduction, modification, 
 * disclosure, distribution or transfer of this software, or any software 
 * that includes or is based upon any of this code, is prohibited unless 
 * expressly authorized by QSS by written agreement.  For more information 
 * (including whether this source code file has been published) please
 * email licensing@qnx.com. $
*/

/*
 *  sys/usb100.h
 *

 */

#include <inttypes.h>

#ifndef __USB100_H_INCLUDED
#define __USB100_H_INCLUDED

#define USB_VERSION				0x0110

#define USB_DESC_DEVICE				0x01
#define USB_DESC_CONFIGURATION		0x02
#define USB_DESC_STRING				0x03
#define USB_DESC_INTERFACE			0x04
#define USB_DESC_ENDPOINT			0x05
#define USB_DESC_DEVICE_QUALIFIER	0x06
#define USB_DESC_OTHER_SPEED_CONF	0x07
#define USB_DESC_INTERFACE_POWER	0x08

#define USB_DESC_HID				0x21
#define USB_DESC_REPORT				0x22
#define USB_DESC_PHYSICAL			0x23
#define USB_DESC_HUB				(USB_TYPE_CLASS | USB_CLASS_HUB)

#define USB_CLASS_AUDIO				0x01
#define USB_CLASS_COMM				0x02
#define USB_CLASS_HID				0x03
#define USB_CLASS_PRN				0x07
#define USB_CLASS_UMASS				0x08
#define USB_CLASS_HUB				0x09
#define USB_CLASS_DATA              0x0A

#define USB_COMM_SUBCLASS_ACM       0x02
#define USB_COMM_SUBCLASS_TCM       0x03
#define USB_COMM_SUBCLASS_ECM       0x06
#define USB_COMM_SUBCLASS_DEVMGNT   0x09

#define USB_ENDPOINT_CONTROL		0

#define USB_ENDPOINT_MASK			0x0F
#define USB_ENDPOINT_IN				0x80
#define USB_ENDPOINT_OUT			0x00

#define USB_ATTRIB_CONTROL			0x00
#define USB_ATTRIB_ISOCHRONOUS		0x01
#define USB_ATTRIB_BULK				0x02
#define USB_ATTRIB_INTERRUPT		0x03

#define	USB_GET_STATUS				0
#define	USB_CLEAR_FEATURE			1
#define	USB_SET_FEATURE				3
#define	USB_SET_ADDRESS				5
#define	USB_GET_DESCRIPTOR			6
#define	USB_SET_DESCRIPTOR			7
#define	USB_GET_CONFIGURATION		8
#define	USB_SET_CONFIGURATION		9
#define	USB_GET_INTERFACE			10
#define	USB_SET_INTERFACE			11
#define	USB_SYNCH_FRAME				12

#define USB_FEATURE_EPT_HALT		0
#define USB_FEATURE_DEV_WAKEUP		1

#define USB_RECIPIENT_DEVICE		(0 << 0)
#define USB_RECIPIENT_INTERFACE		(1 << 0)
#define USB_RECIPIENT_ENDPOINT		(2 << 0)
#define USB_RECIPIENT_OTHER			(3 << 0)
#define USB_TYPE_STANDARD			(0 << 5)
#define USB_TYPE_CLASS				(1 << 5)
#define USB_TYPE_VENDOR				(2 << 5)
#define USB_DIRECTION_DEVICE		(0 << 7)
#define USB_DIRECTION_HOST			(1 << 7)

__BEGIN_DECLS

#define USB100_FIELD(_name, _type) _Uint8t	_name[sizeof(_type)];

typedef struct _usb100_generic_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bGeneric,				_Uint8t[1]);
} usb100_generic_descriptor_t;

typedef struct _usb100_device_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bcdUSB,					_Uint16t);
	USB100_FIELD(	bDeviceClass,			_Uint8t);
	USB100_FIELD(	bDeviceSubClass,		_Uint8t);
	USB100_FIELD(	bDeviceProtocol,		_Uint8t);
	USB100_FIELD(	bMaxPacketSize0,		_Uint8t);
	USB100_FIELD(	idVendor,				_Uint16t);
	USB100_FIELD(	idProduct,				_Uint16t);
	USB100_FIELD(	bcdDevice,				_Uint16t);
	USB100_FIELD(	iManufacturer,			_Uint8t);
	USB100_FIELD(	iProduct,				_Uint8t);
	USB100_FIELD(	iSerialNumber,			_Uint8t);
	USB100_FIELD(	bNumConfigurations,		_Uint8t);
} usb100_device_descriptor_t;

typedef struct _usb100_configuration_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	wTotalLength,			_Uint16t);
	USB100_FIELD(	bNumInterfaces,			_Uint8t);
	USB100_FIELD(	bConfigurationValue,	_Uint8t);
	USB100_FIELD(	iConfiguration,			_Uint8t);
	USB100_FIELD(	bmAttributes,			_Uint8t);
	USB100_FIELD(	MaxPower,				_Uint8t);
} usb100_configuration_descriptor_t;

typedef struct _usb100_string_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bString,				_Uint16t[1]);
} usb100_string_descriptor_t;

typedef struct _usb100_interface_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bInterfaceNumber,		_Uint8t);
	USB100_FIELD(	bAlternateSetting,		_Uint8t);
	USB100_FIELD(	bNumEndpoints,			_Uint8t);
	USB100_FIELD(	bInterfaceClass,		_Uint8t);
	USB100_FIELD(	bInterfaceSubClass,		_Uint8t);
	USB100_FIELD(	bInterfaceProtocol,		_Uint8t);
	USB100_FIELD(	iInterface,				_Uint8t);
} usb100_interface_descriptor_t;

typedef struct _usb100_endpoint_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bEndpointAddress,		_Uint8t);
	USB100_FIELD(	bmAttributes,			_Uint8t);
	USB100_FIELD(	wMaxPacketSize,			_Uint16t);
	USB100_FIELD(	bInterval,				_Uint8t);
} usb100_endpoint_descriptor_t;

typedef struct _usb100_audio_endpoint_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bEndpointAddress,		_Uint8t);
	USB100_FIELD(	bmAttributes,			_Uint8t);
	USB100_FIELD(	wMaxPacketSize,			_Uint16t);
	USB100_FIELD(	bInterval,				_Uint8t);
	USB100_FIELD(	bRefresh,				_Uint8t);
	USB100_FIELD(	bSyncAddress,			_Uint8t);
} usb100_audio_endpoint_descriptor_t;

typedef struct _usb100_hid_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bcdHID,					_Uint16t);
	USB100_FIELD(	bCountryCode,			_Uint8t);
	USB100_FIELD(	bNumDescriptors,		_Uint8t);
	USB100_FIELD(	bReportDescriptorType,	_Uint8t);
	USB100_FIELD(	wDescriptorLength,		_Uint16t);
} usb100_hid_descriptor_t;

typedef struct _usb100_hub_descriptor {
	USB100_FIELD(	bLength,				_Uint8t);
	USB100_FIELD(	bDescriptorType,		_Uint8t);
	USB100_FIELD(	bNbrPorts,				_Uint8t);
	USB100_FIELD(	wHubCharacteristics,	_Uint16t);
	USB100_FIELD(	bPwrOn2PwrGood,			_Uint8t);
	USB100_FIELD(	bHubContrCurrent,		_Uint8t);
	USB100_FIELD(	DeviceRemovable,		_Uint8t[1]);
	USB100_FIELD(	PortPwrCtrlMask,		_Uint8t[1]);
} usb100_hub_descriptor_t;

__END_DECLS

#endif



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn/product/branches/6.5.0/trunk/lib/usbdi/public/sys/usb100.h $ $Rev: 710622 $")
#endif
