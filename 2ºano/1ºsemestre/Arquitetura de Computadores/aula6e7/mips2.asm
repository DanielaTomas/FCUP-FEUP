	 .data
_squares:.word 0:100
	 .text
	 
_main:
	 li	$s0, 0           # int i = 0
	 
         li	$v0, 5
	 syscall
	 
	 move   $s1, $v0        # int upTo 
	 
	 la     $s6, _squares   # $s6 = &_squares[0]
_loop:
         bge	$s0, $s1, _end 
         
         sll    $t0, $s0, 2    # i * 4
         add    $t0, $s6, $t0  # i * 4 = &_squares[0] + i * 4
         
         mul  	$t1, $s0, $s0  # i * i
         sw     $t1, 0($t0)    # _squares[i] = i * i
    
	 addiu	$s0, $s0, 1    # i++
	 j	_loop
_end:	
	li	$v0, 10
	syscall
  
