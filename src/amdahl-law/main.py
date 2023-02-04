from count_lines import count_lines

# the rabin-karp part and roughly half of the main (slave).
parallelizable = count_lines("../headers/rabin_karp.h") + count_lines("../parallel/main.cpp") / 2

# total
total = parallelizable + count_lines("../parallel/main.cpp") / 2 + count_lines("../headers/read_file.h")

P = parallelizable / total
S = 1 - P
print("The percentage of serial code is:", round(S, 2))
print("The percentage of parallel code is:", round(P, 2))

speedup = lambda N, S, P: 1 / (S + P / N)

n_slaves = 3
print('With', n_slaves, 'slave cores, the expected speed-up is:', speedup(n_slaves, S, P))
