#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

"""
author : xiaohai
email : xiaohaijin@outlook.com
"""


import subprocess


def main():
    subprocess.call(('make', 'clean'))
    subprocess.call(('xelatex', 'OpenCV.tex'))
    subprocess.call(('bibtex',  'OpenCV.aux'))
    subprocess.call(('xelatex', 'OpenCV.tex'))
    subprocess.call(('xelatex', 'OpenCV.tex'))
    subprocess.call(('evince',  'OpenCV.pdf'))

if __name__ == '__main__':
    main()
