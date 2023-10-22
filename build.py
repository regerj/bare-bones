import subprocess, argparse

from enum import Enum

class Command(Enum):
    ASSEMBLE = 0
    COMPILE = 1
    LINK = 2
    VERIFY_MULTIBOOT = 3
    CREATE_IMAGE = 4
    RUN_IMAGE = 5

class CommandFactory:
    def __init__(self, commandType):
        if commandType is Command.ASSEMBLE:
            self.commandArray = [{
                "command": "i686-elf-as",
                "file": "boot.s",
                "output": ""
            }]
        elif commandType is Command.COMPILE:
            self.commandArray = [{
                "command": "i686-elf-gcc",
                "component_flag": "-c",
                "file": "",
                "output_flag": "-o",
                "output": "",
                "standard": "-std=gnu99",
                "freestanding": "-ffreestanding",
                "optimization": "-O2",
                "wall": "-Wall",
                "wextra": "-Wextra"
            }]
        elif commandType is Command.LINK:
            self.commandArray = [{
                "command": "i686-elf-gcc",
                "t": "-T",
                ""
            }]

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

def Build():
    output = subprocess.run("i686-elf-as")

def main():
    args = GetArgs()
    
    