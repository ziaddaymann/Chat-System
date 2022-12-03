# Chat-System
A Chat System that consists of two microcontrollers, two pc, and some communication protocols. It consists of two Tiva C boards. Each has the same state machine. The communication can be from Tiva A to Tiva B or from Tiva B to Tiva A.
The project contains 7 states : Ideal ,Data Collection , Data Transmission , Encryption , Data Receiving , Decryption , and Data Presenting
Ideal: the blue led on and there is nothing to do while i'm waiting for any interrupt
Data Collection : it collect data from pc to tiva from uart module and store it on uart buffer if i clicked on push buttom 2 and the green led will be on
Data Transmission : It transmit the data from tiva to another tiva by can module if i clicked on push buttom 1 or i wrote 200 byte it will transmit 8 bytes 8 bytes bytes every cycle with 100ms and print error message that i'm exceeded 200 byte
Encryption : It encrypt the data transmitting before it transmit by mapping 
Data Receiving : It receive the data 8 bytes by 8 bytes every cycle by 100ms and store it on can buffer
Decryption : It decrypt the message receiving
Data Presenting : it present the data from tiva to pc by uart module 
