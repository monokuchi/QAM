
import matplotlib.pyplot as plt
import numpy as np
from scipy import signal as sig

signal = [(-0.000141579,-0.000141579), (-0.000339313,-0.000339313), (-0.000160295,-0.000160295), (0.00066268,0.00066268), (0.00137557,0.00137557), (0.000661762,0.000661762), (-0.00183157,-0.00183157), (-0.0042703,-0.0042703), (-0.00353555,-0.00353555), (0.00214302,0.00214302), (0.0102132,0.0102132), (0.0134424,0.0134424), (0.00403384,0.00403384), (-0.0187092,-0.0187092), (-0.043358,-0.043358), (-0.0503369,-0.0503369), (-0.0257782,-0.0257782), (0.0233861,0.0233861), (0.0654045,0.0654045), (0.0589465,0.0589465), (-0.0170989,-0.0170989), (-0.136831,-0.136831), (-0.226444,-0.226444), (-0.200013,-0.200013), (-0.0191263,-0.0191263), (0.258227,0.258227), (0.474853,0.474853), (0.431187,0.431187), (-0.01987,-0.01987), (-0.887897,-0.887897), (-2.01921,-2.01921), (-3.15053,-3.15053), (-4.01832,-4.01832), (-4.46894,-4.46894), (-4.51295,-4.51295), (-4.29798,-4.29798), (-4.02239,-4.0221), (-3.84043,-3.83975), (-3.80864,-3.80832), (-3.89174,-3.89306), (-4.01128,-4.01431), (-4.09967,-4.10167), (-4.1276,-4.12426), (-4.09857,-4.0887), (-4.03059,-4.02076), (-3.94771,-3.95067), (-3.88426,-3.90834), (-3.88362,-3.91904), (-3.97581,-3.99123), (-4.14035,-4.09932), (-4.28659,-4.17977), (-4.28603,-4.15714), (-4.06065,-3.99771), (-3.67699,-3.7585), (-3.3665,-3.58705), (-3.41917,-3.64894), (-3.98149,-4.01142), (-4.87466,-4.55259), (-5.57533,-4.96389), (-5.42693,-4.86505), (-4.00973,-3.98346), (-1.46824,-2.30435), (1.42301,-0.107144), (3.55192,2.13508), (4.0056,3.93883), (2.57182,4.98431), (-0.0863977,5.20533), (-2.71056,4.77477), (-4.05185,4.02061), (-3.48027,3.31998), (-1.26844,2.9985), (1.60029,3.23699), (3.97842,3.99012), (5.14211,4.94872), (5.09485,5.59559), (4.43987,5.38435), (3.92947,4.00332), (3.97799,1.60513), (4.42486,-1.14723), (4.67051,-3.29853), (4.08407,-4.01763), (2.42458,-3.00965), (0.020747,-0.691329), (-2.39405,1.99592), (-4.08583,4.05563), (-4.71847,4.93512), (-4.5119,4.76727), (-4.06748,4.20996), (-3.96845,3.97881), (-4.39473,4.3574), (-4.98845,4.99147), (-5.06032,5.10616), (-4.02776,4.02694), (-1.83157,1.68681), (0.923016,-1.20549), (3.20648,-3.46774), (4.07047,-4.06523), (3.14151,-2.69938), (0.822243,-0.0207469), (-1.91947,2.66886), (-4.05592,4.06699), (-5.01225,3.5157), (-4.8985,1.29253), (-4.34048,-1.59732), (-4.02862,-3.98853), (-4.26335,-5.15265), (-4.77062,-5.09851), (-4.8896,-4.43654), (-4.01263,-3.9234), (-2.00857,-3.97467), (0.62212,-4.42852), (2.9505,-4.68106), (4.06132,-4.09404), (3.48916,-2.42128), (1.42318,0.00350303), (-1.40579,2.42882), (-4.06681,4.09931), (-5.8066,4.67543), (-6.28217,4.40626), (-5.57173,3.94551), (-4.01553,3.91512), (-2.01066,4.47811), (0.123937,5.19211), (2.16761,5.25691), (3.93607,4.0343), (5.21609,1.53481), (5.764,-1.44261), (5.3841,-3.64851), (4.04618,-4.04344), (1.96679,-2.41352), (-0.411145,0.431892), (-2.55354,3.0308), (-4.03098,4.02676), (-4.68151,2.89865), (-4.65497,0.24687), (-4.31107,-2.53063), (-4.02284,-3.98926), (-3.98745,-3.39325), (-4.14377,-1.06221), (-4.23538,1.85826), (-3.97938,4.03723), (-3.24287,4.63283), (-2.12927,3.63901), (-0.929702,1.76152), (0.0249006,-0.0440953), (0.523321,-1.07667), (0.557905,-1.16569), (0.296968,-0.620366), (-0.0244436,0.0516238), (-0.225573,0.454005), (-0.24719,0.468058), (-0.141795,0.223984), (-0.0103107,-0.0523475), (0.067487,-0.196371), (0.0690674,-0.175889), (0.0220625,-0.0630884), (-0.0285293,0.0439512), (-0.0516622,0.0870877), (-0.0430374,0.0671269), (-0.0180306,0.0209931), (0.004317,-0.0141392), (0.0134424,-0.0233084), (0.0102132,-0.0135557), (0.00214302,-0.000140871), (-0.00353555,0.00656984), (-0.0042703,0.00559566), (-0.00183157,0.00151098), (0.000661762,-0.00134039), (0.00137557,-0.00165873), (0.00066268,-0.00066268), (-0.000160295,0.000160295), (-0.000339313,0.000339313), (-0.000141579,0.000141579)]
signal = np.array([i[0]+1j*i[1] for i in signal])
pilot_signal = [(-4.01847,-4.01847), (-4.46928,-4.46928), (-4.51312,-4.51312), (-4.29732,-4.29732), (-4.02073,-4.02073), (-3.83908,-3.83908), (-3.81015,-3.81015), (-3.89733,-3.89733), (-4.01784,-4.01784), (-4.09952,-4.09952), (-4.11404,-4.11404), (-4.07526,-4.07526), (-4.01673,-4.01673), (-3.96939,-3.96939), (-3.95171,-3.95171), (-3.96939,-3.96939), (-4.01673,-4.01673), (-4.07526,-4.07526), (-4.11404,-4.11404), (-4.09952,-4.09952), (-4.01784,-4.01784), (-3.89733,-3.89733), (-3.81015,-3.81015), (-3.83908,-3.83908), (-4.02073,-4.02073), (-4.29732,-4.29732), (-4.51312,-4.51312), (-4.46928,-4.46928), (-4.01847,-4.01847)]
pilot_signal = np.array([i[0]+1j*i[1] for i in pilot_signal])
correlated_signal = sig.correlate(signal, pilot_signal)
time = np.arange(0, len(pilot_signal))

# print(np.angle(correlated_signal[np.argmax(correlated_signal)]))

#plt.subplot(3, 1, 1)
plt.grid(True)
plt.title("Complex TX Signal")
plt.plot(signal.real)
plt.plot(signal.imag)

#plt.subplot(3, 1, 2)
plt.grid(True)
plt.title("Pilot Signal")
plt.plot(time+32, pilot_signal.real)
plt.plot(time+32, pilot_signal.imag)

#plt.subplot(3, 1, 3)
plt.grid(True)
plt.title("Correlated Signal")
plt.plot(abs(correlated_signal)/100)

plt.show()
