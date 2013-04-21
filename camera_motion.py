import cv2
import sys
import numpy as np

path = "earth7.jpg"
im = cv2.imread(path)
cv2.imwrite("earth.png", im)
img2 = cv2.cvtColor(im, cv2.COLOR_RGB2GRAY)
features = cv2.goodFeaturesToTrack(img2, 50, .01, 50)
height = img2.shape[0]
width = img2.shape[1]
ch_height = 0
ch_width = 0
for item in features:
    for x, y in item:
        if x > (width/2):
            ch_width -= 1
        else:
            ch_width += 1
        if y > (height/2):
            ch_height -= 1
        else:
            ch_height += 1
        cv2.circle(img2, (x,y), 10, (255,255,255))
print len(features)
print ch_width, ch_height
cv2.imshow("features", img2)
if ch_width >= len(features)/2:
    print "Move camera Left"
elif -ch_width >= len(features)/2:
    print "Move camera Right"
else:
    print "X-axis OK."
if ch_height >= len(features)/2:
    print "Move camera Up"
elif -ch_height >= len(features)/2:
    print "Move camera Down"
else:
    print "Y-axis OK."
cv2.waitKey(0)
if cv2.waitKey(10) != -1:
    print "stop"
cv2.destroyWindow("features")
