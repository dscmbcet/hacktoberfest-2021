# Calculator using Python Tkinter
from tkinter import Tk, Entry, Button, StringVar


class Calculator:
    def __init__(self, body):
        body.title("Calculator")
        body.geometry("357x420+0+0")
        body.config(bg='black')
        

        self.eqn = StringVar()
        self.entry_val = ''
        Entry(width=19, bg='#FFFFFF', font=('Arial Bold', 32), textvariable=self.eqn).place(x=1, y=0)


        Button(width = 10, height = 4, text='(', relief='flat', command = lambda:self.display__val('(')).place(x=0, y=50)
        Button(width=10, height=4, text=')', relief='flat',
               command=lambda: self.display__val(')')).place(x=90, y=50)
        Button(width=10, height=4, text='%', relief='flat',
               command=lambda: self.display__val('%')).place(x=180, y=50)
        Button(width=10, height=4, text='1', relief='flat',
               command=lambda: self.display__val(1)).place(x=0, y=125)
        Button(width=10, height=4, text='2', relief='flat',
               command=lambda: self.display__val(2)).place(x=90, y=125)
        Button(width=10, height=4, text='3', relief='flat',
               command=lambda: self.display__val(3)).place(x=180, y=125)
        Button(width=10, height=4, text='4', relief='flat',
               command=lambda: self.display__val(4)).place(x=0, y=200)
        Button(width=10, height=4, text='5', relief='flat',
               command=lambda: self.display__val(5)).place(x=90, y=200)
        Button(width=10, height=4, text='6', relief='flat',
               command=lambda: self.display__val(6)).place(x=180, y=200)
        Button(width=10, height=4, text='7', relief='flat',
               command=lambda: self.display__val(7)).place(x=0, y=275)
        Button(width=10, height=4, text='8', relief='flat',
               command=lambda: self.display__val(8)).place(x=180, y=275)
        Button(width=10, height=4, text='9', relief='flat',
               command=lambda: self.display__val(9)).place(x=90, y=275)
        Button(width=10, height=4, text='0', relief='flat',
               command=lambda: self.display__val(0)).place(x=90, y=350)
        Button(width=10, height=4, text='.', relief='flat',
               command=lambda: self.display__val('.')).place(x=180, y=350)
        Button(width=10, height=4, text='+', relief='flat',
               command=lambda: self.display__val('+')).place(x=270, y=275)
        Button(width=10, height=4, text='-', relief='flat',
               command=lambda: self.display__val('-')).place(x=270, y=200)
        Button(width=10, height=4, text='/', relief='flat',
               command=lambda: self.display__val('/')).place(x=270, y=50)
        Button(width=10, height=4, text='x', relief='flat',
               command=lambda: self.display__val('x')).place(x=270, y=125)
        Button(width=10, height=4, text='=', relief='flat').place(x=270, y=350)
        Button(width=10, height=4, text='C', relief='flat').place(x=0, y=350)
        

    def display__val(self, val):
        self.entry_val += str(val)
        self.eqn.set(self.entry_val)

base = Tk()

calculator__pad = Calculator(base)
base.mainloop()
