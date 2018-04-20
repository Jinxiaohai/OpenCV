#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

"""
author : xiaohai
email : xiaohaijin@outlook.com
"""


import os
import sys
import subprocess
import shutil


for (roots, dirs, files) in os.walk(os.getcwd()):
    if(len(dirs) != 0):
        for eachDir in dirs:
            if(eachDir == 'Debug' or eachDir == 'Release'):
                subprocess.call(('git', 'rm', '-r', roots+'/'+eachDir))
