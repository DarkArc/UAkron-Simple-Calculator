define i64 @strlen(i8* %str) #0 {
  %1 = alloca i8*, align 8                       ; Allocate space for one char of str
  %i = alloca i64, align 8                       ; Allocate space for the count
  store i8* %str, i8** %1, align 8               ; Store a ptr to the first char of str
  store i64 0, i64* %i, align 8                  ; Set count equal to 0
  br label %logic                                ; Start working

logic:
  %2 = load i64, i64* %i, align 8                ; Load the value in the count register
  %3 = load i8*, i8** %1, align 8                ; Load the ptr in the char of str register
  %4 = getelementptr inbounds i8, i8* %3, i64 %2 ; Fetch the memory address of the str1 char with count offset
  %5 = load i8, i8* %4, align 1                  ; Load the value
  %6 = icmp eq i8 %5, 0                          ; See if it equals 0
  br i1 %6, label %end, label %continuation      ; If they're equal branch to quit

end:
  %7 = load i64, i64* %i, align 8                ; Load the value in the count register
  ret i64 %7                                     ; Return it

continuation:
  %8 = load i64, i64* %i, align 8                ; Load the value in the count register
  %9 = add i64 %8, 1                             ; Add one to the count value
  store i64 %9, i64* %i, align 8                 ; Store the new count value back in the count register
  br label %logic                                ; Return back to the loop
}
