#!/usr/bin/env python3
import subprocess


def main():
    subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])


if __name__ == '__main__':
    main()
