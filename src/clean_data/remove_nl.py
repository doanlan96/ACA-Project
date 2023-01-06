with open('../serial/genome_no_new_line.txt', 'a') as out_file, open('../../data/EscherichiaColi/genome.fna','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))

with open('../serial/pat_no_new_line.txt', 'a') as out_file, open('../../data/pat.txt','r') as in_file:
    for line in in_file:
        out_file.write(line.strip('\n'))        