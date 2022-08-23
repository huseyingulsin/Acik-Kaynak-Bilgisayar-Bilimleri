import filecmp
import os
from os import walk

# test dosyalarinin oldugu yer
path = r'C:\Users\onat_\Dropbox\deu\bbg_odev\bbg_odev_tester'

#programin oldugu yer
program_name = 'bbg_odev_2018280038.exe'

# dosyalari ayirmak icin uzanti turleri
question_tag = '_qst.txt'
answer_tag = '_ans.txt'
output_tag = '_out.txt'

os.chdir(path)

for (dirpath, dirnames, filenames) in walk(path):
	for filename in filenames:
		# for every file in [path]

		#filter ones that doesn't contain question_tag
		if filename.find(question_tag) == -1:
			continue

		print(filename)

		root_filename = filename[:len(filename ) - len(question_tag)]

		# get answer to current question
		answer_file = open(path + root_filename + answer_tag, 'r')
		answer_line = ''
		for line in answer_file:
			answer_line = line.strip()
			break



		# get output for the current question
		os.system(program_name + '<' +  filename + '>' + root_filename + output_tag)

		output_file = open(path + root_filename + output_tag, 'r')
		output_line = ''
		for line in output_file:
			output_line = line.strip()
			break

		print(output_line, answer_line)
