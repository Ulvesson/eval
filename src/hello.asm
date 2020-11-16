; masm - hello world

extern GetStdHandle     :PROC
extern WriteConsoleA    :PROC

.data
buffer          db  'Hello, World!!', 13, 10
bytesWritten    dq  00h

.code
main PROC
    mov     rcx, 0fffffff5h
    call    GetStdHandle
    mov     rcx, rax
    mov     rdx, offset buffer
    mov     r8, lengthof buffer
    mov     r9, offset bytesWritten
    sub     rsp, 28h
    mov     qword ptr [rsp+20h], 00h
    call    WriteConsoleA
    add     rsp, 28h
ExitProgram:
    xor     eax, eax
    ret
main ENDP
END