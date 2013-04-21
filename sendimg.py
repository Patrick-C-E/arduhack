import os
import time

while(1):
   
    os.system("fswebcam image.jpg")                                                        ## Take image
    os.system("wget http://www.agm.me.uk/arduhack/_putimg.php --post-file=image.jpg")    ## wget image to server
   
    os.system("wget http://www.agm.me.uk/arduhack/_putdara.php --post-file=data.txt")    ## wget data to server
    time.sleep(2)                                                                        ## sleep for 2 secs.

