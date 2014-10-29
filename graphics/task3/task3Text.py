__author__ = 'home'
import cv2
import numpy as np


def main():
    img = cv2.imread("text.bmp", cv2.CV_LOAD_IMAGE_COLOR)  # Read image file
    img = cv2.GaussianBlur(img, (3, 3), 0)
    img = cv2.Laplacian(img, 0)
    cv2.threshold(img, 70, 255, cv2.THRESH_BINARY, img)
    kernel = np.ones((4, 6), np.uint8)
    img = cv2.dilate(img, kernel, iterations = 1)
    img = cv2.erode(img, kernel, iterations = 1)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    contours, hierarchy = cv2.findContours(gray, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)

    color = (255, 255, 255)
    drawing = np.zeros(img.shape, np.uint8)
    for cnt in contours:
        x, y, w, h = cv2.boundingRect(cnt)
        cv2.rectangle(drawing, (x, y), (x + w, y + h), color)

    drawing = cv2.cvtColor(drawing, cv2.COLOR_RGB2GRAY)
    h, w = img.shape[:2]
    outpImg = np.zeros((h-2, w-2), np.uint8)
    cv2.floodFill(outpImg, drawing, (0, 0), color)

    cv2.threshold(outpImg, 254, 255, cv2.THRESH_BINARY_INV, outpImg)

    cv2.imwrite("outputTask3.jpg", outpImg)
    cv2.namedWindow('Display Window', cv2.WINDOW_NORMAL)        # Create window for display
    cv2.imshow('Display Window', outpImg)         # Show image in the window
    cv2.moveWindow('Display Window', 1, 1)
    print ("size of image: ", img.shape)      # print size of image
    cv2.waitKey(0)                           # Wait for keystroke
    cv2.destroyAllWindows()                  # Destroy all windows

main()
