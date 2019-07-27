import json

alphabet = [
'#', '&', '+', '.', '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
]

dico = dict()
for letter in alphabet:
    dico[letter] = 0

filepath = '../words.txt'
with open(filepath) as fp:
    line = fp.readline()
    cnt = 1
    while line:
        word = line.split("\t")[0]
        frequency = int(line.split("\t")[1])
        
        for letter in word:
            dico[letter] += frequency
        
        print("Line {}: {} with frequency: {}".format(cnt, word, frequency))
        line = fp.readline()
        cnt += 1


with open("character_frequency.txt", "w") as f:
    sorted_x = list(map(lambda x: x[0], sorted(dico.items(), key=lambda kv: kv[1])[::-1]))
    f.write(json.dumps(sorted_x))
