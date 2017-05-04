# code by Sebastian Vazquez-Carson

#!/opt/sphenix/utils/bin/python

import os
import subprocess

for i in range(3801, 3805):
   #print ('Starting iteration for run number ', i)
   h = subprocess.check_output("ddump -p 910 -t 9 JinData/beam/beam_0000%d-0000.prdf | grep 'E:2CH' | awk '{print $3}'" %(i), shell=True)
   h = float(h)
   #print ('Okay I think I have the variable, here it is ', h)
   v = subprocess.check_output("ddump -p 910 -t 9 JinData/beam/beam_0000%d-0000.prdf | grep 'E:2CV' | awk '{print $3}'" %(i), shell=True)
   v = float(v)
   print ('horizontal position is',h,'and vertical posiiton is',v)




   # f = open("MT_Positions.txt","w") #opens file with name of "test.txt"

   # for i in range(750, 999):
   #    horizontal = os.system("ddump -p 910 -t 9 Data/beam/beam_00003801-0%d.prdf | grep 'E:2CH' | awk '{print $3}'" %(i))
   #    vertical = os.system("ddump -p 910 -t 9 Data/beam/beam_00003801-0%d.prdf | grep 'E:2CV' | awk '{print $3}'" %(i)) 
   #    f.write(horizontal ' ' veritcal '\n')
   

   # horizontal = os.system("ddump -p 910 -t 9 Data/beam/beam_00003801-1000.prdf | grep 'E:2CH' | awk '{print $3}'")
   # vertical = os.system("ddump -p 910 -t 9 Data/beam/beam_00003801-1000.prdf | grep 'E:2CV' | awk '{print $3}'")

   # f.write(horizontal ' ' veritcal)
   # f.close()
