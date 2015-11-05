GLOBAL _int0
GLOBAL _int1
GLOBAL _int2
GLOBAL _int3
GLOBAL _int4
GLOBAL _int5
GLOBAL _int6
GLOBAL _int7
GLOBAL _int8
GLOBAL _int9
GLOBAL _inta
GLOBAL _intb
GLOBAL _intc
GLOBAL _intd
GLOBAL _inte
GLOBAL _intf
GLOBAL _int10
GLOBAL _int11
GLOBAL _int12
GLOBAL _int13
GLOBAL _int14
GLOBAL _int15
GLOBAL _int16
GLOBAL _int17
GLOBAL _int18
GLOBAL _int19
GLOBAL _int1a
GLOBAL _int1b
GLOBAL _int1c
GLOBAL _int1d
GLOBAL _int1e
GLOBAL _int1f
GLOBAL _int20
GLOBAL _int21
GLOBAL _int22
GLOBAL _int23
GLOBAL _int24
GLOBAL _int25
GLOBAL _int26
GLOBAL _int27
GLOBAL _int28
GLOBAL _int29
GLOBAL _int2a
GLOBAL _int2b
GLOBAL _int2c
GLOBAL _int2d
GLOBAL _int2e
GLOBAL _int2f
GLOBAL _int30
GLOBAL _int31
GLOBAL _int32
GLOBAL _int33
GLOBAL _int34
GLOBAL _int35
GLOBAL _int36
GLOBAL _int37
GLOBAL _int38
GLOBAL _int39
GLOBAL _int3a
GLOBAL _int3b
GLOBAL _int3c
GLOBAL _int3d
GLOBAL _int3e
GLOBAL _int3f
GLOBAL _int40
GLOBAL _int41
GLOBAL _int42
GLOBAL _int43
GLOBAL _int44
GLOBAL _int45
GLOBAL _int46
GLOBAL _int47
GLOBAL _int48
GLOBAL _int49
GLOBAL _int4a
GLOBAL _int4b
GLOBAL _int4c
GLOBAL _int4d
GLOBAL _int4e
GLOBAL _int4f
GLOBAL _int50
GLOBAL _int51
GLOBAL _int52
GLOBAL _int53
GLOBAL _int54
GLOBAL _int55
GLOBAL _int56
GLOBAL _int57
GLOBAL _int58
GLOBAL _int59
GLOBAL _int5a
GLOBAL _int5b
GLOBAL _int5c
GLOBAL _int5d
GLOBAL _int5e
GLOBAL _int5f
GLOBAL _int60
GLOBAL _int61
GLOBAL _int62
GLOBAL _int63
GLOBAL _int64
GLOBAL _int65
GLOBAL _int66
GLOBAL _int67
GLOBAL _int68
GLOBAL _int69
GLOBAL _int6a
GLOBAL _int6b
GLOBAL _int6c
GLOBAL _int6d
GLOBAL _int6e
GLOBAL _int6f
GLOBAL _int70
GLOBAL _int71
GLOBAL _int72
GLOBAL _int73
GLOBAL _int74
GLOBAL _int75
GLOBAL _int76
GLOBAL _int77
GLOBAL _int78
GLOBAL _int79
GLOBAL _int7a
GLOBAL _int7b
GLOBAL _int7c
GLOBAL _int7d
GLOBAL _int7e
GLOBAL _int7f
GLOBAL _int80
GLOBAL _int81
GLOBAL _int82
GLOBAL _int83
GLOBAL _int84
GLOBAL _int85
GLOBAL _int86
GLOBAL _int87
GLOBAL _int88
GLOBAL _int89
GLOBAL _int8a
GLOBAL _int8b
GLOBAL _int8c
GLOBAL _int8d
GLOBAL _int8e
GLOBAL _int8f
GLOBAL _int90
GLOBAL _int91
GLOBAL _int92
GLOBAL _int93
GLOBAL _int94
GLOBAL _int95
GLOBAL _int96
GLOBAL _int97
GLOBAL _int98
GLOBAL _int99
GLOBAL _int9a
GLOBAL _int9b
GLOBAL _int9c
GLOBAL _int9d
GLOBAL _int9e
GLOBAL _int9f
GLOBAL _inta0
GLOBAL _inta1
GLOBAL _inta2
GLOBAL _inta3
GLOBAL _inta4
GLOBAL _inta5
GLOBAL _inta6
GLOBAL _inta7
GLOBAL _inta8
GLOBAL _inta9
GLOBAL _intaa
GLOBAL _intab
GLOBAL _intac
GLOBAL _intad
GLOBAL _intae
GLOBAL _intaf
GLOBAL _intb0
GLOBAL _intb1
GLOBAL _intb2
GLOBAL _intb3
GLOBAL _intb4
GLOBAL _intb5
GLOBAL _intb6
GLOBAL _intb7
GLOBAL _intb8
GLOBAL _intb9
GLOBAL _intba
GLOBAL _intbb
GLOBAL _intbc
GLOBAL _intbd
GLOBAL _intbe
GLOBAL _intbf
GLOBAL _intc0
GLOBAL _intc1
GLOBAL _intc2
GLOBAL _intc3
GLOBAL _intc4
GLOBAL _intc5
GLOBAL _intc6
GLOBAL _intc7
GLOBAL _intc8
GLOBAL _intc9
GLOBAL _intca
GLOBAL _intcb
GLOBAL _intcc
GLOBAL _intcd
GLOBAL _intce
GLOBAL _intcf
GLOBAL _intd0
GLOBAL _intd1
GLOBAL _intd2
GLOBAL _intd3
GLOBAL _intd4
GLOBAL _intd5
GLOBAL _intd6
GLOBAL _intd7
GLOBAL _intd8
GLOBAL _intd9
GLOBAL _intda
GLOBAL _intdb
GLOBAL _intdc
GLOBAL _intdd
GLOBAL _intde
GLOBAL _intdf
GLOBAL _inte0
GLOBAL _inte1
GLOBAL _inte2
GLOBAL _inte3
GLOBAL _inte4
GLOBAL _inte5
GLOBAL _inte6
GLOBAL _inte7
GLOBAL _inte8
GLOBAL _inte9
GLOBAL _intea
GLOBAL _inteb
GLOBAL _intec
GLOBAL _inted
GLOBAL _intee
GLOBAL _intef
GLOBAL _intf0
GLOBAL _intf1
GLOBAL _intf2
GLOBAL _intf3
GLOBAL _intf4
GLOBAL _intf5
GLOBAL _intf6
GLOBAL _intf7
GLOBAL _intf8
GLOBAL _intf9
GLOBAL _intfa
GLOBAL _intfb
GLOBAL _intfc
GLOBAL _intfd
GLOBAL _intfe
GLOBAL _intff


