import cv2
import numpy as np

out = cv2.VideoWriter('pi.mp4',cv2.VideoWriter_fourcc(*'MJPG'), 60, (400,400))

file = open('solution.txt','r')
sol_line = file.readlines()[0]
file.close()

bg = np.zeros((400,400,3), dtype='uint8')
width, height, _ = bg.shape
for i in range(width):
	for j in range(height):
		bg[i][j] = [int(240), int(30), int(30)]

for i in range(3141):
	c = sol_line[i]
	frame = bg.copy()
	frame = cv2.putText(frame,'%s'%(c),(60,360),cv2.FONT_HERSHEY_SIMPLEX,15,(0,0,0),5,cv2.LINE_AA)
	frame = cv2.putText(frame,'%s'%(c),(60,360),cv2.FONT_HERSHEY_SIMPLEX,15,(255,255,102),3,cv2.LINE_AA)

	cv2.imshow('frame',frame)
	cv2.waitKey(1)

	if i == 0:
		for i in range(25):
			out.write(frame)
	elif i < 10:
		for i in range(20):
			out.write(frame)
	elif i < 20:
		for i in range(15):
			out.write(frame)
	elif i < 30:
		for i in range(10):
			out.write(frame)
	elif i < 40:
		for i in range(8):
			out.write(frame)
	elif i < 50:
		for i in range(5):
			out.write(frame)
	elif i < 100:
		for i in range(3):
			out.write(frame)
	else:
		out.write(frame)
out.release()

cv2.destroyAllWindows()