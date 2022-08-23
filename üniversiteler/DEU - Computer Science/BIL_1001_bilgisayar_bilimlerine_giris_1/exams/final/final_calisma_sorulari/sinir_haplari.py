from random import randint

def shuffle(ls):
	new_ls = []
	copy = ls.copy()

	for i in range(len(ls)):
		index = randint(0, len(copy)-1)
		new_ls.append(copy.pop(index))

	return new_ls

matrix = [[]]

for i in range(7):
	matrix.append([])
	for j in range(7):
		matrix[i].append(1 if (i == j) else 0)

for line in shuffle(matrix):
	print(line)
