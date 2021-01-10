#!D:\Softs\Python27\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'trac==1.0','console_scripts','tracd'
__requires__ = 'trac==1.0'
import sys
from pkg_resources import load_entry_point

sys.exit(
   load_entry_point('trac==1.0', 'console_scripts', 'tracd')()
)
