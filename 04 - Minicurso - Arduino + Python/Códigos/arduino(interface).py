__author__ = 'Gabriel Barreto'

from Tkinter import *
import serial

class arduino:
    def __init__(self, pyduino):
        #frame1
        self.frame1 = Frame(pyduino)
        self.frame1['padx'] = 10
        self.frame1['pady'] = 10
        self.frame1.pack()

        #label1
        self.label1 = Label(self.frame1)
        self.label1['text'] = 'LED Verde: '
        self.label1['font'] = ('Calibri','11')
        self.label1['fg'] = 'black'
        self.label1.pack()

        #button1
        self.button1 = Button(self.frame1)
        self.button1['text'] = 'Ligar!'
        self.button1['bg'] = 'green'
        self.button1['fg'] = 'black'
        self.button1.bind("<Button-1>",self.g_led)
        self.button1.pack()

        #frame2
        self.frame2 = Frame(pyduino)
        self.frame2['padx'] = 10
        self.frame2['pady'] = 10
        self.frame2.pack()

        #label2
        self.label2 = Label(self.frame2)
        self.label2['text'] = 'LED Amarelo: '
        self.label2['font'] = ('Calibri','11')
        self.label2['fg'] = 'black'
        self.label2.pack()

        #button2
        self.button2 = Button(self.frame2)
        self.button2['text'] = 'Ligar!'
        self.button2['bg'] = 'yellow'
        self.button2['fg'] = 'black'
        self.button2.bind("<Button-1>",self.y_led)
        self.button2.pack()

        #frame3
        self.frame3 = Frame(pyduino)
        self.frame3['padx'] = 10
        self.frame3['pady'] = 10
        self.frame3.pack()

        #label3
        self.label3 = Label(self.frame3)
        self.label3['text'] = 'LED Vermelho: '
        self.label3['font'] = ('Calibri','11')
        self.label3['fg'] = 'black'
        self.label3.pack()

        #button3
        self.button3 = Button(self.frame3)
        self.button3['text'] = 'Ligar!'
        self.button3['bg'] = 'red'
        self.button3['fg'] = 'black'
        self.button3.bind("<Button-1>",self.r_led)
        self.button3.pack()

        #frame4
        self.frame4 = Frame(pyduino)
        self.frame4['padx'] = 10
        self.frame4['pady'] = 10
        self.frame4.pack()

        #label4
        self.label4 = Label(self.frame4)
        self.label4['text'] = 'LEDs: '
        self.label4['font'] = ('Calibri','11')
        self.label4['fg'] = 'black'
        self.label4.pack()

        #button4
        self.button4 = Button(self.frame4)
        self.button4['text'] = 'Ligar!'
        self.button4['bg'] = 'black'
        self.button4['fg'] = 'white'
        self.button4.bind("<Button-1>",self.off)
        self.button4.pack()

    def off(self, event):
        serial.write('0'.encode())

    def r_led(self, event):
        serial.write('7'.enconde())

    def y_led(self, event):
        serial.write('6'.enconde())

    def g_led(self, event):
        serial.write('5'.enconde())

#serial= serial.Serial('COM5', 9600, timeout=1)

root = Tk()
arduino(root)
root.mainloop()
