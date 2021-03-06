# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


# Add tests below
test "PINA: 0x10 PINB: 0x10 PINC: 0x10 => PORTD: 0x30"
setPINA 0x10
setPINB 0x10
setPINC 0x10
continue 5
expectPORTD 0x30
checkResult

test "PINA: 0x21 PINB: 0x68 PINC: 0x35 => PORTD: 0xBD"
setPINA 0x21
setPINB 0x68
setPINC 0x35
continue 5
expectPORTD 0xBD
checkResult

test "PINA: 0x60 PINB: 0x25 PINC: 0x0F => PORTD: 0x97"
setPINA 0x60
setPINB 0x25
setPINC 0x0F
continue 5
expectPORTD 0x97
checkResult




# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
