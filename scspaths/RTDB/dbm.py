import pyscs

import socket
import os
import cmd
import traceback

# use
# getChildren
# getAttributes
# read
# write

class DBBrowserCmd(cmd.Cmd,object):
    def __init__(self, db):
      cmd.Cmd.__init__(self)
      self.prompt = ":> "
      self.db = db
      self.currentPoint = ''

    def default(self, line):
        cmd, arg, line = self.parseline(line)
        func = [getattr(self, n) for n in self.get_names() if n.startswith('do_' + cmd)]
        if func: # maybe check if exactly one or more elements, and tell the user
            func[0](arg)
            
    def do_shell(self, s):
      os.system(s)
        
    def help_shell(self):
      print "execute shell commands"
    
    def can_exit(self):
      return True
        
    def do_exit(self, s):
      return True
        
    def help_exit(self):
      print "Exit the interpreter."
      print "You can also use the Ctrl-Z shortcut."
        
    do_EOF = do_exit
    help_EOF= help_exit
    
    def do_ls(self, s):
      c = self.db.getChildren(self.currentPoint)
      print c
      
    def help_ls(self):
      print "List children of current point"
      
    def do_a(self, s):
      c = self.db.getAttributes(self.currentPoint)
      print c
      
    def help_a(self):
      print "List attributes of current point"
      
    def do_r(self, s):
      l = s.split()
      if len(l)!=1:
        print "*** invalid number of arguments", l
        return
      attname = l[0]
      if self.currentPoint == '':
        a = self.currentPoint + '.' + attname
      else:
        a = self.currentPoint + '.' + attname
      
      v = self.db.read(a)
      
      if v != None and a in v:
        type, value = v[a]
        print value
      else:
        print "cannot read ", a
        
    def help_r(self):
      print "Read attribute of current point: r attrName"
    
    def do_w(self, s):
      l = s.split()
      if len(l)!=3:
        print "*** invalid number of arguments", l
        return
      attname = l[0]
      if self.currentPoint == '':
        a = self.currentPoint + '.' + attname
      else:
        a = self.currentPoint + '.' + attname
      vtype = l[1]
      v = l[2]
      
      ds = {}
      if vtype == 'S':
        ds = {a : v}
      elif vtype == 'I':
        ds = {a : int(v)}
      elif vtype == 'F':
        ds = {a : float(v)}
        
      print ds
      self.db.write(ds)

    def help_w(self):
      print "Write attribute of current point: w attrName attValue"
      
    def do_cd(self, s):
      l = s.split()
      if len(l)<1:
        print "*** invalid number of arguments", l
        return
      cname = ' '.join(l)
      if cname == '..' or cname == '^':
        p = self.currentPoint.split(':')
        self.currentPoint = ':'.join(p[0:-1])
      else:
        self.currentPoint = self.currentPoint + ':' + cname
      
      if self.currentPoint == '':
        self.prompt = ":> "
      else:
        self.prompt = self.currentPoint + "> "
      
    def help_cd(self):
      print "Change to children: c childrenName"
      
    def preloop(self):
        print 'Welcome DB browser'
        super(DBBrowserCmd,self).preloop()
        
    def postloop(self):
        print 'Goodbye'
        super(DBBrowserCmd,self).postloop()

        
def run(dbenv, dbname, physenv, srvname):
    pyscs.SCADAsoft_init(physenv,srvname)
    db = pyscs.DbmServer()
    db.connect(dbenv, dbname)

    try:
      interpreter = DBBrowserCmd(db)
      interpreter.cmdloop()
    except:
      traceback.print_exc()
      
    pyscs.SCADAsoft_exit()

if __name__ == "__main__":
  host = socket.gethostname()
  logenv = 'RTDB'
  physenv = "%SCSENV%_" + host
  if 'SCSENV' in os.environ:
    logenv = os.environ['SCSENV']
    physenv = os.environ['SCSENV'] + "_" + host    
  
  run(logenv, 'DbmServer', physenv, 'PyBrowser')