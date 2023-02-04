with open('../parallel/genome_human_single_line.txt', 'a') as out_file, open('../../data/GRCh38_Human/GRCh38','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))

with open('../parallel/pattern_human_single_line.txt', 'a') as out_file, open('../../data/patternHuman.txt','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))      