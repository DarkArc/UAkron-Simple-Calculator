define i32 @strcmp(i8* %str1, i8* %str2) {
  %1 = alloca i8*, align 8                          ; Allocate space for one char of str1
  %2 = alloca i8*, align 8                          ; Allocate space for one char of str2
  %i = alloca i64, align 8                          ; Allocate space for the count
  %returnVal = alloca i32, align 4                  ; Allocate space for the return value
  store i8* %str1, i8** %1, align 8                 ; Store a ptr to the first char of str1
  store i8* %str2, i8** %2, align 8                 ; Store a ptr to the first char of str2
  store i64 0, i64* %i, align 8                     ; Set count equal to 0
  br label %3                                       ; Start working

; <label>:3
  %4 = load i64, i64* %i, align 8                   ; Load the value of the count register
  %5 = load i8*, i8** %1, align 8                   ; Load the ptr in the char of str1 register
  %6 = getelementptr inbounds i8, i8* %5, i64 %4    ; Fetch the memory address of the src1 register char with count offset
  %7 = load i8, i8* %6, align 1                     ; Load the value
  %8 = sext i8 %7 to i32                            ; Extend the sign to 32-bit
  %9 = load i8*, i8** %2, align 8                  ; Load the ptr in the char of str2 register
  %10 = getelementptr inbounds i8, i8* %9, i64 %4  ; Fetch the memory address of the src2 register char with count offset
  %11 = load i8, i8* %10, align 1                   ; Load the value
  %12 = sext i8 %11 to i32                          ; Extend the sign to 32-bit
  %13 = sub nsw i32 %8, %12                         ; Subtract str1 char from str2 char
  store i32 %13, i32* %returnVal, align 4           ; Store the result in the returnVal register
  %14 = icmp ne i32 %13, 0                          ; See if it equals 0
  br i1 %14, label %30, label %15                   ; If it does continue checks, else go to the end

; <label>:15
  %16 = load i64, i64* %i, align 8                  ; Load the value of the count register
  %17 = load i8*, i8** %1, align 8                  ; Load the ptr in the char of str1 register
  %18 = getelementptr inbounds i8, i8* %17, i64 %16 ; Fetch the memory address of the src1 register char with count offset
  %19 = load i8, i8* %18, align 1                   ; Load the value
  %20 = icmp ne i8 %19, 0                           ; See if it equals 0
  br i1 %20, label %21, label %30                   ; If it does go to the end, otherwise continue checks

; <label>:21
  %22 = load i64, i64* %i, align 8                  ; Load the value of the count register
  %23 = load i8*, i8** %2, align 8                  ; Load the ptr in the char str2 register
  %24 = getelementptr inbounds i8, i8* %23, i64 %22 ; Fetch the memory address of the src2 register char with count offset
  %25 = load i8, i8* %24, align 1                   ; Load the vale
  %26 = icmp ne i8 %25, 0                           ; See if it equals 0
  br i1 %26, label %27, label %30                   ; If it does go to the end, otherwise continue to increment

; <label>:27
  %28 = load i64, i64* %i, align 8                  ; Load the value of the count register
  %29 = add i64 %28, 1                              ; Add one to the count value
  store i64 %29, i64* %i, align 8                   ; Store the new count value back in the count register
  br label %3                                       ; Go to the next character

; <label>:30
  %31 = load i32, i32* %returnVal, align 4          ; Load the value of the returnVal register
  ret i32 %31                                       ; Return it
}
