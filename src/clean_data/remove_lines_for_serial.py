with open('../serial/genome_single_line.txt', 'a') as out_file, open('../../data/EscherichiaColi/genome.fna','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))

with open('../serial/pat_single_line.txt', 'a') as out_file, open('../../data/pat1.txt','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))        