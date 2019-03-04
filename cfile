#!/usr/bin/env python3

import argparse
import pathlib


parser = argparse.ArgumentParser()
parser.add_argument('output', help='output file')
parser.add_argument('-p', '--prologue', help='head string', default='prologue.txt', action='store')

args = parser.parse_args()

output = args.output
prologue = args.prologue

with open(prologue) as fp:
    prologue = fp.read()

file_content = prologue

if pathlib.Path(output).suffix in ('.h', '.hpp'):
    file_content += '''
#ifndef {guard}
#define {guard}

#endif // {guard}
'''.format(guard=output.replace('/', '_').replace('.', '_').upper())

with open(output, 'w') as fp:
    fp.write(file_content)
