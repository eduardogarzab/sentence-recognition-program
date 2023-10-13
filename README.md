# Sentence Recognition Program

## Overview

This program is designed to process a text file, identify and display valid sentences based on a specific sentence structure. The goal is to recognize and extract valid sentences from a given text, one sentence per line, by using C++ and linear data structures (lists, stacks, and/or queues). The structure of a valid sentence consists of the following parts: article, noun, adjective, verb, and direct object. 

## Functionality

To achieve its goal, the program relies on the following criteria and assumptions:

1. The program reads input text from a file provided as input.
2. It assumes that there are five separate files containing valid articles, nouns, adjectives, verbs, and direct objects, respectively.
3. The words in these files should be in lowercase.
4. Any words containing the character "ñ" should be replaced with "n" in the input files.
5. Accented characters in the input files should be stored without accents.
6. The program considers verbs in their infinitive form to simplify processing. If a different verb form is needed, it must be included in the "verbs.txt" file.
7. A sentence is considered valid only if all its constituent words are found in the respective files provided to the program.
