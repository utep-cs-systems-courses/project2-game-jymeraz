	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern blinkLimit, color, direction
	.global oncePerSecond
oncePerSecond:
	cmp #8, &blinkLimit
	jnc first
	mov #0, &blinkLimit
	xor #1, &color
	jmp out
first:
	cmp &blinkLimit, #0
	jnc second
	mov #1, &direction
	jmp out
second:
	cmp #1, &direction
	jnc third
	add #1, &blinkLimit
	jmp out
third:
	sub #1, blinkLimit
	jmp out
out:
	pop r0			
	
