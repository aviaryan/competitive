from math import sqrt

a,b = list( map(float, input().split()) )
c,d = list( map(float, input().split()) )

class complex:
	def __init__(self, a, b):
		self.real, self.img = a, b

	def addTo(self, z2):
		zx = z2.real + self.real
		zy = z2.img + self.img
		return complex(zx, zy)

	def minTo(self, z2):
		zx = self.real - z2.real
		zy = self.img - z2.img
		return complex(zx, zy)

	def multTo(self, z2):
		zx = self.real*z2.real - self.img*z2.img
		zy = self.real*z2.img + self.img*z2.real
		return complex(zx, zy)

	def divTo(self, z2):
		zn = self.multTo(complex(z2.real, -1*z2.img))
		zd = z2.real**2 + z2.img**2
		return complex(zn.real / zd, zn.img / zd)

	def printmod(self):
		zmod = sqrt(self.real**2 + self.img**2)
		print('{:.2f}'.format(zmod))
		return 

	def printC(self):
		imgmin = 0
		imgbk = self.img
		if self.img < 0:
			imgmin = 1
			self.img = -1*self.img
		if self.real != 0:
			print('{:.2f}'.format(self.real), end='')
		if self.img != 0:
			if self.real != 0:
				if imgmin:
					print(' -', end=' ')
				else:
					print(' +', end=' ')
				print('{:.2f}'.format(self.img) + 'i', end='')
			else:
				print('{:.2f}'.format(imgbk) + 'i', end='')
		elif self.real == 0:
			print('0.00', end='')
		print()



z1 = complex(a,b)
z2 = complex(c,d)

zadd = z1.addTo(z2)
zadd.printC()

zmin = z1.minTo(z2)
zmin.printC()

zmul = z1.multTo(z2)
zmul.printC()

zdiv = z1.divTo(z2)
zdiv.printC()

z1.printmod()
z2.printmod()