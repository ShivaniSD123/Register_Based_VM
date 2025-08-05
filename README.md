# Register_Based_VM
<br>This is register based vm currently having functions 
<br>
MOV- Push elements into register
<br>
ADD- Add elements in the register
<br>
PRN- prints the information that is stored in the given register
<br>
HLT- Exits the program

<br>
Apart from these, the program throws runtime error for the commands that are not specified. And also throws error if user try to access the register that are not in use.
<br> 
<br>
How the commands work-
<br>
MOV, 5, 4 //Moves 4 to Register 5
<br>
ADD, 0, 1, 2 //Adds the information stored in register 1 and 2 and stores in register 0
<br>
PRN, 4 //Prints the data stored in register 4
<br>
HLT //Exits the program