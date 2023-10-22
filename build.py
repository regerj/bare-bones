#!/usr/bin/python3

import subprocess, argparse, os, shutil

from enum import StrEnum

class Command(StrEnum):
    BUILD = "build"
    RUN = "run"
    CLEAN = "clean"
    
def Clean():
    try:
        shutil.rmtree("build")
    except:
        pass
    
    try:
        shutil.rmtree("isodir")
    except:
        pass

def Build():
    Clean()
    
    os.mkdir("build")
    
    os.chdir("build")
    output = subprocess.run([
        "cmake",
        ".."
    ])
    
    print(output.stdout)
    
    output = subprocess.run(
        "make"
    )
    
    print(output.stdout)
    
    os.chdir("..")
    
def Run():
    Build()
    
    os.mkdir("isodir")
    os.mkdir("isodir/boot")
    os.mkdir("isodir/boot/grub")
    shutil.copy("./build/bin/timberline", "./isodir/boot")
    shutil.copy("./src/grub.cfg", "./isodir/boot/grub")

def GetArgs():
    parser = argparse.ArgumentParser(
        prog='TimberlineOS utility script',
        description='TimberlineOS utility script for building and running.'
    )
    
    subparsers = parser.add_subparsers(
        dest='command',
        required=True
    )
    
    parser_build = subparsers.add_parser('build')
    parser_build.add_argument(
        '-c',
        '--clean',
        action='store_true'
    )
    
    parser_clean = subparsers.add_parser('clean')
    
    parser_run = subparsers.add_parser('run')
    
    return parser.parse_args()

def main():
    args = GetArgs()
    
    if args.command == Command.BUILD:
        Build()
    elif args.command == Command.RUN:
        Run()
    else:
        print("Invalid command")
        
if __name__ == "__main__":
    main()
    