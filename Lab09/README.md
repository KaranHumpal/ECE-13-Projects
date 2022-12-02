Karan Humpal SOLO
I WROTE:
-AGENT.C
-AGENTTEST.C
-FIELD.C
-FIELDTEST.C

This lab consists of two main modules, Agent and Message. Agent holds a state machine that moves around between the possible states that the game can be in, whether our agent is attacking, defending or waiting, it knows exactly what to do and when to do it. Message goes through a message received or creates a message with a payload, message ID, data fields and checksum that can be used to send information to the opponent or decode information sent to it and take the appropriate action. Agent utilizes the submodules, Field and Negotiation to correctly create the state machine. Field creates the battlefield and can modify and check both our own field and the opponent's field. We also use field to register enemy attacks, place our boats in the beginning, and make our guesses for when we are attacking. Negotiation is used to detect cheating, create a hash, and dictate which agent goes first based on a type of coin flip.

This lab was definetly the hardest of the quarter. I started a little later than I normally due due to my situation at home and not having Lab 8 done yet. I was also not able to find a partner since I started so late, so I decided to do the solo option.

We learned how to use functions like rand() and srand(). We also made use of enumerations and pointers. I learned alot from this lab and was actually able to finish it on time. The Agent file was much more difficult than the field file. 


