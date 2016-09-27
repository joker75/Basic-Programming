#!/usr/bin/env python2
# Bench file reader

import re
from collections import OrderedDict
from BinPy import *

#if re.findall(r'(.*?)\(.*?\)', "OUTPUT(G22gat)"=line) == "OUTPUT":
#   output.append(line)

#for i in range(len(output)):
#   print(output[i])

file = "c17.bench"
with open(file) as f:
    content = f.readlines()

for i in range(len(content)):
    content[i] = content[i].rstrip('\n') # remove \n's
content = filter(None, content) # remove empty strings after removing \n's
#for i in range(len(content)):
#    if content[i] == '':
#            del content[i]
matches = []
first = 0
for i in range(len(content)):
    if content[i][:5] == "INPUT":
        matches.append(i)
first = matches[0]

del content[:first]; first = 0; matches = []

print(content)

for i in range(len(content)):
    if content[i][:6] == "OUTPUT":
                matches.append(i)
first = matches[0]
print_inputs = []
print_inputs.append(content[:first])
print_inputs = print_inputs[0]
print(print_inputs)
print(first)
first = 0

raw = []
for i in range(len(matches)):
    raw.append(re.findall(r'\([^)]*\)', content[matches[i]]))
output_vars = []

for i in range(len(raw)):
    output_vars.append(raw[0][0][1:len(raw[0][0])-1]) # remove beginning and trailing parens from output variable names
del raw;
last = matches[-1] + 1
del content[:last]
new_content = []
for i in range(len(content)):
    new_content.append(re.sub(re.findall("nand", content[i])[0], "NAND", content[i]))
content = new_content # swap content with new_content because strings are immutable in Python
del new_content
vars = ["G1gat", "G2gat", "G3gat", "G6gat", "G7gat", "G10gat", "G11gat", "G16gat", "G19gat", "G22gat", "G23gat"]
taint_vars = []
raw_terms = []
term_dicts = []
all_print_taints = []

for i in range(len(content)):
	raw_terms.append((re.findall(r'\([^)]*\)', content[i]))[0])

#print(raw_terms)

for i in range(len(raw_terms)):
	for j in range(len(raw_terms[i])):
		term_dicts.append([raw_terms[i][1:raw_terms[i].index(", ")], raw_terms[i][raw_terms[i].index(", ") + 2:-1]])
#term_dicts = set(term_dicts)
x = len(term_dicts)
term_dicts.append(term_dicts[0])
term_dicts.append(term_dicts[15])
term_dicts.append(term_dicts[30])
term_dicts.append(term_dicts[45])
term_dicts.append(term_dicts[60])
term_dicts.append(term_dicts[75])
term_dicts.append(term_dicts[90])
del term_dicts[0:x]
print(term_dicts)

print_vars = []
for i in range(len(content)):
	print_vars.append(content[i][:content[i].index(" =")] + "T") # with the + "T" to indicate taint in the file output

# dummy array here for the dummy taints

for i in range(len(vars) - len(output_vars)): # change occurred here
    taint_vars.append(vars[i]) # mark these variables as taint
for i in range(len(vars) - len(output_vars), len(vars)):
    taint_vars.append(vars[i] + "T")
for i in range(len(term_dicts)):
	for j in range(len(term_dicts[0])):
		all_print_taints.append(term_dicts[i][j] + "T")
z = len(all_print_taints)
for i in range(1, len(all_print_taints) - 1, 2):
	all_print_taints.append([all_print_taints[i-1], all_print_taints[i]])
del all_print_taints[:z]
#def initVars(vars):
for i in range(len(vars)):
    exec(vars[i] + str("=1"))
#for i in range(len(taint_vars)):
#    exec(taint_vars[i] + str("=1"))
#initVars(vars)

for i in range(len(content)):
        exec(str(content[i]))

for i in range(len(output_vars)):
    print(eval(output_vars[i])) #output()))

#for i in range(len(taint_vars)):
#	taint_vars[i] = OR(AND(vars[i]))

#for i in range(len(taint_vars)): # print the values of the taint variables
#   print(eval(taint_vars[i]))


#print(G10gat.output())
#print(last)
#print(first)
#print(matches)

#print(list(G10gat.inputs()))
print(taint_vars)
print(output_vars)

for i in range(len(content)):
    print(content[i])
#print(content)
print(G22gat.output())
print(G23gat.output())
#for i in range(len(content)):
#    print(eval(output_vars[i]).output())
#print(output_vars[0].output())
#print(output_vars[1].output())
print(taint_vars)
print(content)
print(print_vars)
print(first)
##### OUTPUT OF FILE#####
print("\n\n\n\n\n\n")
for i in range(len(print_inputs)):
	print("INPUT (" + print_inputs[i] + ")")       # Victor's edit
for i in range(len(output_vars), 0, -1):
	print("OUTPUT(" + taint_vars[-i] + ")")
for i in range(len(print_vars)):
	print(print_vars[i] + " = or(and(" + term_dicts[i][0] + ", "+ all_print_taints[i][1] + "), "	# ABt
											"and(" + term_dicts[i][1] + ", "+ all_print_taints[i][0] + "), "		# BAt
											"and(" + term_dicts[i][1] + ", "+ all_print_taints[i][1] + "))")	# AtBt

dummy = []
for i in range(len(taint_vars)):
    dummy.append(int(re.findall(r'\d+', taint_vars[i])[0]))
print(dummy)
greatest = int(dummy[-1])
available = []
print(greatest)
every = []
for i in range(1, greatest + 1):
    every.append(i)
every = set(every)
dummy = set(dummy)
available = every - dummy
available = list(available)
print(available)
dummy_names = []
for i in range(len(available)):
    dummy_names.append("G" + str(available[i]) + "dt")
print(dummy_names)
