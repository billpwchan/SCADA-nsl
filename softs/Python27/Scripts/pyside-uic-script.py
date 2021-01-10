#!python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'PySide==1.2.1','console_scripts','pyside-uic'
__requires__ = 'PySide==1.2.1'
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.exit(
        load_entry_point('PySide==1.2.1', 'console_scripts', 'pyside-uic')()
    )