EXTERN intHandler


%macro intMacro 1
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	mov rdi, %1
	call intHandler
	;int %1

	;EOI
	mov al, 20h
	out 20h, al
	
	;Undo stack frame
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro


_int0:
	intMacro 0x0

_int1:
	intMacro 0x1

_int2:
	intMacro 0x2

_int3:
	intMacro 0x3

_int4:
	intMacro 0x4

_int5:
	intMacro 0x5

_int6:
	intMacro 0x6

_int7:
	intMacro 0x7

_int8:
	intMacro 0x8

_int9:
	intMacro 0x9

_inta:
	intMacro 0xa

_intb:
	intMacro 0xb

_intc:
	intMacro 0xc

_intd:
	intMacro 0xd

_inte:
	intMacro 0xe

_intf:
	intMacro 0xf

_int10:
	intMacro 0x10

_int11:
	intMacro 0x11

_int12:
	intMacro 0x12

_int13:
	intMacro 0x13

_int14:
	intMacro 0x14

_int15:
	intMacro 0x15

_int16:
	intMacro 0x16

_int17:
	intMacro 0x17

_int18:
	intMacro 0x18

_int19:
	intMacro 0x19

_int1a:
	intMacro 0x1a

_int1b:
	intMacro 0x1b

_int1c:
	intMacro 0x1c

_int1d:
	intMacro 0x1d

_int1e:
	intMacro 0x1e

_int1f:
	intMacro 0x1f

_int20:
	intMacro 0x20

_int21:
	intMacro 0x21

_int22:
	intMacro 0x22

_int23:
	intMacro 0x23

_int24:
	intMacro 0x24

_int25:
	intMacro 0x25

_int26:
	intMacro 0x26

_int27:
	intMacro 0x27

_int28:
	intMacro 0x28

_int29:
	intMacro 0x29

_int2a:
	intMacro 0x2a

