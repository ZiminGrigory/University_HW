import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread("priroda-35.jpg", 0)
dft = cv2.dft(np.float32(img), flags = cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)
magnitude_spectrum = 20*np.log(cv2.magnitude(dft_shift[:, :, 0], dft_shift[:, :, 1]))


rows, cols = img.shape
crow, ccol = rows/2, cols/2
# create a mask first, center square is 1, remaining all zeros
mask = np.zeros((rows, cols, 2), np.uint8)
mask[crow-50:crow+50, ccol-50:ccol+50] = 1
# apply mask and inverse DFT
fshift = dft_shift * mask
f_ishift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_ishift)
img_back = cv2.magnitude(img_back[:, :, 0], img_back[:, :, 1])

img2 =  cv2.GaussianBlur(img, (5, 5), 2, 2)

plt.subplot(2,2,1),plt.imshow(img, cmap = "gray")
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(2,2,2),plt.imshow(img_back, cmap = "gray")
plt.title("Blur IMg DFT = IDFT"), plt.xticks([]), plt.yticks([])
plt.subplot(2,2,4),plt.imshow(img2, cmap = "gray")
plt.title("Blur IMg2 with Gauss"), plt.xticks([]), plt.yticks([])
plt.show()

