# binary_clock
A [binary clock](https://en.wikipedia.org/wiki/Binary_clock) is just a clock but instead of using arabic numbers (zero to nine) it uses binary numbers represented by lights on or off (ones and zeros).

## Display
It shows 6 columns representing time in HH:MM:SS with 4 lights (LEDs) each so each digit is shown as a 4 bits binary number, being the Least Significant Bit on the top.

## Reading
To read a column first translate the lights on or off as zeros and ones so each column represents 4 zeros or ones. That is a 4 bits [binary number](https://en.wikipedia.org/wiki/Binary_number) where the least significant bit is on the top. So reading top to bottom gives you something like 0101 (5) or 0010 (2) for example.


| Lights | ⭕️</br>⭕️</br>⭕️</br>⭕️ | ⭕️</br>⭕️</br>⭕️</br>🔴 | ⭕️</br>⭕️</br>🔴</br>⭕️ | ⭕️</br>⭕️</br>🔴</br>🔴 | ⭕️</br>🔴</br>⭕️</br>⭕️ | ⭕️</br>🔴</br>⭕️</br>🔴 | ⭕️</br>🔴</br>🔴</br>⭕️ | ⭕️</br>🔴</br>🔴</br>🔴 | 🔴</br>⭕️</br>⭕️</br>⭕️ | 🔴</br>⭕️</br>⭕️</br>🔴 |
|:---    | :----:              | :----:              | :----:              | :----:              | :----:              | :----:              | :----:              | :----:              | :----:              | :----:              |
| Binary | 0000                | 0001                | 0010                | 0011                | 0100                | 0101                | 0110                | 0111                | 1000                | 1001                |
| Arabic | 0                   | 1                   | 2                   | 3                   | 4                   | 5                   | 6                   | 7                   | 8                   | 9                   |
