loadn   r0,#'O'
loadn   r2,#0
loadn r3,#1000
print_c:
    outchar     r0,r3
    call        wait_time
    dec         r3
    cmp         r3,r2
    jne         print_c


wait_time:
    loadn   r4,#100000
    dec     r4
    cmp     r4,r2
    jne     wait_time

    ret

halt