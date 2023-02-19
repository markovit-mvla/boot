entry start 
start: 
	mov ax,#0xb800 ; ax = Immediate video memory address
	mov es,ax      ; Write ax to es, extra segment
	seg es	       ; es goes to video memory
	mov [0],#0x41  ; Move 'A' into first byte of video memory
	seg es         ; es goes to video memory
	mov [1],#0x1f  ; White [0] on blue background in second byte
loop1: jmp loop1       ; Stop execution after display of character