_int2b:
	intMacro 0x2b

_int2c:
	intMacro 0x2c

_int2d:
	intMacro 0x2d

_int2e:
	intMacro 0x2e

_int2f:
	intMacro 0x2f

_int30:
	intMacro 0x30

_int31:
	intMacro 0x31

_int32:
	intMacro 0x32

_int33:
	intMacro 0x33

_int34:
	intMacro 0x34

_int35:
	intMacro 0x35

_int36:
	intMacro 0x36

_int37:
	intMacro 0x37

_int38:
	intMacro 0x38

_int39:
	intMacro 0x39

_int3a:
	intMacro 0x3a

_int3b:
	intMacro 0x3b

_int3c:
	intMacro 0x3c

_int3d:
	intMacro 0x3d

_int3e:
	intMacro 0x3e

_int3f:
	intMacro 0x3f

_int40:
	intMacro 0x40

_int41:
	intMacro 0x41

_int42:
	intMacro 0x42

_int43:
	intMacro 0x43

_int44:
	intMacro 0x44

_int45:
	intMacro 0x45

_int46:
	intMacro 0x46

_int47:
	intMacro 0x47

_int48:
	intMacro 0x48

_int49:
	intMacro 0x49

_int4a:
	intMacro 0x4a

_int4b:
	intMacro 0x4b

_int4c:
	intMacro 0x4c

_int4d:
	intMacro 0x4d

_int4e:
	intMacro 0x4e

_int4f:
	intMacro 0x4f

_int50:
	intMacro 0x50

_int51:
	intMacro 0x51

_int52:
	intMacro 0x52

_int53:
	intMacro 0x53

_int54:
	intMacro 0x54

_int55:
	intMacro 0x55

_int56:
	intMacro 0x56

_int57:
	intMacro 0x57

_int58:
	intMacro 0x58

_int59:
	intMacro 0x59

_int5a:
	intMacro 0x5a

_int5b:
	intMacro 0x5b

_int5c:
	intMacro 0x5c

_int5d:
	intMacro 0x5d

_int5e:
	intMacro 0x5e

_int5f:
	intMacro 0x5f

_int60:
	intMacro 0x60

_int61:
	intMacro 0x61

_int62:
	intMacro 0x62

_int63:
	intMacro 0x63

_int64:
	intMacro 0x64

_int65:
	intMacro 0x65

_int66:
	intMacro 0x66

_int67:
	intMacro 0x67

_int68:
	intMacro 0x68

_int69:
	intMacro 0x69

_int6a:
	intMacro 0x6a

_int6b:
	intMacro 0x6b

_int6c:
	intMacro 0x6c

_int6d:
	intMacro 0x6d

_int6e:
	intMacro 0x6e

_int6f:
	intMacro 0x6f

_int70:
	intMacro 0x70

_int71:
	intMacro 0x71

_int72:
	intMacro 0x72

_int73:
	intMacro 0x73

_int74:
	intMacro 0x74

_int75:
	intMacro 0x75

_int76:
	intMacro 0x76

_int77:
	intMacro 0x77

_int78:
	intMacro 0x78

_int79:
	intMacro 0x79

_int7a:
	intMacro 0x7a

_int7b:
	intMacro 0x7b

_int7c:
	intMacro 0x7c

_int7d:
	intMacro 0x7d

_int7e:
	intMacro 0x7e

_int7f:
	intMacro 0x7f

_int80:
	intMacro 0x80

_int81:
	intMacro 0x81

_int82:
	intMacro 0x82

_int83:
	intMacro 0x83

_int84:
	intMacro 0x84

_int85:
	intMacro 0x85

_int86:
	intMacro 0x86

_int87:
	intMacro 0x87

_int88:
	intMacro 0x88

_int89:
	intMacro 0x89

_int8a:
	intMacro 0x8a

_int8b:
	intMacro 0x8b

_int8c:
	intMacro 0x8c

_int8d:
	intMacro 0x8d

_int8e:
	intMacro 0x8e

_int8f:
	intMacro 0x8f

_int90:
	intMacro 0x90

_int91:
	intMacro 0x91

_int92:
	intMacro 0x92

_int93:
	intMacro 0x93

_int94:
	intMacro 0x94

_int95:
	intMacro 0x95

_int96:
	intMacro 0x96

_int97:
	intMacro 0x97

_int98:
	intMacro 0x98

