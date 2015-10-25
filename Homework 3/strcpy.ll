define i8* @strcpy(i8* %dest, i8* %src) {
  %1 = alloca i8*, align 8                           ; Allocate space for the first char dest
  %2 = alloca i8*, align 8                           ; Allocate space for the first char src
  %i = alloca i64, align 4                           ; Allocate space for the count
  store i8* %dest, i8** %1, align 8                  ; Store a ptr to the first char of dest
  store i8* %src, i8** %2, align 8                   ; Store a ptr to the fist char of src
  store i64 0, i64* %i, align 4                      ; Set the count to 0
  br label %3                                        ; Start working

; <label>:3
  %4 = load i64, i64* %i, align 4                    ; Load the value of the count register
  %5 = load i8*, i8** %2, align 8                    ; Load the ptr in the char of src register
  %6 = getelementptr inbounds i8, i8* %5, i64 %4     ; Fetch the memory address of the src register char with count offset
  %7 = load i8, i8* %6, align 1                      ; Load the value
  %8 = sext i8 %7 to i32                             ; Extend the sign to 32-bit
  %9 = icmp ne i32 %8, 0                             ; See if it equals 0
  br i1 %9, label %10, label %18                     ; If it does go to mem cpy, else go to final cpy

; <label>:10
  %11 = load i64, i64* %i, align 8                   ; Load the value of the count register
  %12 = load i8*, i8** %2, align 8                   ; Load the ptr in the char of src register
  %13 = getelementptr inbounds i8, i8* %12, i64 %11  ; Fetch the memory address of the src register char with count offset
  %14 = load i8, i8* %13, align 1                    ; Load the value
  %15 = load i8*, i8** %1, align 8                   ; Load the ptr in the char of dest register
  %16 = getelementptr inbounds i8, i8* %15, i64 %11  ; Fetch the memory address of the dest register char with count offset
  store i8 %14, i8* %16, align 1                     ; Store the value of the src char in the equivalent dest char
  %17 = add i64 %11, 1                               ; Add one to the count value
  store i64 %17, i64* %i, align 8                    ; Store the new count value back in the count register
  br label %3                                        ; Return back to the loop check

; <label>:18
  %19 = load i64, i64* %i, align 8                   ; Load the value of the count register
  %20 = add i64 %19, 1                               ; Add one to the count value
  %21 = load i8*, i8** %2, align 8                   ; Load the ptr in the char of src register
  %22 = getelementptr inbounds i8, i8* %21, i64 %20  ; Fetch the memory address of the src register char with count offset
  %23 = load i8, i8* %22, align 1                    ; Load the value
  %24 = load i8*, i8** %1, align 8                   ; Load the ptr in the char of dest regiter
  %25 = getelementptr inbounds i8, i8* %24, i64 %20  ; Fetch the memory address of the dest register char with count offset
  store i8 %23, i8* %25, align 1                     ; Store the value of the src char in the equivalent dest char
  %26 = load i8*, i8** %1, align 8                   ; Load the ptr in the char of dest register (char of dest begin)
  ret i8* %26                                        ; Return the char of dest register begin
}
