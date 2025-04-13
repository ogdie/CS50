counter_words = 0
counter_sentences = 0
counter_letters = 0

text = input("Text: ")
for i in range(len(text)):
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        counter_letters += 1
    counter_words = counter_words + 1 if text[i] == ' ' else counter_words
    counter_sentences = counter_sentences + 1 if text[i] in ['.', '!', '?'] else counter_sentences
counter_words += 1

L = counter_letters * 100 / counter_words
S = counter_sentences * 100 / counter_words
index = 0.0588 * L - 0.296 * S - 15.8

if (index >= 16):
    print("Grade 16+")
elif (index <= 1):
    print("Before grade 1")
else:
    print(f"Grade {round(index)}")
