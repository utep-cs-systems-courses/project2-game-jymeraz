	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern blinkLimit
	.extern color
	.extern direction
	.global oncePerSecond
	
oncePerSecond:
	cmp #8, &blinkLimit
	jnc first
	mov #0, &direction
	xor #1, &color
first:
	mov #0, r12
	cmp &blinkLimit, r12
	jnc second
	mov #1, &direction
second:
	cmp #1, &direction
	jne third
	add #1, &blinkLimit
	jmp out
third:
	sub #1, &blinkLimit	
out:
	pop r0			
	
	
