from tkinter import*
import random
import time

def mover_bola(bola, raquete):
	bola['tela'].move(bola['id'], bola['vel_x'], bola['vel_y'])
	pos = bola['tela'].coords(bola['id'])
	if pos[1] <= 0:
		bola['vel_y'] = 3
	if pos[3] >= bola['tela_altura']:
		bola['vidas'] -= 1     #x -= 1  equivale a x = x - 1
		bola['vel_y'] = -3
		if bola['vidas'] == 0:
			bola['deve_terminar'] = True
	if pos[0] <= 0:
		bola['vel_x'] = random.randint(1,3)
	if pos[2] >= bola['tela_largura']:
		bola['vel_x'] = -random.randint(1,3)
	if tocar_raquete(pos, bola, raquete):
		bola['vel_y'] = -3
		bola['vel_x'] = random.randint(-3,3)
	bola['tela'].itemconfigure(bola['config_placar'], text = bola['vidas'])

def tocar_raquete(pos, bola, raquete):
	tocou = False 
	raquete_pos = bola['tela'].coords(raquete['id'])
	if pos[2] >= raquete_pos[0] and pos[0] <= raquete_pos[2]:
		if pos[3] >= raquete_pos[1] and pos[3] <= raquete_pos[3]:
			tocou = True
	return tocou

def ir_direita(evt):
	raquete1['vel_x'] = 2

def ir_esquerda(evt):
	raquete1['vel_x'] = -2

def mover_raquete(raquete):
	raquete['tela'].move(raquete['id'], raquete['vel_x'],0)
	pos = raquete['tela'].coords(raquete['id'])
	if pos[0] <= 0:
		raquete['vel_x'] = 0
	elif pos[2] >= raquete['tela_largura']:
		raquete['vel_x'] = 0

janela = Tk()
janela.title("Game")
janela.resizable(0, 0)
janela.wm_attributes("-topmost", 1)
tela = Canvas(janela, width = 500, height = 400, bd = 0, highlightthickness = 0)
tela.pack()
janela.update()
tupla_vel = (-3, -2, -1, 1, 2, 3)
imagem = PhotoImage(file = 'Piramides.gif') 
tela.create_image(0, 0, anchor=NW, image = imagem)
cor_texto = "green"
tela.create_text(55, 350, text = 'Vidas: ', fill = cor_texto)
tempoInicial = time.time()
tempoDecorrido = None

#bola
bola1 = {}
bola1['tela'] = tela
bola1['id'] = bola1['tela'].create_oval(10, 10, 25, 25, fill = 'yellow')
bola1['tela'].move(bola1['id'], 245, 100)
bola1['vel_x'] = random.choice(tupla_vel)
bola1['vel_y'] = -3
bola1['tela_altura'] = bola1['tela'].winfo_height()
bola1['tela_largura'] = bola1['tela'].winfo_width()
bola1['deve_terminar'] = False
bola1['vidas'] = 10
bola1['config_placar'] = bola1['tela'].create_text(100, 350, fill = cor_texto)

#raquete
raquete1 = {}
raquete1['tela'] = tela
raquete1['id'] = raquete1['tela'].create_rectangle(0, 0, 100, 10, fill = 'red')
raquete1['tela'].move(raquete1['id'], 200, 300)
raquete1['vel_x'] = 0
raquete1['tela_largura'] = raquete1['tela'].winfo_width()
raquete1['tela'].bind_all('<KeyPress-Left>', ir_esquerda)
raquete1['tela'].bind_all('<KeyPress-Right>', ir_direita)

while True:     #loop continuo
        if bola1['deve_terminar'] == False:
                mover_bola(bola1, raquete1)
                mover_raquete(raquete1)
        else:
                if tempoDecorrido == None:
                        tempoDecorrido = time.time() - tempoInicial
                        tela.create_text(250, 150, text = 'Game Over', fill = cor_texto,\
                                         font = ("Times", 40))
                        tela.create_text(250,370,text = 'Voce sobreviveu por ' \
                                         + str(int(tempoDecorrido)) + ' segundos', fill = cor_texto)
        janela.update()
        time.sleep(0.01)