_int99:
	intMacro 0x99

_int9a:
	intMacro 0x9a

_int9b:
	intMacro 0x9b

_int9c:
	intMacro 0x9c

_int9d:
	intMacro 0x9d

_int9e:
	intMacro 0x9e

_int9f:
	intMacro 0x9f

_inta0:
	intMacro 0xa0

_inta1:
	intMacro 0xa1

_inta2:
	intMacro 0xa2

_inta3:
	intMacro 0xa3

_inta4:
	intMacro 0xa4

_inta5:
	intMacro 0xa5

_inta6:
	intMacro 0xa6

_inta7:
	intMacro 0xa7

_inta8:
	intMacro 0xa8

_inta9:
	intMacro 0xa9

_intaa:
	intMacro 0xaa

_intab:
	intMacro 0xab

_intac:
	intMacro 0xac

_intad:
	intMacro 0xad

_intae:
	intMacro 0xae

_intaf:
	intMacro 0xaf

_intb0:
	intMacro 0xb0

_intb1:
	intMacro 0xb1

_intb2:
	intMacro 0xb2

_intb3:
	intMacro 0xb3

_intb4:
	intMacro 0xb4

_intb5:
	intMacro 0xb5

_intb6:
	intMacro 0xb6

_intb7:
	intMacro 0xb7

_intb8:
	intMacro 0xb8

_intb9:
	intMacro 0xb9

_intba:
	intMacro 0xba

_intbb:
	intMacro 0xbb

_intbc:
	intMacro 0xbc

_intbd:
	intMacro 0xbd

_intbe:
	intMacro 0xbe

_intbf:
	intMacro 0xbf

_intc0:
	intMacro 0xc0

_intc1:
	intMacro 0xc1

_intc2:
	intMacro 0xc2

_intc3:
	intMacro 0xc3

_intc4:
	intMacro 0xc4

_intc5:
	intMacro 0xc5

_intc6:
	intMacro 0xc6

_intc7:
	intMacro 0xc7

_intc8:
	intMacro 0xc8

_intc9:
	intMacro 0xc9

_intca:
	intMacro 0xca

_intcb:
	intMacro 0xcb

_intcc:
	intMacro 0xcc

_intcd:
	intMacro 0xcd

_intce:
	intMacro 0xce

_intcf:
	intMacro 0xcf

_intd0:
	intMacro 0xd0

_intd1:
	intMacro 0xd1

_intd2:
	intMacro 0xd2

_intd3:
	intMacro 0xd3

_intd4:
	intMacro 0xd4

_intd5:
	intMacro 0xd5

_intd6:
	intMacro 0xd6

_intd7:
	intMacro 0xd7

_intd8:
	intMacro 0xd8

_intd9:
	intMacro 0xd9

_intda:
	intMacro 0xda

_intdb:
	intMacro 0xdb

_intdc:
	intMacro 0xdc

_intdd:
	intMacro 0xdd

_intde:
	intMacro 0xde

_intdf:
	intMacro 0xdf

_inte0:
	intMacro 0xe0

_inte1:
	intMacro 0xe1

_inte2:
	intMacro 0xe2

_inte3:
	intMacro 0xe3

_inte4:
	intMacro 0xe4

_inte5:
	intMacro 0xe5

_inte6:
	intMacro 0xe6

_inte7:
	intMacro 0xe7

_inte8:
	intMacro 0xe8

_inte9:
	intMacro 0xe9

_intea:
	intMacro 0xea

_inteb:
	intMacro 0xeb

_intec:
	intMacro 0xec

_inted:
	intMacro 0xed

_intee:
	intMacro 0xee

_intef:
	intMacro 0xef

_intf0:
	intMacro 0xf0

_intf1:
	intMacro 0xf1

_intf2:
	intMacro 0xf2

_intf3:
	intMacro 0xf3

_intf4:
	intMacro 0xf4

_intf5:
	intMacro 0xf5

_intf6:
	intMacro 0xf6

_intf7:
	intMacro 0xf7

_intf8:
	intMacro 0xf8

_intf9:
	intMacro 0xf9

_intfa:
	intMacro 0xfa

_intfb:
	intMacro 0xfb

_intfc:
	intMacro 0xfc

_intfd:
	intMacro 0xfd

_intfe:
	intMacro 0xfe

_intff:
	intMacro 0xff