#!/usr/bin/env python3

import random


def get_rand_list(list_len):
    return [random.randrange(70, 100) for i in range(list_len)]

names = "Raymon Rachel Guido Kyle Kramer Seinfel Superman Clark " \
    "Hero Fowler Genius Kanye Kim".split()

f_name = "combo_students.txt"

with open(f_name, 'w') as f:
    for n in names:
        if random.randint(0, 1):
            #undergrad student
            num_grades = 5
            f.write('U ')
        else:
            #grad student
            num_grades = 6
            f.write('G ')

        grades = [str(random.randint(60, 100)) for i in range(num_grades)]

        f.write('{name} {grades} \n'.format(name = n, 
            grades = ' '.join(grades)))
        

