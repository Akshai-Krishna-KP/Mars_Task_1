"""Program that take morse as input and return English.
Each word in morse code is made using dot and dash.
There will be a small pause between this to distingush letter and word."""


"""I am considering International Morse code,
   also input morse code as string with space for 1 pause and distinguish letter and 3 for words"""

# made a dict to store the morse code and alphabets
morse_english = {
    ".-": "A", "-...": "B", "-.-.": "C", "-..": "D", ".": "E", "..-.": "F",
    "--.": "G", "....": "H", "..": "I", ".---": "J", "-.-": "K", ".-..": "L",
    "--": "M", "-.": "N", "---": "O", ".--.": "P", "--.-": "Q", ".-.": "R",
    "...": "S", "-": "T", "..-": "U", "...-": "V", ".--": "W", "-..-": "X",
    "-.--": "Y", "--..": "Z", "-----": "0", ".----": "1", "..---": "2", "...--": "3",
    "....-": "4", ".....": "5", "-....": "6", "--...": "7", "---..": "8", "----.": "9"
}

#function to translate into Morse_code to English
def morse_to_english(code):
    #words are seperated by 3 spaces
    words = code.split("   ")
    deco_words = []
    for word in words: #identify each code and interpet 
        #letters are separted by one space
        temp = [morse_english.get(char, "?") for char in word.split()]
        deco_words.append("".join(temp))
    
    #join all decoded words into a single string with space and return
    return " ".join(deco_words)

#MAIN function
if __name__ == "__main__":
    morse_code = ".... . .-.. .-.. ---   -- .- .-. ..."
    print(morse_to_english(morse_code))