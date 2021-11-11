.type go, @function
.type even, @function
;====================even function==================
;       c-like signature: int even (int num, int i);
;  registers reports:
;   rdi: num       rsi:  i      rdx:        rcx:        r8:         r9:
;           
;   memory status:
;   ________________________
;   main()
;   go()
;   even() <= we are here
;   ________________________

even:   ;even(int num, int i), num in %rdi, i in %rsi
    sarl %rdi, %rsi
    movl %rsi, %rax
    ret
;_______________________end of even___________________    


;====================go function==================
;       c-like signature: int go (int A[10])
;  registers reports:
;   rdi: pointer to A[0]      rsi:        rdx:        rcx:  num      
;   r8: value of A[i]          r9: copy of value of A[i]       
;   r15: int sum = 0              r14:`int i = 0        
;   memory status:
;   ________________________
;   main()
;   go()     <= we are here
;   ________________________

go: 
;   ______________IN C: int sum = 0, int i = 0
    movl $0x0, %r15
    movl $0x0, %r14
;    _______________IN C : DO{} statement;
    .DO_WHILE:
;       ________getting the A[i] value to r8 and r9.
        leal (%rdi,%rdi,%r14),%r8
        leal (%rdi,%rdi,%r14),%r9
;        _________setting r8 to A[i]%2_________
        sarl $1,%r8
        sall $1,%r8
;       __________comapring r8 and r9- IF STATEMENT___
        cmpl %r8,%r9
        je .if_res
;        __________ELSE STATEMENT_____________
        addl %r15, %r9
        addl $1, %r14
        


;        ________IF-RESULT STATEMENT: CALL EVEN <-with even (A[i], i);
        .if_res:
            movl %r9, %rdi
            movl %r14, %rsi
            call even
            addl %r15, %rax
            addl $1, %r14
  
;       ___________________WHILE (i<10) statement____________
        cmpl(%r14,10)
        jl .DO_WHILE
;       _____________ RETURN SUM_____________________    
    movl %r15,%rax
    ret




