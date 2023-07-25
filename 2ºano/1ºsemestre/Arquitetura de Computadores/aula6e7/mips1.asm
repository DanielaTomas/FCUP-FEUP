	.data
_msg1:	.asciiz	"The result is "
_msg2:	.asciiz "\n"

	.text
_main:
	li	$s0, 0           # int i = 0
	li	$s2, 0           # int sum = 0

	li	$v0, 5           # int upTo
	syscall

	move $s1, $v0
_loop:
	bge	$s0, $s1, _end
	mul	$t0, $s0, $s0    # i * i
	add	$s2, $s2, $t0    # sum = sum + i * i
	addiu	$s0, $s0, 1      # i = i + 1
	j	_loop
_end:
	li	$v0, 4
	la	$a0, _msg1
	syscall
	li	$v0, 1
	move	$a0, $s2
	syscall
	li	$v0, 4
	la	$a0, _msg2
	syscall
	li	$v0, 10
	syscall
